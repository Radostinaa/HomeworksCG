#include "Menu.h"
#include <SDL.h>
#include <stdio.h>

Menu::Menu(SDL_Window* w, TTF_Font* f)
{
	lables[0] = "1";
	lables[1] = "2";
	lables[2] = "3";
	lables[3] = "4";
	lables[4] = "Close";

	font = f;
	window = w;
	screen = SDL_GetWindowSurface(w);

	for (int i = 0; i < NUMMENUS; i++)
	{
		menus[i] = TTF_RenderText_Solid(font, lables[i], colors[0]);
	}

	//x
	for (int i = 0; i < NUMMENUS; i++)
	{
		pos[i].x = screen->clip_rect.w / 2 - menus[i]->clip_rect.w/2;
	}

	pos[2].y = screen->clip_rect.h / 2 - menus[2]->clip_rect.h/2; // center
	//y up
	pos[1].y = screen->clip_rect.h / 2 - (menus[2]->clip_rect.h/2 + menus[1]->clip_rect.h);
	pos[0].y = pos[1].y - menus[0]->clip_rect.h; 
	//y down
	pos[3].y = pos[2].y + menus[3]->clip_rect.h; 
	pos[4].y = pos[3].y + menus[4]->clip_rect.h; 

}

Menu::~Menu()
{
	freeAll();
}

int Menu::init()
{
	int x, y;
	while (true)
	{
		time = SDL_GetTicks();

		SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));

		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				return 0;
				break;
			case SDL_MOUSEMOTION:
				x = event.motion.x;
				y = event.motion.y;

				for (int i = 0; i < NUMMENUS; i++)
				{
					if (isInRect(x, y, i))
					{
						if (!selected[i])
						{
							selected[i] = 1;
							SDL_FreeSurface(menus[i]);
							menus[i] = TTF_RenderText_Solid(font, lables[i], colors[1]);
						}
					}
					else
					{
						if (selected[i])
						{
							selected[i] = 0;
							SDL_FreeSurface(menus[i]);
							menus[i] = TTF_RenderText_Solid(font, lables[i], colors[0]);
						}
					}
				}
				break;
			case SDL_MOUSEBUTTONDOWN:
				x = event.button.x;
				y = event.button.y;
				for (int i = 0; i < NUMMENUS; i++)
				{
					if (isInRect(x, y, i))
					{
						return i+1;
					}
				}
				break;
			case SDLK_ESCAPE:
				return 5; //==close
				break;
			}
			for (int i = 0; i < NUMMENUS; i++)
			{
				SDL_BlitSurface(menus[i], NULL, screen, &pos[i]);
			}
			SDL_UpdateWindowSurface(window);

			if (1000 / 30 > (SDL_GetTicks() - time))
			{
				SDL_Delay(1000 / 30 - (SDL_GetTicks() - time));
			}
		}
	}
	return 0;
}

void Menu::freeAll()
{
	for (int i = 0; i < NUMMENUS; i++)
	{
		SDL_FreeSurface(menus[i]);
	}
}

bool Menu::isInRect(int x, int y, int rect)
{
	if (x >= pos[rect].x && x <= (pos[rect].x + pos[rect].w) && y >= pos[rect].y && y < (pos[rect].y + pos[rect].h))
		return true;

	return false;
}