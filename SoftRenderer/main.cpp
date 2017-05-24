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

Vec3 left = { -1.0f, 0.57733f, 2.0f };
Vec3 right = { 1.0f, 0.57733f, 2.0f };
Vec3 top = { 0.0f, -1.15467f, 2.0f };

Vec3 origin = { 0.0f, 0.0f, 2.0f };

Vec3 sqTL = { -1.0f, 1.0f, 1.0f };
Vec3 sqTR = { 1.0f, 1.0f, 1.0f };
Vec3 sqBL = { -1.0f, -1.0f, 1.0f };
Vec3 sqBR = { 1.0f, -1.0f, 1.0f };

Vec3 rotatedLeft = left;
Vec3 rotatedRight = right;
Vec3 rotatedTop = top;

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

				rotatedLeft = left;
				rotatedRight = right;
				rotatedTop = top;

				Vec3::rot(&rotatedLeft, 0.0f, angle, 0.0f, &origin);
				Vec3::rot(&rotatedRight, 0.0f, angle, 0.0f, &origin);
				Vec3::rot(&rotatedTop, 0.0f, angle, 0.0f, &origin);

				/*Vec3::rot(&rotatedLeft, angle, angle, angle, &origin);
				Vec3::rot(&rotatedRight, angle, angle, angle, &origin);
				Vec3::rot(&rotatedTop, angle, angle, angle, &origin);*/

				angle += 0.001f;

				Vec3 renderLeft =	perspectiveTransform(&rotatedLeft);
				Vec3 renderRight =	perspectiveTransform(&rotatedRight);
				Vec3 renderTop =	perspectiveTransform(&rotatedTop);

				renderLeft = screenspaceTransform(&renderLeft);
				renderRight = screenspaceTransform(&renderRight);
				renderTop = screenspaceTransform(&renderTop);

				drawTriangle(&renderLeft, &renderRight, &renderTop);

				Vec3 renderSqTL = perspectiveTransform(&sqTL);
				Vec3 renderSqTR = perspectiveTransform(&sqTR);
				Vec3 renderSqBR = perspectiveTransform(&sqBR);
				Vec3 renderSqBL = perspectiveTransform(&sqBL);

				renderSqTL = screenspaceTransform(&renderSqTL);
				renderSqTR = screenspaceTransform(&renderSqTR);
				renderSqBR = screenspaceTransform(&renderSqBR);
				renderSqBL = screenspaceTransform(&renderSqBL);

				drawLine((int)renderSqTL.x, (int)renderSqTL.y, (int)renderSqTR.x, (int)renderSqTR.y);
				drawLine((int)renderSqTR.x, (int)renderSqTR.y, (int)renderSqBR.x, (int)renderSqBR.y);
				drawLine((int)renderSqBR.x, (int)renderSqBR.y, (int)renderSqBL.x, (int)renderSqBL.y);
				drawLine((int)renderSqBL.x, (int)renderSqBL.y, (int)renderSqTL.x, (int)renderSqTL.y);

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