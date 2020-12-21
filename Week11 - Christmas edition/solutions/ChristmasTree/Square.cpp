#pragma once
#include "Square.h"
#include "Line.h"

Square::Square(SDL_Renderer* _renderer, const Color& _color, double _x, double _y, int _side) :
		Point(_renderer, _color, _x, _y), side(_side)
{
}

void Square::draw()
{
	Point topRight = Point(getRenderer(), getColor(),this->getX() + side, this->getY()),
		botLeft = Point(getRenderer(), getColor(), this->getX(), this->getY() + side),
		botRight = Point(getRenderer(), getColor(), this->getX() + side, this->getY() + side);

	Line top = Line(getRenderer(), getColor() , *this, topRight),
		left = Line(getRenderer() , getColor() , *this, botLeft),
		bot = Line(getRenderer(), getColor(), botLeft, botRight),
		right = Line(getRenderer(), getColor(), botRight, topRight);

	top.draw();
	left.draw();
	bot.draw();
	right.draw();
}

Square::~Square() = default;
