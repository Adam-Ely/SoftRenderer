#include "DrawWrapper.h"
#include "LineDrawing.h"

SDL_Renderer* myDraw::renderer = NULL;

void myDraw::drawPoint(int x, int y)
{
	SDL_RenderDrawPoint(renderer, x, y);
}

void myDraw::drawLine(int x1, int y1, int x2, int y2)
{
	SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
}
