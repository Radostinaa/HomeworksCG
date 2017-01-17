#include "Task.h"
#include <new>

Task::Task(SDL_Renderer * r, int pNeeded)
{
	pn = pNeeded;
	renderer = r;
	reset();
}

Task::~Task()
{
	deletePoints();
}

void Task::addPoint(int x, int y)
{
	pointsNeeded--;
	points[pointsNum] = Point(x, y);
	pointsNum++;
}

void Task::reset()
{
	pointsNum = 0;
	pointsNeeded = pn;
	points = new (std::nothrow) Point[pointsNeeded];
}

void Task::deletePoints()
{
	delete[] points;
}
