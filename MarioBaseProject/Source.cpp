#include "Constants.h"
#include <iostream>
#include <SDL.h>
#include <SDL_image.h>

using namespace std;

// Globals
SDL_Window* g_window = nullptr;

// Prototypes
bool InitSDL();
void CloseSDL();

int main(int argc, char* args[])
{
	// SDL setup check
	if (InitSDL())
		SDL_Delay(5000);

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
}
