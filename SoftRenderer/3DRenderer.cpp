#include "3DRenderer.h"
#include <algorithm>
#include <math.h>

//private

bool Renderer::isInsideFrustum(Vec3 * vertToCheck)
{
	bool output = true;

	Vec3 translatedVert;
	translatedVert.x = vertToCheck->x - cameraPosition.x;
	translatedVert.y = vertToCheck->y - cameraPosition.y;
	translatedVert.z = vertToCheck->z - cameraPosition.z;

	//cull verts behind near plane
	if ((Vec3::dotProduct(&translatedVert, &cameraLookAt)) - nearPlane < 0.0f)
	{
		output = false;
	}
	else if (Vec3::dotProduct(&translatedVert, &frustumLeftSide) < 0.0f)
	{
		output = false;
	}
	else if (Vec3::dotProduct(&translatedVert, &frustumRightSide) < 0.0f)
	{
		output = false;
	}
	else if (Vec3::dotProduct(&translatedVert, &frustumTopSide) < 0.0f)
	{
		output = false;
	}
	else if (Vec3::dotProduct(&translatedVert, &frustumBottomSide) < 0.0f)
	{
		output = false;
	}

	return output;
}
void Renderer::frustumCullVerts()
{
	for (auto it = std::begin(vertsToRender); it != std::end(vertsToRender); ++it)
	{
		if (isInsideFrustum(&(*it)))//address of the Vec3 pointed to by the pointer (would look a lot nicer if I just used a for loop)
		{
			drawList.push_back(*it);
		}
	}
}
void Renderer::rotateWorldToCamera()
{
	for (auto it = std::begin(drawList); it != std::end(drawList); ++it)
	{
		Vec3::dotRotate(&(*it), &sineTheta, &cosineTheta, &cameraPosition);
	}
}
void Renderer::screenspaceTransformWorld()
{
	for (auto it = std::begin(drawList); it != std::end(drawList); ++it)
	{
		*it = screenspaceTransform(&(*it));
	}
}
void Renderer::perspectiveCorrectWorld()
{
	for (auto it = std::begin(drawList); it != std::end(drawList); ++it)
	{
		*it = perspectiveTransform(&(*it));
	}
}
void Renderer::drawWorldAsPoints()
{
	for (auto it = std::begin(drawList); it != std::end(drawList); ++it)
	{
		drawPoint(&(*it));
	}
}
void Renderer::setFrustum()
{
	//hacks that assume 90 degree vertical FOV and 3:4 aspect ratio
	float halfHorizontalFOV = atan(4.0f / 3.0f);
	float quarterPi = (float)M_PI / 4.0f;
	float halfPi = (float)M_PI / 2.0f;
	frustumLeftSide = { 0.0f, 0.0f, 1.0f };
	frustumRightSide = { 0.0f, 0.0f, 1.0f };;
	frustumTopSide = { 0.0f, 0.0f, 1.0f };;
	frustumBottomSide = { 0.0f, 0.0f, 1.0f };;



	Vec3::rotY(&frustumLeftSide, - (halfPi - halfHorizontalFOV), &cameraPosition);
	Vec3::rotY(&frustumRightSide,  halfPi - halfHorizontalFOV, &cameraPosition);
	Vec3::rotX(&frustumTopSide, quarterPi, &cameraPosition);
	Vec3::rotX(&frustumBottomSide, -quarterPi, &cameraPosition);

	Vec3::rot(&frustumLeftSide, cameraRotation.x, cameraRotation.y, cameraRotation.z, &cameraPosition);
	Vec3::rot(&frustumRightSide, cameraRotation.x, cameraRotation.y, cameraRotation.z, &cameraPosition);
	Vec3::rot(&frustumTopSide, cameraRotation.x, cameraRotation.y, cameraRotation.z, &cameraPosition);
	Vec3::rot(&frustumBottomSide, cameraRotation.x, cameraRotation.y, cameraRotation.z, &cameraPosition);
}
void Renderer::updateCamera()
{
	//update thetas for each rotation axis
	cosineTheta.x = cos(cameraRotation.x);
	cosineTheta.y = cos(cameraRotation.y);
	cosineTheta.z = cos(cameraRotation.z);

	sineTheta.x = sin(cameraRotation.x);
	sineTheta.y = sin(cameraRotation.y);
	sineTheta.z = sin(cameraRotation.z);

	setFrustum();
}

//public
Renderer::Renderer()
{
	setFrustum();
}
Vec3 Renderer::perspectiveTransform(Vec3 *input)
{
	//assumes a camera FOV of 90 degrees
	Vec3 output;

	if (input->z == 0.0f)//this should never happen with near-plane culling
	{
		output.x = input->x;
		output.y = input->y;
		output.z = input->z;

		return output;
	}

output.x = input->x / input->z;
output.y = input->y / input->z;
output.z = input->z;

return output;

////adjustable fov beginnings. Abandoned for now. Need to disable aspect ratio correction in screenspaceTransform to have this
//Vec3 output;

//output.x = input->x / (halfHorizontalFOVTangent * input->z);
//output.y = input->y / (halfVerticalFOVTangent * input->z);
//output.z = input->z;

//return output;
}
Vec3 Renderer::screenspaceTransform(Vec3 *input)
{
	float safeLength = (float)std::min(SCREEN_WIDTH, SCREEN_HEIGHT) - 1.0f;

	Vec3 output;

	output.x = ((float)SCREEN_WIDTH / 2.0f) + (input->x * (safeLength / 2.0f));
	output.y = ((float)SCREEN_HEIGHT / 2.0f) + (input->y * (safeLength / 2.0f));

	output.z = input->z;

	return output;
}
void Renderer::setCameraRotation(Vec3 * rotationInRadians)
{
	setCameraRotation(rotationInRadians->x, rotationInRadians->y, rotationInRadians->z);
}
void Renderer::setCameraRotation(float xRotationInRadians, float yRotationInRadians, float zRotationInRadians)
{
	cameraRotation.x = xRotationInRadians;
	cameraRotation.y = yRotationInRadians;
	cameraRotation.z = zRotationInRadians;

	//calculate new lookat (rotate neutral unit vector by new angles)

	cameraLookAt = { 0.0f, 0.0f, 1.0f };
	Vec3::rot(&cameraLookAt, cameraRotation.x, cameraRotation.y, cameraRotation.z, &cameraPosition);

	return;
}
void Renderer::addVert(Vec3 * vertToRender)
{
	Vec3 newVert = { vertToRender->x, vertToRender->y, vertToRender->z };

	vertsToRender.push_back(newVert);
	return;
}
void Renderer::render()
{
	updateCamera();
	frustumCullVerts();
	rotateWorldToCamera();
	perspectiveCorrectWorld();
	screenspaceTransformWorld();
	
	drawWorldAsPoints();
	drawList.clear();

	return;
}
