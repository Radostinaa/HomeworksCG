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

void Point::draw(SDL_Renderer * r, bool isCustom)
{
	if (isCustom)
		toReal();
	SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0x00);

	SDL_RenderDrawPoint(r, x, y);
	SDL_RenderDrawPoint(r, x + 1, y);
	SDL_RenderDrawPoint(r, x, y + 1);
	SDL_RenderDrawPoint(r, x + 1, y + 1);
	SDL_RenderPresent(r);
}
