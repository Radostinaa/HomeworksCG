#pragma once
#include <SDL.h>
#include "Point.h"
#include <SDL_ttf.h>

class Task
{
public:
	Task(SDL_Renderer* r, int pNeeded);
	virtual ~Task();

	virtual void Draw() {};
	virtual void drawInfo(SDL_Window* window, SDL_Surface* screen, TTF_Font* font) {};
	void addPoint(int x, int y);
	void resetPoints();
	void deletePoints();
	void BresenhamLine(Point from, Point to, SDL_Color color);

	SDL_Renderer* renderer;
	int pointsNeeded;
	Point* points; 
	int pn;
	int pointsNum;
};