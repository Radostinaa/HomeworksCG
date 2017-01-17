#include "Task1.h"

Task1::~Task1()
{
	SDL_FreeSurface(info1);
	SDL_FreeSurface(info2);
}

void Task1::BresenhamLine(Point p1, Point p2)
{
	int x, y;
	int dx = abs(p2.x - p1.x);
	int  dy = abs(p2.y - p1.y);
	bool reverse = dx < dy;
	if (reverse)
	{
		int d = p1.x; p1.x = p1.y; p1.y = d;
		d = p2.x; p2.x = p2.y; p2.y = d;
		d = dx; dx = dy; dy = d;
	}
	int incUp = -2 * dx + 2 * dy;
	int incDn = 2 * dy;
	int incX = (p1.x <= p2.x) ? 1 : -1;
	int incY = (p1.y <= p2.y) ? 1 : -1;

	int d = -dx + 2 * dy;
	x = p1.x;
	y = p1.y;
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

void Task1::RoundingLine(Point p1, Point p2)
{
	int dx = abs(p2.x - p1.x);
	int dy = abs(p2.y - p1.y);
	bool reverse;
	if (reverse = (dx < dy)) {
		int d = p1.x; p1.x = p1.y; p1.y = d;
		d = p2.x; p2.x = p2.y; p2.y = d;
		d = dx; dx = dy; dy = d;
	}
	int incX = (p1.x <= p2.x) ? 1 : -1;
	float incY = ((float)dy )/ (float)dx;
	int x = p1.x;
	float y = p1.y;
	int n = dx + 1;
	while (n--) {
		if (reverse) Point((int)y, x).draw(renderer, color, true);
		else Point(x, (int)y).draw(renderer, color, true);
		x += incX;
		y += incY;
	}
}

void Task1::Draw()
{
	points[0].toCustom(); // p1
	points[1].toCustom(); // p2

	if (isBresenham)
	{
		color = { 255 ,100 ,34 ,1 };
		BresenhamLine(points[0], points[1]);
	}
	else
	{
		color = { 0 ,255 ,0 ,1 };
		RoundingLine(points[0], points[1]);
	}

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


