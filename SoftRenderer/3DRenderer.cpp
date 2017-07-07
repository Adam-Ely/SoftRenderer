#include "3DRenderer.h"
#include <algorithm>
#include <math.h>

//private

bool Renderer::isInsideFrustum(const Vec3 & vertToCheck)
{
	bool output = true;

	Vec3 translatedVert = vertToCheck - m_cameraPosition;

	//cull verts behind near plane
	if ((Vec3::dotProduct(translatedVert, m_cameraLookAt)) - m_nearPlane < 0.0f)
	{
		output = false;
	}
	else if (Vec3::dotProduct(translatedVert, m_frustumLeftSide) < 0.0f)
	{
		output = false;
	}
	else if (Vec3::dotProduct(translatedVert, m_frustumRightSide) < 0.0f)
	{
		output = false;
	}
	else if (Vec3::dotProduct(translatedVert, m_frustumTopSide) < 0.0f)
	{
		output = false;
	}
	else if (Vec3::dotProduct(translatedVert, m_frustumBottomSide) < 0.0f)
	{
		output = false;
	}

	return output;
}
void Renderer::frustumCullVerts()
{
	for (auto it = std::begin(m_vertsToRender); it != std::end(m_vertsToRender); ++it)
	{
		if (isInsideFrustum(*it))//address of the Vec3 pointed to by the iterator (would look a lot nicer if I just used a for loop)
		{
			m_drawList.push_back(*it);
		}
	}

	for (auto it = std::begin(m_transformedModelVerts); it != std::end(m_transformedModelVerts); ++it)
	{
		if (isInsideFrustum(*it))
		{
			m_drawList.push_back(*it);
		}
	}
}
void Renderer::rotateWorldToCamera()
{
	for (auto it = std::begin(m_drawList); it != std::end(m_drawList); ++it)
	{
		Vec3::reverseDotRotate(*it, m_inverseSineTheta, m_inverseCosineTheta, m_cameraPosition);
	}
}
void Renderer::screenspaceTransformWorld()
{
	for (auto it = std::begin(m_drawList); it != std::end(m_drawList); ++it)
	{
		*it = screenspaceTransform(*it);
	}
}
void Renderer::perspectiveCorrectWorld()
{
	for (auto it = std::begin(m_drawList); it != std::end(m_drawList); ++it)
	{
		*it = perspectiveTransform(*it);
	}
}
void Renderer::drawWorldAsPoints()
{
	for (auto it = std::begin(m_drawList); it != std::end(m_drawList); ++it)
	{
		drawPoint(*it);
	}
}
void Renderer::setFrustum()
{
	//hacks that assume 90 degree vertical FOV and 3:4 aspect ratio
	float halfHorizontalFOV = atan(4.0f / 3.0f);
	float quarterPi = (float)M_PI / 4.0f;
	float halfPi = (float)M_PI / 2.0f;
	m_frustumLeftSide = { 0.0f, 0.0f, 1.0f };
	m_frustumRightSide = { 0.0f, 0.0f, 1.0f };
	m_frustumTopSide = { 0.0f, 0.0f, 1.0f };
	m_frustumBottomSide = { 0.0f, 0.0f, 1.0f };



	Vec3::rotY(m_frustumLeftSide, - (halfPi - halfHorizontalFOV), m_cameraPosition);
	Vec3::rotY(m_frustumRightSide,  halfPi - halfHorizontalFOV, m_cameraPosition);
	Vec3::rotX(m_frustumTopSide, -quarterPi, m_cameraPosition); //45 degrees, so don't need any special arithmetic
	Vec3::rotX(m_frustumBottomSide, quarterPi, m_cameraPosition);

	Vec3::rot(m_frustumLeftSide, m_cameraRotation.x, m_cameraRotation.y, m_cameraRotation.z, m_cameraPosition);
	Vec3::rot(m_frustumRightSide, m_cameraRotation.x, m_cameraRotation.y, m_cameraRotation.z, m_cameraPosition);
	Vec3::rot(m_frustumTopSide, m_cameraRotation.x, m_cameraRotation.y, m_cameraRotation.z, m_cameraPosition);
	Vec3::rot(m_frustumBottomSide, m_cameraRotation.x, m_cameraRotation.y, m_cameraRotation.z, m_cameraPosition);
}
void Renderer::updateCamera()
{
	//update thetas for each rotation axis
	m_inverseCosineTheta.x = cos(-m_cameraRotation.x);
	m_inverseCosineTheta.y = cos(-m_cameraRotation.y);
	m_inverseCosineTheta.z = cos(-m_cameraRotation.z);

	m_inverseSineTheta.x = sin(-m_cameraRotation.x);
	m_inverseSineTheta.y = sin(-m_cameraRotation.y);
	m_inverseSineTheta.z = sin(-m_cameraRotation.z);

	setFrustum();
}
void Renderer::transformModels()
{
	Vec3 sineTheta, cosineTheta;
	
	for (auto modelIt = std::begin(m_modelsToRender); modelIt != std::end(m_modelsToRender); ++modelIt)//loop through models
	{
		modelIt->m_rotation += modelIt->m_rotationVelocity;
		
		sineTheta.x = sin(modelIt->m_rotation.x);
		sineTheta.y = sin(modelIt->m_rotation.y);
		sineTheta.z = sin(modelIt->m_rotation.z);

		cosineTheta.x = cos(modelIt->m_rotation.x);
		cosineTheta.y = cos(modelIt->m_rotation.y);
		cosineTheta.z = cos(modelIt->m_rotation.z);
		
		for (auto vertIt = std::begin( *(modelIt->getVerts())); //from the model iterator, get pointer to its vertex buffer and create iterator to first element of said buffer
			vertIt != std::end(*(modelIt->getVerts())); //as above, except the ending iterator
			++vertIt)
		{
			Vec3 vert = *vertIt + modelIt->m_position;

			Vec3::dotRotate(vert, sineTheta, cosineTheta, modelIt->m_position);

			m_transformedModelVerts.push_back(vert);
		}
	}
}

