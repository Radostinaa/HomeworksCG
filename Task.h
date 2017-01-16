#pragma once
#include <SDL.h>

struct Point 
{
	int x, y;
	Point(int _x = 0, int _y = 0) : x(_x), y(_y) {}
};
class Task
{
public:
	Task(int taskNub, SDL_Window* w, SDL_Renderer *r);
	~Task();
	void Draw();
	int pointsNeeded;
	void addPoint(int x, int y);
private:
	SDL_Renderer *renderer;
	SDL_Window* window;
	int taskNumber;
	int pointsNum;
	void Draw1();
	Point* points;
};