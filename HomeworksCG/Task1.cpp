#include "Task1.h"
#include <new>

//void Task1::addPoint(int x, int y)
//{
//	pointsNeeded--;
//	points[pointsNum] = Point(x, y);
//	pointsNum++;
//}


//Task1::Task1(SDL_Renderer* r)
//{
//	renderer = r;
//	reset();
//}

//Task1::~Task1()
//{
//	deletePoints();
//}
//void Task1::deletePoints()
//{
//	delete[] points;
//}

//void Task1::reset()
//{
	//pointsNum = 0;
	//pointsNeeded = 2;
	//points = new (std::nothrow) Point[pointsNeeded];
	
//}
int distance(Point p1, Point p2) 
{
	return sqrt((p1.x - p2.x)*(p1.x - p2.x) + (p1.y - p2.y)*(p1.y - p2.y));
}

void Task1::drawBresenhamCircle(Point center, int radius)
{
	int x, y, d;

	x = 0;
	y = radius;
	d = 3 - 2 * radius;

	Point(center.x, center.y + radius).draw(renderer, true);
	Point(center.x, center.y + radius).draw(renderer, true);
	Point(center.x, center.y - radius).draw(renderer, true);
	Point(center.x + radius, center.y).draw(renderer, true);
	Point(center.x - radius, center.y).draw(renderer, true);

	while (1)
	{
		if (d > -y)
		{
			y--;
			d += 1 - 2 * y;
		}
		if (d >= x)
		{
			x++;
			d += 1 + 2 * x;
		}
		if (x < y) return;
		FourSymmetric(center, x, y, radius);
	}
}

void Task1::SimpleCircle(Point center, int radius)
{
	int x, y;
	x = 0;
	y = radius;
	Point(center.x, center.y + radius).draw(renderer, true);
	Point(center.x + radius, center.y).draw(renderer, true);
	Point(center.x, center.y - radius).draw(renderer, true);
	Point(center.x - radius, center.y).draw(renderer, true);
	while (x < y)
	{
		x++;
		y = (int)sqrt((double)(radius*radius - x*x));
		EightSymmetric(center, x, y, radius);
	}
	if (x == y) FourSymmetric(center, x, y, radius);
}

void Task1::FourSymmetric(Point center, int x, int y, int radius)
{
	Point(center.x + x, center.y + y).draw(renderer, true);
	Point(center.x - x, center.y - y).draw(renderer, true);
	Point(center.x - x, center.y + y).draw(renderer, true);
	Point(center.x + x, center.y - y).draw(renderer, true);
}

void Task1::EightSymmetric(Point center, int x, int y, int radius)
{
	FourSymmetric(center, x, y, radius);
	FourSymmetric(center, y, x, radius);
}

void Task1::Draw()
{
	points[0].toCustom(); // center
	points[1].toCustom(); // p2
	int radius = distance(points[0], points[1]);

	if(isBresenham) drawBresenhamCircle(points[0], radius);
	else SimpleCircle(points[0], radius);

	isBresenham = isBresenham ? 0 : 1;
	deletePoints();
	reset();
}
