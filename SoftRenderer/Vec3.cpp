#include "Vec3.h"
#include <math.h>

void Vec3::rot(float * first, float * second, float angle)
{
	float sine = sin(angle);
	float cosine = cos(angle);

	float firstAxis = *first;
	float secondAxis = *second;

	*first = (cosine * firstAxis) - (sine * secondAxis);
	*second = (cosine * secondAxis) + (sine * firstAxis);

	return;
}

void Vec3::rot(Vec3 * vertex, float xAngle, float yAngle, float zAngle, Vec3 * origin)
{
	vertex->x -= origin->x;
	vertex->y -= origin->y;
	vertex->z -= origin->z;

	Vec3::rot(&(vertex->z), &(vertex->y), xAngle);
	Vec3::rot(&(vertex->x), &(vertex->z), yAngle);
	Vec3::rot(&(vertex->x), &(vertex->y), zAngle);

	vertex->x += origin->x;
	vertex->y += origin->y;
	vertex->z += origin->z;

	return;
}

void Vec3::rotX(Vec3 * vertex, float angle, Vec3 * origin)
{
	vertex->z -= origin->z;
	vertex->y -= origin->y;
	
	Vec3::rot(&(vertex->z), &(vertex->y), angle);

	vertex->z += origin->z;
	vertex->y += origin->y;

	return;
}

void Vec3::rotY(Vec3 * vertex, float angle, Vec3 * origin)
{
	vertex->x -= origin->x;
	vertex->z -= origin->z;
	
	Vec3::rot(&(vertex->x), &(vertex->z), angle);

	vertex->x += origin->x;
	vertex->z += origin->z;

	return;
}

void Vec3::rotZ(Vec3 * vertex, float angle, Vec3 * origin)
{
	vertex->x -= origin->x;
	vertex->y -= origin->y;
	
	Vec3::rot(&(vertex->x), &(vertex->y), angle);

	vertex->x += origin->x;
	vertex->y += origin->y;

	return;
}

float Vec3::dotProduct(Vec3 * first, Vec3 * second)
{
	return (first->x * second->x) +
		   (first->y * second->y) +
		   (first->z * second->z);
}

void Vec3::dotRotate(Vec3 * vertex, Vec3 * sineAngle, Vec3 * cosineAngle, Vec3 * origin)
{
	
	vertex->x -= origin->x;
	vertex->y -= origin->y;
	vertex->z -= origin->z;

	Vec3 temp = { vertex->x, vertex->y, vertex->z };

	vertex->z = (temp.z * cosineAngle->x) + (temp.y * -sineAngle->x);
	vertex->y = (temp.z * sineAngle->x) + (temp.y * cosineAngle->x);

	temp = { vertex->x, vertex->y, vertex->z };

	vertex->x = (temp.x * cosineAngle->y) + (temp.z * -sineAngle->y);
	vertex->z = (temp.x * sineAngle->y) + (temp.z * cosineAngle->y);

	temp = { vertex->x, vertex->y, vertex->z };

	vertex->x = (temp.x * cosineAngle->z) + (temp.y * -sineAngle->z);
	vertex->y = (temp.x * sineAngle->z) + (temp.y * cosineAngle->z);

	vertex->x = vertex->x + origin->x;
	vertex->y = vertex->y + origin->y;
	vertex->z = vertex->z + origin->z;

	return;
}

void Vec3::reverseDotRotate(Vec3 * vertex, Vec3 * sineAngle, Vec3 * cosineAngle, Vec3 * origin)
{

	vertex->x -= origin->x;
	vertex->y -= origin->y;
	vertex->z -= origin->z;

	Vec3 temp = { vertex->x, vertex->y, vertex->z };

	vertex->x = (temp.x * cosineAngle->z) + (temp.y * -sineAngle->z);
	vertex->y = (temp.x * sineAngle->z) + (temp.y * cosineAngle->z);

	temp = { vertex->x, vertex->y, vertex->z };

	vertex->x = (temp.x * cosineAngle->y) + (temp.z * -sineAngle->y);
	vertex->z = (temp.x * sineAngle->y) + (temp.z * cosineAngle->y);

	temp = { vertex->x, vertex->y, vertex->z };

	vertex->z = (temp.z * cosineAngle->x) + (temp.y * -sineAngle->x);
	vertex->y = (temp.z * sineAngle->x) + (temp.y * cosineAngle->x);

	vertex->x = vertex->x + origin->x;
	vertex->y = vertex->y + origin->y;
	vertex->z = vertex->z + origin->z;

	return;
}