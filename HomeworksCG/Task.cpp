#include "Task.h"
#include <new>

Task::Task(SDL_Renderer * r, int pNeeded)
{
	pn = pNeeded;
	renderer = r;
	resetPoints();
}

Task::Task(const Task & t)
{
}

Task::~Task()
{
	deletePoints();
}

void Task::addPoint(int x, int y)
{
	pointsNeeded--;
	Point p = Point(x, y);
	p.toCustom();
	points[pointsNum] = p;
	pointsNum++;
}

void Task::resetPoints()
{
	pointsNum = 0;
	pointsNeeded = pn;
	points = new (std::nothrow) Point[pointsNeeded];
}

void Task::deletePoints()
{
	delete[] points;
}
