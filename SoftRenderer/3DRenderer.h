#pragma once
#include "Vec3.h"
#include <vector>
#include "LineDrawing.h"
#include "Model.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

class Renderer {
	private:
		Vec3 m_cameraPosition = { 0.0f, 0.0f, 0.0f };
		Vec3 m_cameraRotation = { 0.0f, 0.0f, 0.0f };

		Vec3 m_cameraLookAt = { 0.0f, 0.0f, 1.0f };

		Vec3 m_inverseCosineTheta = { 1.0f, 1.0f, 1.0f };
		Vec3 m_inverseSineTheta = { 0.0f, 0.0f, 0.0f };

		const float m_nearPlane = 0.1f;
		Vec3 m_frustumLeftSide;
		Vec3 m_frustumRightSide;
		Vec3 m_frustumTopSide;
		Vec3 m_frustumBottomSide;

		std::vector<Vec3> m_vertsToRender;
		std::vector<Vec3> m_transformedModelVerts;
		std::vector<Vec3> m_drawList;
		std::vector<Model> m_modelsToRender;

		bool isInsideFrustum(const Vec3 &vertToCheck);
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
		static Vec3 perspectiveTransform(const Vec3 &vertex);
		static Vec3 screenspaceTransform(const Vec3 &vertex);
		void setCameraRotation(float xRotationInRadians, float yRotationInRadians, float zRotationInRadians);
		void setCameraRotation(const Vec3 & rotationInRadians);
		void addVert(const Vec3 & vertToRender);
		void addModel(Model & modelToRender);
		void render();
};