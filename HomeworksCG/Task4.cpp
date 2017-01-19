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
		BresenhamLine(points[2], points[3],color);
		color = colorIn;
		Clip(points[0], points[1], points[2], points[3]);

		deletePoints();
		resetPoints();
		pointsNeeded = 2;
		rectDrawn = false;
	}
}


void Task4::Clip(Point rect1, Point rect2, Point po1, Point po2)
{
	float po1x = po1.x, po1y = po1.y, po2x = po2.x, po2y = po2.y;
	float dx = po2.x - po1.x;
	float dy = po2.y - po1.y;
	float tin = 0;
	float tout = 1;
	int xMin = std::min(rect1.x, rect2.x);
	int xMax = std::max(rect1.x, rect2.x);
	int yMin = std::min(rect1.y, rect2.y);
	int yMax = std::max(rect1.y, rect2.y);


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


					BresenhamLine(Point(po1x, po1y), Point(po2x, po2y),color);
				}

}

bool Task4::CalcT(float r, float q, float* tin, float* tout)
{
	float t;
	if (r > 0)
	{
		t = q / r;
		if (t < *tin) return false;
		*tout = std::min(t, *tout);
	}
	else if (r < 0)
	{
		t = q / r;
		if (t > *tout) return true;
		*tin = std::max(t, *tin);
	}
	else if (q < 0) return false;
	return true;
}

void Task4::drawRect()
{
	BresenhamLine(points[0], Point(points[1].x, points[0].y),color);
	BresenhamLine(Point(points[1].x, points[0].y), points[1], color);
	BresenhamLine(points[1], Point(points[0].x, points[1].y), color);
	BresenhamLine(Point(points[0].x, points[1].y), points[0],color);
}

