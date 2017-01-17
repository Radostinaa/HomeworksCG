#pragma once
#include <SDL.h>
#include "Point.h"
#include "Task.h"

class Task1 : public Task
{
public :
	Task1(SDL_Renderer* r) : Task(r , 2) 
	{
		isBresenham = false;
	}
	//Task1();
	//void addPoint(int x, int y);
	void Draw();
	//int pointsNeeded;

private:
	//int pointsNum;
	//Point* points;
	bool isBresenham;
	//SDL_Renderer* renderer;

	//void deletePoints();
	// reset();
	
	void drawBresenhamCircle(Point center, int radius);
	void SimpleCircle(Point center, int radius);
	void FourSymmetric(Point center, int x, int y, int radius);
	void EightSymmetric(Point center, int x, int y, int radius);
};
