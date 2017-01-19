#pragma once
#include "Task.h"
#include <SDL.h>

struct Pixel 
{
	int x, y;
	SDL_Color color;
	Pixel(int _x = -1, int _y = -1, SDL_Color _color = {0,0,0,0}) 
		: x(_x), y(_y), color(_color) {}
};

class Task3 : public Task
{
public:
	Task3(SDL_Renderer* r, int _w, int _h) : Task(r, 5) 
	{
		pointsNeeded = 2;//first side
		w = _w;
		h = _h;
		filledPixels = new Pixel[w*h];
		pixelsCount = 0;
		colorSides = { 255,0,0,1 };
		colorFill = { 255,165,0,1 };
		edges = 0;
		clear = true;
	}
	~Task3();
	void Draw();
	
private:

	SDL_Color colorSides;
	SDL_Color colorFill;
	int edges;
	Pixel* filledPixels;
	int pixelsCount;
	int w, h;
	bool clear;

	bool freePixel(Point p);
	void BoundryFill(Point begin);
	void drawside();
	void BresenhamLine(Point from, Point to);
};

