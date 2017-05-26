/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#pragma once
#include <SDL.h>
#include <stdio.h>
#include "LineDrawing.h"
#include "DrawWrapper.h"
#include "Vec3.h"
#include <float.h>
#include "3DRenderer.h"

//Screen dimension constants
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;

//Starts up SDL and creates window
bool init();

//Frees media and shuts down SDL
void close();

//The window we'll be rendering to
SDL_Window* gWindow = NULL;
	
//The surface contained by the window
//SDL_Surface* gScreenSurface = NULL;

SDL_Renderer* gRenderer = NULL;

////////TRIANGLE
Vec3 left = { -1.0f, 0.57733f, 2.0f };
Vec3 right = { 1.0f, 0.57733f, 2.0f };
Vec3 top = { 0.0f, -1.15467f, 2.0f };

Vec3 origin = { 0.0f, 0.0f, 2.0f };

Vec3 rotatedLeft;
Vec3 rotatedRight;
Vec3 rotatedTop;

/////////TRIANGLE Y ROTATION AXIS
Vec3 axisTop = {0.0f, -1.5f, 2.0f};
Vec3 axisBottom = {0.0f, 0.85f, 2.0f};

/////////CUBE
//Vec3 sqTL = { -1.0f, 1.0f, 2.0f };
//Vec3 sqTR = { 1.0f, 1.0f, 2.0f };
//Vec3 sqBL = { -1.0f, -1.0f, 2.0f };
//Vec3 sqBR = { 1.0f, -1.0f, 2.0f };
//Vec3 cubeTL = { -1.0f, 1.0f, 4.0f };
//Vec3 cubeTR = { 1.0f, 1.0f, 4.0f };
//Vec3 cubeBL = { -1.0f, -1.0f, 4.0f };
//Vec3 cubeBR = { 1.0f, -1.0f, 4.0f };
//
//Vec3 cubeOrigin = { 0.0f, 0.0f, 3.0f };

//Vec3 rCubeFTL; // = sqTL;
//Vec3 rCubeFTR; // = sqTR;
//Vec3 rCubeFBL; // = sqBL;
//Vec3 rCubeFBR; // = sqBR;
//Vec3 rCubeBTL; // = cubeTL;
//Vec3 rCubeBTR; // = cubeTR;
//Vec3 rCubeBBL; // = cubeBL;
//Vec3 rCubeBBR; // = cubeBR;


bool init()
{	
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
		success = false;
	}
	else
	{
		//Create window
		gWindow = SDL_CreateWindow( "Software Renderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( gWindow == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
			success = false;
		}
	}

	SDL_SetHint(SDL_HINT_VIDEO_HIGHDPI_DISABLED, "1");

	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	if (gRenderer == NULL)
	{
		printf("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		success = false;
	}

	myDraw::renderer = gRenderer;
	return success;
}

void close()
{

	//Destroy window
	SDL_DestroyWindow( gWindow );
	gWindow = NULL;

	//Quit SDL subsystems
	SDL_Quit();
}

