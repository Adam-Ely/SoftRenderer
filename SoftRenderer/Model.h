#pragma once

#include <vector>
#include "Vec3.h"

class Model
{
public:
	Vec3 m_position;
	Vec3 m_rotation;
	Vec3 m_rotationVelocity;
	std::vector<Vec3>* getVerts();
	std::vector<Vec3>* vertices;
};

