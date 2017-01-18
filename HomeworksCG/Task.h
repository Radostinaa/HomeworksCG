#pragma once
#include <SDL.h>
#include "Point.h"
#include <SDL_ttf.h>

class Task
{
public:
	Task(SDL_Renderer* r, int pNeeded);
	~Task();
	virtual void Draw() {};
	virtual void drawInfo(SDL_Window* window, SDL_Surface* screen, TTF_Font* font) {};

	SDL_Renderer* renderer;
	int pointsNeeded;
	void addPoint(int x, int y);
	void resetPoints();
	void deletePoints();
	Point* points; 
	int pn;
	int pointsNum;
};