//public
Renderer::Renderer()
{
	setFrustum();
}
Vec3 Renderer::perspectiveTransform(const Vec3 &input)
{
	//assumes a camera FOV of 90 degrees
	Vec3 output;

	if (input.z == 0.0f)//this should never happen with near-plane culling
	{
		output = input;
		return output;
	}

output.x = input.x / input.z;
output.y = input.y / input.z;
output.z = input.z;

return output;

////adjustable fov beginnings. Abandoned for now. Need to disable aspect ratio correction in screenspaceTransform to have this
//Vec3 output;

//output.x = input->x / (halfHorizontalFOVTangent * input->z);
//output.y = input->y / (halfVerticalFOVTangent * input->z);
//output.z = input->z;

//return output;
}
Vec3 Renderer::screenspaceTransform(const Vec3 &input)
{
	float safeLength = (float)std::min(SCREEN_WIDTH, SCREEN_HEIGHT) - 1.0f;

	Vec3 output;

	output.x = floor(((float)SCREEN_WIDTH / 2.0f) + (input.x * (safeLength / 2.0f)));
	output.y = floor(((float)SCREEN_HEIGHT / 2.0f) - (input.y * (safeLength / 2.0f)));

	output.z = input.z;

	return output;
}
void Renderer::setCameraRotation(const Vec3 & rotationInRadians)
{
	setCameraRotation(rotationInRadians.x, rotationInRadians.y, rotationInRadians.z);
}
void Renderer::setCameraRotation(float xRotationInRadians, float yRotationInRadians, float zRotationInRadians)
{
	m_cameraRotation = { xRotationInRadians, yRotationInRadians, zRotationInRadians };		//calculate new lookat (rotate neutral unit vector by new angles)
	m_cameraLookAt = { 0.0f, 0.0f, 1.0f };
	Vec3::rot(m_cameraLookAt, m_cameraRotation.x, m_cameraRotation.y, m_cameraRotation.z, m_cameraPosition);

	return;
}
void Renderer::addVert(const Vec3 & vertToRender)
{
	m_vertsToRender.push_back(vertToRender);
	return;
}
void Renderer::addModel(Model & modelToRender)
{
	m_modelsToRender.push_back(modelToRender);
	return;
}

void Renderer::render()
{
	updateCamera();
	transformModels();
	frustumCullVerts();
	m_transformedModelVerts.clear();
	rotateWorldToCamera();
	perspectiveCorrectWorld();
	screenspaceTransformWorld();
	drawWorldAsPoints();
	m_drawList.clear();

	return;
}
