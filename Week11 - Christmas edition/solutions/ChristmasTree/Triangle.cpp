#pragma once
#include "Triangle.h"
#include "Line.h"

Triangle::Triangle(SDL_Renderer* _renderer, const Color& _color, std::vector<Point> _points) : Drawable(_renderer, _color), points(_points)
{
}

void Triangle::transformPoints(Transformation transformation)
{
	for(Point& point : points)
	{
		transformation.transform(point);
	}
}

void Triangle::draw()
{
	Line a = Line(getRenderer(), getColor(), points[0], points[1]),
		b = Line(getRenderer(), getColor(), points[1], points[2]),
		c = Line(getRenderer(), getColor(), points[2], points[0]);
	a.draw();
	b.draw();
	c.draw();
}

Triangle::~Triangle() = default;
