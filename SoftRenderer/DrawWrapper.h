#pragma once
#include <SDL.h>

class myDraw {
	
	public:
		static SDL_Renderer * renderer;
		static void drawPoint(int x, int y);
		static void drawLine(int x1, int y1, int x2, int y2);
};

