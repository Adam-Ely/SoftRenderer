#pragma once
#include "Vec3.h"
#include <vector>
#include "LineDrawing.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;



class Renderer {
	private:
		Vec3 cameraPosition = { 0.0f, 0.0f, 0.0f };
		Vec3 cameraRotation = { 0.0f, 0.0f, 0.0f };

		Vec3 cameraLookAt = { 0.0f, 0.0f, 1.0f };
		/*Vec3 cameraHorizontalPerpendicular = { 0.0f, 0.0f, 1.0f };
		Vec3 cameraVerticalPerpendicular = { 0.0f, 1.0f, 0.0f };*/

		Vec3 cosineTheta = { 1.0f, 1.0f, 1.0f };
		Vec3 sineTheta = { 0.0f, 0.0f, 0.0f };

		const float nearPlane = 0.1f;
		Vec3 frustumLeftSide;
		Vec3 frustumRightSide;
		Vec3 frustumTopSide;
		Vec3 frustumBottomSide;

		//float horizontalFOVInRadians; //still need this stuff? sticking to 90 degree FOV?
		//float verticalFOVInRadians;
		//float halfHorizontalFOVTangent; //calculated in constructor and change of FOV
		//float halfVerticalFOVTangent; 

		std::vector<Vec3> vertsToRender;// = std::vector<Vec3>(100);
		std::vector<Vec3> drawList;// = std::vector<Vec3*>(100);

		bool isInsideFrustum(Vec3 * vertToCheck);
		void frustumCullVerts();
		void rotateWorldToCamera();
		void screenspaceTransformWorld();
		void perspectiveCorrectWorld();
		void drawWorldAsPoints();
		void updateCamera();
		void setFrustum();

	public:
		Renderer();
		static Vec3 perspectiveTransform(Vec3 *vertex);
		static Vec3 screenspaceTransform(Vec3 *vertex);
		void setCameraRotation(float xRotationInRadians, float yRotationInRadians, float zRotationInRadians);
		void setCameraRotation(Vec3 * rotationInRadians);
		void addVert(Vec3 * vertToRender);
		void render();
};