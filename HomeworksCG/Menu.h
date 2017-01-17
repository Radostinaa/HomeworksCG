#pragma once
#include <SDL_ttf.h>

const int NUMMENUS = 5;
class Menu
{
private:
	const int numMenus = 5;
	const char* lables[NUMMENUS];
	SDL_Surface* menus[NUMMENUS];
	SDL_Color colors[2] = { { 255,255,255 },{ 255,0,0 } };
	bool selected[NUMMENUS] = { 0,0,0,0,0 };
	SDL_Rect pos[NUMMENUS];
	SDL_Surface* screen;
	SDL_Window* window;
	TTF_Font* font;

	SDL_Event event;
	Uint32 time;

	void freeAll();
	bool isInRect(int x, int y, int rect);


public:
	Menu(SDL_Window* w, TTF_Font* f);
	~Menu();
	int init();
};
