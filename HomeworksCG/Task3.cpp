#include "Task3.h"

Task3::~Task3()
{
	delete[] filledPixels;
}

void Task3::Draw()
{
	if (edges < 3) 
	{
		edges++;
		drawside();
		pointsNeeded = 1; // next side
	}
	else 
	{
		BoundryFill(points[4]);
		edges = 0;
		deletePoints();
		resetPoints();
		pointsNeeded = 2;
	}


}

bool Task3::freePixel(Point p)
{
	return filledPixels[p.x + p.y*w].x == -1;
}

void Task3::BoundryFill(Point point)
{
	if (freePixel(point))
	{
		if (point.x < (w / 3) && point.x >= 0 && point.y < (h / 3) && point.y >= 0)
		{
			point.draw(renderer, colorFill, true);
		
			filledPixels[point.x + point.y*w] = Pixel(point.x, point.y, colorFill);
			SDL_Delay(2);
			BoundryFill(Point(point.x - 1, point.y));
			BoundryFill(Point(point.x + 1, point.y));
			BoundryFill(Point(point.x, point.y + 1));
			BoundryFill(Point(point.x, point.y - 1));
		}
	}
}

void Task3::drawside() 
{
	if(edges == 3)
	{
		BresenhamLine(points[edges - 1], points[edges]);
		BresenhamLine(points[edges], points[0]);
	}
	else
		BresenhamLine(points[edges-1], points[edges]);
}

void Task3::BresenhamLine(Point p1, Point p2)
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
		if (reverse) 
		{
			Point(y, x).draw(renderer, colorSides, true);
			if(x < h && y < w)
				filledPixels[y + x*w] = Pixel(y, x, colorSides);
		}
		else
		{
			Point(x, y).draw(renderer, colorSides, true);
			if (x < w && y < h)
				filledPixels[x + y*w] = Pixel(x, y, colorSides);
		}

		x += incX;
		if (d > 0)
		{
			d += incUp;
			y += incY;
		} else d += incDn;
	}
}