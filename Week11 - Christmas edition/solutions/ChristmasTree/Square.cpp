#pragma once
#include "Square.h"
#include "Line.h"

Square::Square(SDL_Renderer* _renderer, double _x, double _y, int _side, unsigned char _r, unsigned char _g, unsigned char _b) :
		Point(_renderer, _x, _y, Color(_r, _g, _b)), side(_side)
{
}

void Square::draw()
{
	Point topRight = Point(getRenderer(),this->getX() + side, this->getY(), getColor()),
		botLeft = Point(getRenderer(), this->getX(), this->getY() + side, getColor()),
		botRight = Point(getRenderer(), this->getX() + side, this->getY() + side, getColor());

	Line top = Line(getRenderer(), *this, topRight, getColor()),
		left = Line(getRenderer() , *this, botLeft, getColor()),
		bot = Line(getRenderer(), botLeft, botRight, getColor()),
		right = Line(getRenderer(), botRight, topRight, getColor());

	top.draw();
	left.draw();
	bot.draw();
	right.draw();
}

Square::~Square() = default;
