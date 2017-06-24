/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#pragma once
#include <SDL.h>
#include <stdio.h>
#include "LineDrawing.h"
//#include "DrawWrapper.h"
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

Renderer renderer;

/////////CUBE
Vec3 sqTL	= { -1.0f, 1.0f, 2.0f };
Vec3 sqTR	= { 1.0f, 1.0f, 2.0f };
Vec3 sqBL	= { -1.0f, -1.0f, 2.0f };
Vec3 sqBR	= { 1.0f, -1.0f, 2.0f };
Vec3 cubeTL = { -1.0f, 1.0f, 4.0f };
Vec3 cubeTR = { 1.0f, 1.0f, 4.0f };
Vec3 cubeBL = { -1.0f, -1.0f, 4.0f };
Vec3 cubeBR = { 1.0f, -1.0f, 4.0f };


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

			renderer.addVert(&sqTL);
			renderer.addVert(&sqTR);
			renderer.addVert(&sqBL);
			renderer.addVert(&sqBR);
			renderer.addVert(&cubeTL);
			renderer.addVert(&cubeTR);
			renderer.addVert(&cubeBL);
			renderer.addVert(&cubeBR);

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

				////////CUBE (CAMERA)////////

				renderer.render();

				angle += 0.001f;
				renderer.setCameraRotation(0.0f, angle, 0.0f);

				SDL_RenderPresent(gRenderer);

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
	}

	//Free resources and close SDL
	close();

	return 0;
}