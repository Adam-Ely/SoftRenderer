/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/

//Using SDL and standard IO
#pragma once
#include <SDL.h>
#include <stdio.h>
#include "LineDrawing.h"
#include "Vec3.h"
#include <float.h>
#include "3DRenderer.h"
#include "Mario.h"

float RandomFloat(float a, float b) {
	float random = ((float)rand()) / (float)RAND_MAX;
	float diff = b - a;
	float r = random * diff;
	return a + r;
}

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

Model marioModel;

/////////CUBE
Vec3 cubeOneFTL = { -1.0f, 1.0f, -1.0f };
Vec3 cubeOneFTR = { 1.0f, 1.0f, -1.0f };
Vec3 cubeOneFBL = { -1.0f, -1.0f, -1.0f };
Vec3 cubeOneFBR = { 1.0f, -1.0f, -1.0f };
Vec3 cubeOneBTL = { -1.0f, 1.0f, 1.0f };
Vec3 cubeOneBTR = { 1.0f, 1.0f, 1.0f };
Vec3 cubeOneBBL = { -1.0f, -1.0f, 1.0f };
Vec3 cubeOneBBR = { 1.0f, -1.0f, 1.0f };

std::vector<Vec3> cubeVerts = {cubeOneFTL, 
								cubeOneFTR,
								cubeOneFBL,
								cubeOneFBR,
								cubeOneBTL,
								cubeOneBTR,
								cubeOneBBL,
								cubeOneBBR};

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

int main(int argc, char* args[])
{
	std::vector<Vec3> marioVerts;
	for (int i = 0; i < mario.size(); i += 3)
	{
		Vec3 newVert = { (float)mario[i], (float)mario[i+1], (float)mario[i+2] };
		marioVerts.push_back(newVert);
	}

	marioModel.m_vertices = &marioVerts;
	marioModel.m_indexBuffer = &marioIndex;
	marioModel.m_position = { 0.0f, -150.0f, 250.0f };
	marioModel.m_rotation = { 0.0f, 0.0f, 0.0f };
	marioModel.m_rotationVelocity = { 0.0f, 0.001f, 0.0f };

	renderer.addModel(marioModel);
	
	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Main loop flag
		bool quit = false;

		//Event handler
		SDL_Event e;

		float xAngle = 0.0f;
		float yAngle = 0.0f;
		float angle = 0.0f;

		//for (int i = 0; i < 100000; ++i)
		//{
		//	Vec3 vert = {RandomFloat(-2.0f, 2.0f),
		//				RandomFloat(-2.0f, 2.0f),
		//				RandomFloat(-2.0f, 2.0f)};

			//	renderer.addVert(vert);

			//}
			/*renderer.addVert(&cubeOneFTL);
			renderer.addVert(&cubeOneFTR);
			renderer.addVert(&cubeOneFBL);
			renderer.addVert(&cubeOneFBR);
			renderer.addVert(&cubeOneBTL);
			renderer.addVert(&cubeOneBTR);
			renderer.addVert(&cubeOneBBL);
			renderer.addVert(&cubeOneBBR);*/

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
					if( e.type == SDL_KEYDOWN)
					{
						if (e.key.keysym.sym == SDLK_w)
						{
							xAngle += 0.01f;
						}
						if (e.key.keysym.sym == SDLK_s)
						{
							xAngle -= 0.01f;
						}
						if (e.key.keysym.sym == SDLK_a)
						{
							yAngle += 0.01f;
						}
						if (e.key.keysym.sym == SDLK_d)
						{
							yAngle -= 0.01f;
						}
					}
				}

				//Draw
				SDL_SetRenderDrawColor(gRenderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);
				SDL_RenderClear(gRenderer);
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);

				////////CUBE (CAMERA)////////

				renderer.render();

				angle += 0.005f;
				//renderer.setCameraRotation(angle, angle, 0.0f);

				SDL_RenderPresent(gRenderer);

				//Update the surface
				SDL_UpdateWindowSurface( gWindow );
			}
	}

	//Free resources and close SDL
	close();

	return 0;
}