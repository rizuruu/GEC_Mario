#include "Constants.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

// Globals
SDL_Window* g_window = nullptr;
SDL_Renderer* g_renderer = nullptr;
SDL_Texture* g_texture = nullptr;

// Prototypes
bool InitSDL();
void CloseSDL();
bool Update();

void Render();
SDL_Texture* LoadTextureFromFile(string path);
void FreeTexture();

int main(int argc, char* args[])
{
	// SDL setup check
	if (InitSDL())
	{
		//flag to check if we wish to quit
		bool quit = false;

		//Game Loop
		while (!quit)
		{
			Render();
			quit = Update();
		}
	}

	CloseSDL();
	return 0;
}

bool InitSDL()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		cout << "SDL did not initialise, Error: " << SDL_GetError();
		return false;
	}
	else
	{
		// Create Window
		g_window = SDL_CreateWindow("GEC",
			SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
			SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

		g_renderer = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);

		if (g_renderer != nullptr)
		{
			//init PNG loading
			int imageFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imageFlags) & imageFlags))
			{
				cout << "SDL_Image could not initialise. Error: " << IMG_GetError();
				return false;
			}
		}
		else
		{
			cout << "Renderer could not initialise. Error: " << SDL_GetError();
			return false;
		}

		//Load the background texture
		g_texture = LoadTextureFromFile("Images/test.bmp");
		if (g_texture == nullptr)
		{
			return false;
		}

		// Check if window is created
		if (g_window == nullptr)
		{
			// Window Failed
			cout << "Window was not created. Error: " << SDL_GetError();
			return false;
		}
	}
	return true;
}

void CloseSDL()
{
	// Release window
	SDL_DestroyWindow(g_window);
	g_window = nullptr;
	IMG_Quit();
	SDL_Quit();
	//clear the texture
	FreeTexture();
	//release the renderer
	SDL_DestroyRenderer(g_renderer);
	g_renderer = nullptr;
}

bool Update()
{
	//Event handler
	SDL_Event e;

	//get events
	SDL_PollEvent(&e);

	//handle the events
	switch (e.type)
	{
		//click the 'X' to quit
	case SDL_QUIT:
		return true;
		break;
	}

	return false;
}

void Render()
{
	//Clear the screen
	SDL_SetRenderDrawColor(g_renderer, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(g_renderer);

	//set where to render the texture
	SDL_Rect renderLocation = { 0,0,SCREEN_WIDTH, SCREEN_HEIGHT };

	//Render to screen
	SDL_RenderCopyEx(g_renderer, g_texture, NULL, &renderLocation, 0, NULL, SDL_FLIP_NONE);

	//update the screen
	SDL_RenderPresent(g_renderer);
}

SDL_Texture* LoadTextureFromFile(string path)
{
	//remove memory used for a previous texture
	FreeTexture();
	SDL_Texture* p_texture = nullptr;

	//Load the image
	SDL_Surface* p_surface = IMG_Load(path.c_str());
	if (p_surface == nullptr)
	{
		cout << "Unable to create texture from surface. SDL Error: " << SDL_GetError();
		//remove the loaded surface now that we have a texture
		SDL_FreeSurface(p_surface);
	}
	else
	{
		p_texture = SDL_CreateTextureFromSurface(g_renderer, p_surface);
		cout << "Unable to create texture from surface. IMG Error: " << IMG_GetError();
	}

	//Return the texture
	return p_texture;
}

void FreeTexture()
{
	//check if texture exists before removing it
	if (g_texture != nullptr)
	{
		SDL_DestroyTexture(g_texture);
		g_texture = nullptr;
	}
}
