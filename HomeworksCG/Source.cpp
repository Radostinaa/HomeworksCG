#include <SDL.h>
#include <stdio.h>
#include "Menu.h"
#include "Task2.h"
#include "Task1.h"
#include "Point.h"

const int SCREEN_WIDTH = 1040;
const int SCREEN_HEIGHT = 880;
int pixelWidth = 4;

void clear(SDL_Renderer* r, SDL_Surface* screen, SDL_Window* window)
{

	SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0xFF, 0xFF, 0xFF));
	SDL_UpdateWindowSurface(window);
	SDL_SetRenderDrawColor(r, 0xFF, 0xFF, 0xFF, 0xFF);
	SDL_RenderClear(r);
}

Task* swithcTask(int task, SDL_Renderer* r)
{
	switch (task)
	{
	case 1:
		return new Task1(r);
	case 2:
		return new Task2(r);
		break;
	}
}

int main(int argc, char* args[])
{
	SDL_Window* window = NULL;
	SDL_Surface* screen = NULL;
	TTF_Font *font = NULL;
	TTF_Font *fontInfo = NULL;
	SDL_Renderer *renderer = NULL;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	}
	else
	{
		window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);


		if (window == NULL)
		{
			printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		}
		else if (TTF_Init() < 0)
		{
			// Handle error...
		}
		else
		{
			font = TTF_OpenFont("OpenSans-LightItalic.ttf", 28);
			fontInfo = TTF_OpenFont("OpenSans-LightItalic.ttf", 18);
			screen = SDL_GetWindowSurface(window);

			int running;
			Menu menu = Menu(window, font);
			running = menu.init();

			clear(renderer, screen, window);

			int currentTask;
			if (running == 5 || running == 0) currentTask = 1;
			else  currentTask = running;

			Task* t = swithcTask(currentTask, renderer);
			t->drawInfo(window, screen, fontInfo);

			Point p;
			SDL_Event event;

			while (running != 0)
			{
				while (SDL_PollEvent(&event))
				{
					switch (event.type)
					{
						//case SDL_QUIT:
						//	//freeAll();
							//break;
					case SDL_KEYDOWN:
						if (event.key.keysym.sym == SDLK_m)// open menu
						{ 
							running = menu.init();
							if (running != currentTask && running != 0 && running != 5) //we have new task
							{
								currentTask = running;
								delete t;
								t = swithcTask(currentTask, renderer);
								clear(renderer, screen, window);
								t->drawInfo(window, screen, font);
							}
						}
						else if (event.key.keysym.sym == SDLK_c) // clear
						{
							clear(renderer, screen, window);
							t->drawInfo(window,screen,fontInfo);
						}
						break;
					case SDL_MOUSEBUTTONDOWN:
						if (event.button.button == SDL_BUTTON_LEFT) //send x and y to current task
						{
							p.x = event.button.x;
							p.y = event.button.y;
							p.draw(renderer, {0,0,0,1}, false);

							t->addPoint(p.x, p.y);

							if (t->pointsNeeded == 0) t->Draw();
						}
						break;
					}
				}
			}

			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			TTF_Quit();
			SDL_Quit();
			delete t;

		}
	}

	return 0;
}

