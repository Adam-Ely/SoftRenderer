#pragma once


class Vec3 {

	public:
		float x;
		float y;
		float z;

		static void rot(Vec3 * vertex, float xAngle, float yAngle, float zAngle, Vec3 * origin);
		static void rotX(Vec3 * vertex, float angle, Vec3 * origin);
		static void rotY(Vec3 * vertex, float angle, Vec3 * origin);
		static void rotZ(Vec3 * vertex, float angle, Vec3 * origin);
		static float dotProduct(Vec3 * first, Vec3 * second);

	private:
		static void rot(float * first, float * second, float angle);
};

