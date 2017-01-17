#pragma once
#include <SDL.h>
#include "Task.h"
#include <SDL_ttf.h>

class Task1 : public Task
{
public:
	Task1(SDL_Renderer* r) : Task(r, 2)
	{
		isBresenham = false;
	}
	~Task1();

	void Draw();
	void drawInfo(SDL_Window* window, SDL_Surface* screen, TTF_Font* font);

private:
	bool isBresenham;
	SDL_Surface * info1;
	SDL_Surface * info2;
	SDL_Rect pos1, pos2;
	SDL_Color color;

	void BresenhamLine(Point p1, Point p2);
	void RoundingLine(Point p1, Point p2);
};