int main( int argc, char* args[] )
{
	//Start up SDL and create window
	if( !init() )
	{
		printf( "Failed to initialize!\n" );
	}
	else
	{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			float angle = 0.0f;

			//While application is running
			while( !quit )
			{
				//Handle events on queue
				while( SDL_PollEvent( &e ) != 0 )
				{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						quit = true;
					}
				}

				//Draw
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(gRenderer);
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);


				////////TRIANGLE//////////
				rotatedLeft = left;
				rotatedRight = right;
				rotatedTop = top;

				Vec3::rot(&rotatedLeft, 0.0f, angle, 0.0f, &origin);
				Vec3::rot(&rotatedRight, 0.0f, angle, 0.0f, &origin);
				Vec3::rot(&rotatedTop, 0.0f, angle, 0.0f, &origin);

				/*Vec3::rot(&rotatedLeft, angle, angle, angle, &origin);
				Vec3::rot(&rotatedRight, angle, angle, angle, &origin);
				Vec3::rot(&rotatedTop, angle, angle, angle, &origin);*/			

				Vec3 renderLeft =	perspectiveTransform(&rotatedLeft);
				Vec3 renderRight =	perspectiveTransform(&rotatedRight);
				Vec3 renderTop =	perspectiveTransform(&rotatedTop);

				renderLeft = screenspaceTransform(&renderLeft);
				renderRight = screenspaceTransform(&renderRight);
				renderTop = screenspaceTransform(&renderTop);

				drawTriangle(&renderLeft, &renderRight, &renderTop);

				///////Y-AXIS//////////

				Vec3 renderAxisTop = perspectiveTransform(&axisTop);
				Vec3 renderAxisBottom = perspectiveTransform(&axisBottom);
				renderAxisTop = screenspaceTransform(&renderAxisTop);
				renderAxisBottom = screenspaceTransform(&renderAxisBottom);

				drawLine((int)renderAxisTop.x, (int)renderAxisTop.y, (int)renderAxisBottom.x, (int)renderAxisBottom.y);

				//////////CUBE////////////
				/*rCubeFTL = sqTL;
				rCubeFTR = sqTR;
				rCubeFBL = sqBL;
				rCubeFBR = sqBR;
				rCubeBTL = cubeTL;
				rCubeBTR = cubeTR;
				rCubeBBL = cubeBL;
				rCubeBBR = cubeBR;

				Vec3::rot(&rCubeFTL, angle, angle, 0.0f, &cubeOrigin);
				Vec3::rot(&rCubeFTR, angle, angle, 0.0f, &cubeOrigin);
				Vec3::rot(&rCubeFBL, angle, angle, 0.0f, &cubeOrigin);
				Vec3::rot(&rCubeFBR, angle, angle, 0.0f, &cubeOrigin);
				Vec3::rot(&rCubeBTL, angle, angle, 0.0f, &cubeOrigin);
				Vec3::rot(&rCubeBTR, angle, angle, 0.0f, &cubeOrigin);
				Vec3::rot(&rCubeBBL, angle, angle, 0.0f, &cubeOrigin);
				Vec3::rot(&rCubeBBR, angle, angle, 0.0f, &cubeOrigin);

				Vec3 renderCubeFTL = perspectiveTransform(&rCubeFTL);
				Vec3 renderCubeFTR = perspectiveTransform(&rCubeFTR);
				Vec3 renderCubeFBL = perspectiveTransform(&rCubeFBL);
				Vec3 renderCubeFBR = perspectiveTransform(&rCubeFBR);
				Vec3 renderCubeBTL = perspectiveTransform(&rCubeBTL);
				Vec3 renderCubeBTR = perspectiveTransform(&rCubeBTR);
				Vec3 renderCubeBBL = perspectiveTransform(&rCubeBBL);
				Vec3 renderCubeBBR = perspectiveTransform(&rCubeBBR);

				renderCubeFTL = screenspaceTransform(&renderCubeFTL);
				renderCubeFTR = screenspaceTransform(&renderCubeFTR);
				renderCubeFBL = screenspaceTransform(&renderCubeFBL);
				renderCubeFBR = screenspaceTransform(&renderCubeFBR);
				renderCubeBTL = screenspaceTransform(&renderCubeBTL);
				renderCubeBTR = screenspaceTransform(&renderCubeBTR);
				renderCubeBBL = screenspaceTransform(&renderCubeBBL);
				renderCubeBBR = screenspaceTransform(&renderCubeBBR);

				drawLine((int)renderCubeFTL.x, (int)renderCubeFTL.y, (int)renderCubeFTR.x, (int)renderCubeFTR.y);
				drawLine((int)renderCubeFTR.x, (int)renderCubeFTR.y, (int)renderCubeFBR.x, (int)renderCubeFBR.y);
				drawLine((int)renderCubeFBR.x, (int)renderCubeFBR.y, (int)renderCubeFBL.x, (int)renderCubeFBL.y);
				drawLine((int)renderCubeFBL.x, (int)renderCubeFBL.y, (int)renderCubeFTL.x, (int)renderCubeFTL.y);
				drawLine((int)renderCubeBTL.x, (int)renderCubeBTL.y, (int)renderCubeBTR.x, (int)renderCubeBTR.y);
				drawLine((int)renderCubeBTR.x, (int)renderCubeBTR.y, (int)renderCubeBBR.x, (int)renderCubeBBR.y);
				drawLine((int)renderCubeBBR.x, (int)renderCubeBBR.y, (int)renderCubeBBL.x, (int)renderCubeBBL.y);
				drawLine((int)renderCubeBBL.x, (int)renderCubeBBL.y, (int)renderCubeBTL.x, (int)renderCubeBTL.y);

				drawLine((int)renderCubeBTL.x, (int)renderCubeBTL.y, (int)renderCubeFTL.x, (int)renderCubeFTL.y);
				drawLine((int)renderCubeBTR.x, (int)renderCubeBTR.y, (int)renderCubeFTR.x, (int)renderCubeFTR.y);
				drawLine((int)renderCubeBBL.x, (int)renderCubeBBL.y, (int)renderCubeFBL.x, (int)renderCubeFBL.y);
				drawLine((int)renderCubeBBR.x, (int)renderCubeBBR.y, (int)renderCubeFBR.x, (int)renderCubeFBR.y);*/

				angle += 0.001f;

				/////////LINES///////////
				/*drawLine(319, 239, 0, 0);
				drawLine(319, 239, 159, 0);
				
				drawLine(319, 239, 479, 0);
				drawLine(319, 239, 639, 0);
				drawLine(319, 239, 639, 119);
				
				drawLine(319, 239, 639, 359);
				drawLine(319, 239, 639, 479);
				drawLine(319, 239, 479, 479);
				
				drawLine(319, 239, 159, 479);
				drawLine(319, 239, 0, 479);
			
				drawLine(319, 239, 0, 119);

				drawLine(299, 239, 339, 239);
				drawLine(319, 219, 319, 259);*/

				SDL_RenderPresent(gRenderer);

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
	}

	//Free resources and close SDL
	close();

	return 0;
}