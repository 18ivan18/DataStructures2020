#pragma once
#include "Point.h"

class Square : public Point
{
private:
	int side;
public:
	Square(SDL_Renderer* _renderer, double _x, double _y, int _side, unsigned char _r, unsigned char _g, unsigned char _b);
	void draw() override;
	~Square() override;
};

