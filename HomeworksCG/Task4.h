#pragma once
#include "Task.h"

class Task4 : public Task 
{
public:
	Task4(SDL_Renderer* r) : Task(r, 4)
	{		
		pointsNeeded = 2;
		rectDrawn = false;
		colorOut = { 255,0,0,1 };
		colorIn = { 0 , 0, 255,1 };
	}
	~Task4();

	void Draw();
private:
	bool rectDrawn;
	SDL_Color color;
	SDL_Color colorOut;
	SDL_Color colorIn;
	
	void Clip(Point p1, Point p2, Point po1, Point po2);
	bool CalcT(float r, float q, float* tin, float* tout);
	void drawRect();
};