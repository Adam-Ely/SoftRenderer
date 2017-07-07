#include "LineDrawing.h"
#include <algorithm>
#include "DrawWrapper.h"

void drawPoint(int x, int y)
{
	myDraw::drawPoint(x, y);
	return;
}
void drawPoint(Vec3 &point)
{
	myDraw::drawPoint((int)round(point.x), (int)round(point.y));
	return;
}
void drawLine(int x1, int y1, int x2, int y2)
{	
	int deltaX = x2 - x1;
	int deltaY = y2 - y1;

	int iX; //increment rate/direction
	int iY;

	int accumulator = 0;

	if (deltaX >= 0) 
	{ iX = 1; }
	else if (deltaX < 0)
	{ iX = -1; }
	if (deltaY >= 0)
	{ iY = 1; }
	else if (deltaY < 0)
	{ iY = -1; }

	int absDeltaX = abs(deltaX);
	int absDeltaY = abs(deltaY);

	if (absDeltaX > absDeltaY)
	{
		int y = 0;
		for (int x = 0; x < absDeltaX; x++) //how many iterations
		{
			if (accumulator - absDeltaX >= 0)
			{
				y++;
				accumulator -= absDeltaX;
			}
			accumulator += absDeltaY;
			myDraw::drawPoint(x1 + (x*iX), y1 + (y*iY));
		}
	}
	else
	{
		int x = 0;
		for (int y = 0; y < absDeltaY; y++)
		{
			if (accumulator - absDeltaY >= 0)
			{
				x++;
				accumulator -= absDeltaY;
			}
			accumulator += absDeltaX;
			myDraw::drawPoint(x1 + (x* iX), y1 + (y * iY));
		}
	}
}
void drawTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
	myDraw::drawLine(x1, y1, x2, y2);
	myDraw::drawLine(x2, y2, x3, y3);
	myDraw::drawLine(x3, y3, x1, y1);
}
void drawTriangle(Vec3 *first, Vec3 *second, Vec3 *third)
{
	drawTriangle((int)round(first->x), (int)round(first->y),
		(int)round(second->x), (int)round(second->y),
		(int)round(third->x), (int)round(third->y));
}