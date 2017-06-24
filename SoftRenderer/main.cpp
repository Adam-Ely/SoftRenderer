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
Vec3 sqTL	= { -1.0f, 1.0f, 2.0f };
Vec3 sqTR	= { 1.0f, 1.0f, 2.0f };
//Vec3 sqBL	= { -1.0f, -1.0f, 2.0f };
//Vec3 sqBR	= { 1.0f, -1.0f, 2.0f };
//Vec3 cubeTL = { -1.0f, 1.0f, 4.0f };
//Vec3 cubeTR = { 1.0f, 1.0f, 4.0f };
//Vec3 cubeBL = { -1.0f, -1.0f, 4.0f };
//Vec3 cubeBR = { 1.0f, -1.0f, 4.0f };

//Vec3 cubeOrigin = { 0.0f, 0.0f, 3.0f };

//Vec3 rCubeFTL;
//Vec3 rCubeFTR;
//Vec3 rCubeFBL;
//Vec3 rCubeFBR;
//Vec3 rCubeBTL;
//Vec3 rCubeBTR;
//Vec3 rCubeBBL;
//Vec3 rCubeBBR;

//Vec3 cubeFTL = {2.0f, 1.0f, 1.0f};
//Vec3 cubeFTR = {2.0f, 1.0f, -1.0f};
//Vec3 cubeFBL = {2.0f, -1.0f, 1.0f};
//Vec3 cubeFBR = {2.0f, -1.0f, -1.0f};
//Vec3 cubeBTL = {4.0f, 1.0f, 1.0f};
//Vec3 cubeBTR = {4.0f, 1.0f, -1.0f};
//Vec3 cubeBBL = {4.0f, -1.0f, 1.0f};
//Vec3 cubeBBR = {4.0f, -1.0f, -1.0f};


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
	//renderer.setCameraRotation(0.0f, (float)M_PI, 0.0f);
	
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
			/*renderer.addVert(&sqBL);
			renderer.addVert(&sqBR);
			renderer.addVert(&cubeTL);
			renderer.addVert(&cubeTR);
			renderer.addVert(&cubeBL);
			renderer.addVert(&cubeBR);*/

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
				//rotatedLeft = left;
				//rotatedRight = right;
				//rotatedTop = top;

				//Vec3::rot(&rotatedLeft, 0.0f, angle, 0.0f, &origin);
				//Vec3::rot(&rotatedRight, 0.0f, angle, 0.0f, &origin);
				//Vec3::rot(&rotatedTop, 0.0f, angle, 0.0f, &origin);

				///*Vec3::rot(&rotatedLeft, angle, angle, angle, &origin);
				//Vec3::rot(&rotatedRight, angle, angle, angle, &origin);
				//Vec3::rot(&rotatedTop, angle, angle, angle, &origin);*/			

				//Vec3 renderLeft =	Renderer::perspectiveTransform(&rotatedLeft);
				//Vec3 renderRight =	Renderer::perspectiveTransform(&rotatedRight);
				//Vec3 renderTop =	Renderer::perspectiveTransform(&rotatedTop);

				//renderLeft = Renderer::screenspaceTransform(&renderLeft);
				//renderRight = Renderer::screenspaceTransform(&renderRight);
				//renderTop = Renderer::screenspaceTransform(&renderTop);

				//drawTriangle(&renderLeft, &renderRight, &renderTop);

				///////Y-AXIS//////////

				/*Vec3 renderAxisTop		=	Renderer::perspectiveTransform(&axisTop);
				Vec3 renderAxisBottom	=	Renderer::perspectiveTransform(&axisBottom);
				renderAxisTop			=	Renderer::screenspaceTransform(&renderAxisTop);
				renderAxisBottom		=	Renderer::screenspaceTransform(&renderAxisBottom);

				drawLine((int)renderAxisTop.x, (int)renderAxisTop.y, (int)renderAxisBottom.x, (int)renderAxisBottom.y);*/

				//////////CUBE (PRE CAMERA)////////////
				//rCubeFTL = sqTL;
				//rCubeFTR = sqTR;
				//rCubeFBL = sqBL;
				//rCubeFBR = sqBR;
				//rCubeBTL = cubeTL;
				//rCubeBTR = cubeTR;
				//rCubeBBL = cubeBL;
				//rCubeBBR = cubeBR;

				//Vec3::rot(&rCubeFTL, angle, angle, 0.0f, &cubeOrigin);
				//Vec3::rot(&rCubeFTR, angle, angle, 0.0f, &cubeOrigin);
				//Vec3::rot(&rCubeFBL, angle, angle, 0.0f, &cubeOrigin);
				//Vec3::rot(&rCubeFBR, angle, angle, 0.0f, &cubeOrigin);
				//Vec3::rot(&rCubeBTL, angle, angle, 0.0f, &cubeOrigin);
				//Vec3::rot(&rCubeBTR, angle, angle, 0.0f, &cubeOrigin);
				//Vec3::rot(&rCubeBBL, angle, angle, 0.0f, &cubeOrigin);
				//Vec3::rot(&rCubeBBR, angle, angle, 0.0f, &cubeOrigin);

				//Vec3 renderCubeFTL = Renderer::perspectiveTransform(&rCubeFTL);
				//Vec3 renderCubeFTR = Renderer::perspectiveTransform(&rCubeFTR);
				//Vec3 renderCubeFBL = Renderer::perspectiveTransform(&rCubeFBL);
				//Vec3 renderCubeFBR = Renderer::perspectiveTransform(&rCubeFBR);
				//Vec3 renderCubeBTL = Renderer::perspectiveTransform(&rCubeBTL);
				//Vec3 renderCubeBTR = Renderer::perspectiveTransform(&rCubeBTR);
				//Vec3 renderCubeBBL = Renderer::perspectiveTransform(&rCubeBBL);
				//Vec3 renderCubeBBR = Renderer::perspectiveTransform(&rCubeBBR);

				//renderCubeFTL = Renderer::screenspaceTransform(&renderCubeFTL);
				//renderCubeFTR = Renderer::screenspaceTransform(&renderCubeFTR);
				//renderCubeFBL = Renderer::screenspaceTransform(&renderCubeFBL);
				//renderCubeFBR = Renderer::screenspaceTransform(&renderCubeFBR);
				//renderCubeBTL = Renderer::screenspaceTransform(&renderCubeBTL);
				//renderCubeBTR = Renderer::screenspaceTransform(&renderCubeBTR);
				//renderCubeBBL = Renderer::screenspaceTransform(&renderCubeBBL);
				//renderCubeBBR = Renderer::screenspaceTransform(&renderCubeBBR);

				//drawLine((int)renderCubeFTL.x, (int)renderCubeFTL.y, (int)renderCubeFTR.x, (int)renderCubeFTR.y);
				//drawLine((int)renderCubeFTR.x, (int)renderCubeFTR.y, (int)renderCubeFBR.x, (int)renderCubeFBR.y);
				//drawLine((int)renderCubeFBR.x, (int)renderCubeFBR.y, (int)renderCubeFBL.x, (int)renderCubeFBL.y);
				//drawLine((int)renderCubeFBL.x, (int)renderCubeFBL.y, (int)renderCubeFTL.x, (int)renderCubeFTL.y);
				//drawLine((int)renderCubeBTL.x, (int)renderCubeBTL.y, (int)renderCubeBTR.x, (int)renderCubeBTR.y);
				//drawLine((int)renderCubeBTR.x, (int)renderCubeBTR.y, (int)renderCubeBBR.x, (int)renderCubeBBR.y);
				//drawLine((int)renderCubeBBR.x, (int)renderCubeBBR.y, (int)renderCubeBBL.x, (int)renderCubeBBL.y);
				//drawLine((int)renderCubeBBL.x, (int)renderCubeBBL.y, (int)renderCubeBTL.x, (int)renderCubeBTL.y);

				//drawLine((int)renderCubeBTL.x, (int)renderCubeBTL.y, (int)renderCubeFTL.x, (int)renderCubeFTL.y);
				//drawLine((int)renderCubeBTR.x, (int)renderCubeBTR.y, (int)renderCubeFTR.x, (int)renderCubeFTR.y);
				//drawLine((int)renderCubeBBL.x, (int)renderCubeBBL.y, (int)renderCubeFBL.x, (int)renderCubeFBL.y);
				//drawLine((int)renderCubeBBR.x, (int)renderCubeBBR.y, (int)renderCubeFBR.x, (int)renderCubeFBR.y);

				///*drawPoint(&renderCubeFTL);
				//drawPoint(&renderCubeFTR);
				//drawPoint(&renderCubeFBL);
				//drawPoint(&renderCubeFBR);
				//drawPoint(&renderCubeBTL);
				//drawPoint(&renderCubeBTR);
				//drawPoint(&renderCubeBBL);
				//drawPoint(&renderCubeBBR);*/

				

				////////CUBE (CAMERA)////////

				renderer.render();

				angle += 0.001f;
				renderer.setCameraRotation(0.0f, angle, 0.0f);

				

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