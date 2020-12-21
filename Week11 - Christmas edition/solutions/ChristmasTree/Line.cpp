#include "Line.h"
#include <cmath>

Line::Line(SDL_Renderer* _renderer, const Color _c, const Point& _a, const Point& _b) : Drawable(_renderer, _c), a(_a), b(_b), color(_c)
{
}

void Line::draw()
{
	colorize();
	double length = sqrt((b.getX() - a.getX()) * (b.getX() - a.getX()) + (b.getY() - a.getY()) * (b.getY() - a.getY())),
		dx = (b.getX() - a.getX()) / length,
		dy = (b.getY() - a.getY()) / length,
		currentX = a.getX(),
		currentY = a.getY();

	for (int i = 0; i < length; i++)
	{
		drawPixel((int)currentX, (int)currentY)
		currentX += dx;
		currentY += dy;
	}
}

Line::~Line() = default;

