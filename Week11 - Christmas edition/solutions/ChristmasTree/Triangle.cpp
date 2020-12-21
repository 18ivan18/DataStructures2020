#pragma once
#include "Triangle.h"
#include "Line.h"

Triangle::Triangle(SDL_Renderer* _renderer, std::vector<Point> _points, Color _color) : IDrawable(_renderer), points(_points), color(_color)
{
}

void Triangle::transform(Transformation transformation)
{
	for(Point& point : points)
	{
		point.transform(transformation);
	}
}

void Triangle::draw()
{
	Line a = Line(getRenderer(), points[0], points[1], color),
		b = Line(getRenderer(), points[1], points[2], color),
		c = Line(getRenderer(), points[2], points[0], color);
	a.draw();
	b.draw();
	c.draw();
}

Triangle::~Triangle() = default;
