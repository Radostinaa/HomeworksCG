#include <stdio.h>
#include "Task.h"
#include <new>

Task::Task(int taskNub, SDL_Window* w, SDL_Renderer *r)
{
	window = w;
	renderer = r;
	taskNumber = taskNub;

	switch (taskNumber)
	{
	case 1:
		pointsNeeded = 2;
		break;
	}

	points = new (std::nothrow) Point[pointsNeeded];
}

Task::~Task()
{
	delete [] points;
}

void Task::Draw()
{
	switch (taskNumber)
	{
	case 1: Draw1();
		break;
	}
}

void Task::addPoint(int x, int y)
{
	pointsNeeded--;
	points[pointsNum] = Point(x, y);
	pointsNum++;
}

void Task::Draw1()
{
	//draw circle
}
