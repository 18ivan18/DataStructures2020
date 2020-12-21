#pragma once
#include "Color.h"

Color::Color() : r(0), g(0), b(0)
{
}

Color::Color(unsigned char _r, unsigned char _g, unsigned char _b) :
	r(_r), g(_g), b(_b)
{
}

Color::Color(const Color& other)
{
	this->r = other.r;
	this->g = other.g;
	this->b = other.b;
}

unsigned char Color::getR() const
{
	return this->r;
}

unsigned char Color::getG() const
{
	return this->g;
}

unsigned char Color::getB() const
{
	return this->b;
}
