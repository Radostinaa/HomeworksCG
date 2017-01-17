#pragma once
#include<SDL.h>

class Point
{
public:
	int x, y;
	Point(int _x = 0, int _y = 0);
	void toReal();
	void toCustom();
	void draw(SDL_Renderer *r, bool isCustom);
};
