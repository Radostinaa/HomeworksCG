#include <SDL.h>
#include <stdio.h>
#include "Menu.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main( int argc, char* args[] )
{
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;
	TTF_Font *font = NULL;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
	{
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	}
	else
	{
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
		if( window == NULL )
		{
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		}
		else if (TTF_Init() < 0) 
		{
			// Handle error...
		}
		else
		{
			font = TTF_OpenFont("OpenSans-LightItalic.ttf", 28);
			if (!font) {
				printf("!!!!!!!!!!!!TTF_OpenFont: %s\n", TTF_GetError());
				
			}
			screen = SDL_GetWindowSurface( window );

			int running = 1;
			Menu menu = Menu(window, font);
			running = menu.init();
			
			SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
			SDL_UpdateWindowSurface(window);

			int task = 1;
			int x, y;
			SDL_Event event;

			while (running != -1)
			{
				while (SDL_PollEvent(&event))
				{
					switch (event.type)
					{
					//case SDL_QUIT:
					//	//freeAll();
						//break;
					case SDLK_ESCAPE: // open menu
							running = menu.init();
							if (running != task && running != 0) //we have new task
							{

							}
							break;
						case SDL_BUTTON_LEFT: //send x and y to current task
							x = event.button.x;
							y = event.button.y;
							break;
					}
				}

				SDL_UpdateWindowSurface(window);
				SDL_Delay(2000);
			}
		}
	}

	SDL_DestroyWindow( window );
	SDL_Quit();

	return 0;
}