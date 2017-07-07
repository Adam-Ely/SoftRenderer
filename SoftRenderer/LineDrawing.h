#pragma once
#include "Vec3.h"
#include "DrawWrapper.h"

void drawPoint(int x, int y);
void drawPoint(Vec3 & point);
void drawLine(int x1, int y1, int x2, int y2);
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3);
void drawTriangle(Vec3 *first, Vec3 *second, Vec3 *third);
