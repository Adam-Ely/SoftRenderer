#pragma once
#include "Vec3.h"

extern const int SCREEN_WIDTH;
extern const int SCREEN_HEIGHT;

Vec3 perspectiveTransform(Vec3 *vertex);
Vec3 screenspaceTransform(Vec3 *vertex);