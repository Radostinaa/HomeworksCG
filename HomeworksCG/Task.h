#pragma once
#include <SDL.h>
#include "Point.h"

class Task
{
public:
	Task(SDL_Renderer* r, int pNeeded);
	~Task();
	virtual void Draw() 
	{
	};

	SDL_Renderer* renderer;
	int pointsNeeded;
	void addPoint(int x, int y);
	void reset();
	void deletePoints();
	Point* points;

private: 
	int pn;
	int pointsNum;
};