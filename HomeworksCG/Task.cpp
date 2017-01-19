#include "Task.h"

Task::Task(SDL_Renderer * r, int pNeeded)
{
	pn = pNeeded;
	renderer = r;
	resetPoints();
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
	points = new Point[pointsNeeded];
}

void Task::deletePoints()
{
	delete[] points;
}

void Task::BresenhamLine(Point from, Point to, SDL_Color color)
{
	int x, y;
	int dx = abs(to.x - from.x);
	int  dy = abs(to.y - from.y);
	bool reverse = dx < dy;
	if (reverse)
	{
		int d = from.x; from.x = from.y; from.y = d;
		d = to.x; to.x = to.y; to.y = d;
		d = dx; dx = dy; dy = d;
	}
	int incUp = -2 * dx + 2 * dy;
	int incDn = 2 * dy;
	int incX = (from.x <= to.x) ? 1 : -1;
	int incY = (from.y <= to.y) ? 1 : -1;

	int d = -dx + 2 * dy;
	x = from.x;
	y = from.y;
	int n = dx + 1;
	while (n--)
	{
		if (reverse) Point(y, x).draw(renderer, color, true);
		else Point(x, y).draw(renderer, color, true);

		x += incX;
		if (d > 0)
		{
			d += incUp;
			y += incY;
		}
		else d += incDn;
	}
}