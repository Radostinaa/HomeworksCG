#include "Point.h"

Point::Point(int _x, int _y)
{
	x = _x;
	y = _y;
}

void Point::toReal()
{
	x = x * 2;
	y = y * 2;
}

void Point::toCustom()
{
	x = x / 2;
	y = y / 2;
}

void Point::draw(SDL_Renderer * r, SDL_Color c, bool isCustom)
{
	if (isCustom)
		toReal();
	SDL_SetRenderDrawColor(r, c.r, c.g, c.b, c.a);

	SDL_RenderDrawPoint(r, x, y);
	SDL_RenderDrawPoint(r, x + 1, y);
	SDL_RenderDrawPoint(r, x, y + 1);
	SDL_RenderDrawPoint(r, x + 1, y + 1);
	SDL_RenderPresent(r);
}
