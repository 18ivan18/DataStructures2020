#pragma once
#include "Point.h"

Point::Point(SDL_Renderer* _renderer, const Color& _color, double _x, double _y) :
	Drawable(_renderer, _color), x(_x), y(_y)
{
}

void Point::setX(double _x)
{
	this->x = _x;
}

void Point::setY(double _y)
{
	this->y = _y;
}

double Point::getX() const
{
	return this->x;
}

double Point::getY() const
{
	return this->y;
}

void Point::draw()
{
	colorize();
	drawPixel((int)this->x, (int)this->y);
}

Point::~Point() = default;
