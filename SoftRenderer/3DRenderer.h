#pragma once
#include "Vec3.h"
#include <vector>
#include "LineDrawing.h"
#include "Model.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class Renderer {
	private:
		Vec3 cameraPosition = { 0.0f, 0.0f, 0.0f };
		Vec3 cameraRotation = { 0.0f, 0.0f, 0.0f };

		Vec3 cameraLookAt = { 0.0f, 0.0f, 1.0f };

		Vec3 inverseCosineTheta = { 1.0f, 1.0f, 1.0f };
		Vec3 inverseSineTheta = { 0.0f, 0.0f, 0.0f };

		const float nearPlane = 0.1f;
		Vec3 frustumLeftSide;
		Vec3 frustumRightSide;
		Vec3 frustumTopSide;
		Vec3 frustumBottomSide;

		std::vector<Vec3> vertsToRender;
		std::vector<Vec3> transformedModelVerts;
		std::vector<Vec3> drawList;
		std::vector<Model> modelsToRender;

		bool isInsideFrustum(Vec3 * vertToCheck);
		void frustumCullVerts();
		void rotateWorldToCamera();
		void screenspaceTransformWorld();
		void perspectiveCorrectWorld();
		void drawWorldAsPoints();
		void updateCamera();
		void setFrustum();
		void transformModels();

	public:
		Renderer();
		static Vec3 perspectiveTransform(Vec3 *vertex);
		static Vec3 screenspaceTransform(Vec3 *vertex);
		void setCameraRotation(float xRotationInRadians, float yRotationInRadians, float zRotationInRadians);
		void setCameraRotation(Vec3 * rotationInRadians);
		void addVert(Vec3 * vertToRender);
		void addModel(Model * modelToRender);
		void render();
};