#pragma once

class Vec3 {

	public:
		float x;
		float y;
		float z;

		static void rot(Vec3 &vertex, float xAngle, float yAngle, float zAngle, const Vec3 &origin);
		static void rotX(Vec3 &vertex, float angle, const Vec3 &origin);
		static void rotY(Vec3 &vertex, float angle, const Vec3 &origin);
		static void rotZ(Vec3 &vertex, float angle, const Vec3 &origin);
		static float dotProduct(const Vec3 &first, const Vec3 &second);
		static void dotRotate(Vec3 &vertex, const Vec3 &sineAngle, const Vec3 &cosineAngle, const Vec3 &origin);
		static void reverseDotRotate(Vec3 &vertex, const Vec3 &sineAngle, const Vec3 &cosineAngle, const Vec3 &origin);

	private:
		static void rot(float * first, float * second, float angle);
};

