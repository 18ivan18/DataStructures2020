#pragma once
#include "Point.h"

class Square : public Point
{
private:
	int side;
public:
	Square(SDL_Renderer* _renderer, const Color& _color, double _x, double _y, int _side);
	void draw() override;
	~Square() override;
};

