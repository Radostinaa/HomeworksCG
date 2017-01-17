#include "Task1.h"
#include <new>


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

	Point(center.x, center.y + radius).draw(renderer, color, true);
	Point(center.x, center.y + radius).draw(renderer, color, true);
	Point(center.x, center.y - radius).draw(renderer, color, true);
	Point(center.x + radius, center.y).draw(renderer, color, true);
	Point(center.x - radius, center.y).draw(renderer, color, true);

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
	Point(center.x, center.y + radius).draw(renderer, color, true);
	Point(center.x + radius, center.y).draw(renderer, color, true);
	Point(center.x, center.y - radius).draw(renderer, color, true);
	Point(center.x - radius, center.y).draw(renderer, color, true);
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
	Point(center.x + x, center.y + y).draw(renderer, color, true);
	Point(center.x - x, center.y - y).draw(renderer, color, true);
	Point(center.x - x, center.y + y).draw(renderer, color, true);
	Point(center.x + x, center.y - y).draw(renderer, color, true);
}

void Task1::EightSymmetric(Point center, int x, int y, int radius)
{
	FourSymmetric(center, x, y, radius);
	FourSymmetric(center, y, x, radius);
}

Task1::~Task1()
{
	SDL_FreeSurface(info1);
	SDL_FreeSurface(info2);
}

void Task1::Draw()
{
	points[0].toCustom(); // center
	points[1].toCustom(); // p2
	int radius = distance(points[0], points[1]);

	/*if (isBresenham)
	{
		color = { 256 ,100 ,34 ,1};
		drawBresenhamCircle(points[0], radius);
	}
	else
	{*/
	color = { 0 ,255 ,0 ,1 };
	SimpleCircle(points[0], radius);
	//}

	isBresenham = isBresenham ? 0 : 1;
	deletePoints();
	reset();
}

void Task1::drawInfo(SDL_Window* window, SDL_Surface* screen, TTF_Font* font)
{
	if (info1 == NULL)
	{
		info1 = TTF_RenderText_Solid(font, "Bresenham", { 255 ,100 ,34 ,1 });
		info2 = TTF_RenderText_Solid(font, "SimpleCircle", { 0 ,255 ,0 ,1 });
	}

	pos1.x = 10;
	pos1.y = 10;
	pos2.x = 20 + info1->clip_rect.w;
	pos2.y = 10;

	SDL_BlitSurface(info1, NULL, screen, &pos1);
	SDL_BlitSurface(info2, NULL, screen, &pos2);
	SDL_UpdateWindowSurface(window);
}

