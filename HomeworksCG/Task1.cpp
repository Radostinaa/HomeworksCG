#include "Task1.h"

Task1::~Task1()
{
	SDL_FreeSurface(info1);
	SDL_FreeSurface(info2);
}


void Task1::RoundingLine(Point p1, Point p2)
{
	int x, z, i, h, v;
	float slope,y;
	bool sx, sy, reverse;
	h = abs(p2.x - p1.x); v = abs(p2.y - p1.y);
	sx = (p2.x < p1.x);
	sy = (p2.y < p1.y);
	if (h < v) {
		reverse = true;
		x = h;
		h = v;
		v = x;
	} else {
		reverse = false;
	}
	if (h == 0) {
		p1.draw(renderer, color, true);
		return;
	}
	slope = (float)v / (float)h;
	for (i = 0; i < h; ++i) {
		x = i; y = floor(slope * x + 0.5);
		if (reverse) {
			z = x; x = y; y = z;
		}
		if (sx) {
			x = (-x);
		}
		if (sy) {
			y = (-y);
		}
		Point(x + p1.x, y + p1.y).draw(renderer, color, true);
	}
}

void Task1::Draw()
{
	if (isBresenham)
	{
		color = { 255 ,100 ,34 ,1 };
		BresenhamLine(points[0], points[1],color);
	}
	else
	{
		color = { 0 ,255 ,0 ,1 };
		RoundingLine(points[0], points[1]);
	}

	isBresenham = !isBresenham;
	deletePoints();
	resetPoints();
}

void Task1::drawInfo(SDL_Window* window, SDL_Surface* screen, TTF_Font* font)
{
	if (info1 == NULL)
	{
		info1 = TTF_RenderText_Solid(font, "Bresenham", { 255 ,100 ,34 ,1 });
		info2 = TTF_RenderText_Solid(font, "Rounding", { 0 ,255 ,0 ,1 });
	}

	pos1.x = 10;
	pos1.y = 10;
	pos2.x = 20 + info1->clip_rect.w;
	pos2.y = 10;

	SDL_BlitSurface(info1, NULL, screen, &pos1);
	SDL_BlitSurface(info2, NULL, screen, &pos2);
	SDL_UpdateWindowSurface(window);
}


