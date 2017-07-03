#pragma once

#include <vector>
#include "Vec3.h"

class Model
{
public:
	Vec3 position;
	Vec3 rotation;
	Vec3 rotationVelocity;
	std::vector<Vec3>* getVerts();
	std::vector<Vec3>* vertices;
};

