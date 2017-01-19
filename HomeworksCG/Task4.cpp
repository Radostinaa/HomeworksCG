#include "Task4.h"
#include <algorithm>

Task4::~Task4()
{
}

void Task4::Draw()
{
	if (!rectDrawn)
	{
		color = colorOut;
		drawRect();
		pointsNeeded = 2;
		rectDrawn = true;
	}
	else
	{
		BresenhamLine(points[2], points[3]);
		color = colorIn;
		Clip(points[0], points[1], points[2], points[3]);

		deletePoints();
		resetPoints();
		pointsNeeded = 2;
		rectDrawn = false;
	}
}


void Task4::Clip(Point p1, Point p2, Point po1, Point po2)
{
	float po1x = po1.x, po1y = po1.y, po2x = po2.x, po2y = po2.y;
	float dx = po2.x - po1.x;
	float dy = po2.y - po1.y;
	float tin = 0;
	float tout = 1;
	int xMin = std::min(p1.x, p2.x);
	int xMax = std::max(p1.x, p2.x);
	int yMin = std::min(p1.y, p2.y);
	int yMax = std::max(p1.y, p2.y);


	if (CalcT(dx, xMax - po1.x, &tin, &tout))
		if (CalcT(-dx, po1x - xMin, &tin, &tout))
			if (CalcT(dy, yMax - po1y, &tin, &tout))
				if (CalcT(-dy, po1y - yMin, &tin, &tout))
				{
					if (tout < 1)
					{
						po2x = po1x + tout*dx;
						po2y = po1y + tout*dy;
					}
					if (tin > 0)
					{
						po1x = po1x + tin*dx;
						po1y = po1y + tin*dy;
					}


					BresenhamLine(Point(po1x, po1y), Point(po2x, po2y));
				}

}

bool Task4::CalcT(float r, float q, float* tin, float* tout)
{
	float t;
	if (r > 0)
	{
		t = q / r;
		if (t < *tin) return 0;
		*tout = std::min(t, *tout);
	}
	else if (r < 0)
	{
		t = q / r;
		if (t > *tout) return 0;
		*tin = std::max(t, *tin);
	}
	else if (q < 0) return 0;
	return 1;
}

void Task4::drawRect()
{
	BresenhamLine(points[0], Point(points[1].x, points[0].y));
	BresenhamLine(Point(points[1].x, points[0].y), points[1]);
	BresenhamLine(points[1], Point(points[0].x, points[1].y));
	BresenhamLine(Point(points[0].x, points[1].y), points[0]);
}

void Task4::BresenhamLine(Point p1, Point p2)
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
