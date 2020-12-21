#pragma once
#include "Point.h"

Point::Point(SDL_Renderer* _renderer, double _x, double _y, const Color& _color) :
	IDrawable(_renderer), x(_x), y(_y), color(_color)
{
}

double Point::getX() const
{
	return this->x;
}

double Point::getY() const
{
	return this->y;
}

Color Point::getColor() const
{
	return this->color;
}

void Point::transform(const Transformation& transformation)
{
	this->x = transformation.scaleX * this->x + transformation.translateX;
	this->y = transformation.scaleY * this->y + transformation.translateY;
}

void Point::colorize()
{
	setColor(color.getR(), color.getG(), color.getB())
}

void Point::draw()
{
	colorize();
	drawPixel((int)this->x, (int)this->y);
}

Point::~Point() = default;
