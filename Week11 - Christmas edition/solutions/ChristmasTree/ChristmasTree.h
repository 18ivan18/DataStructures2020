#pragma once
#include "Square.h"
#include "Triangle.h"

class ChristmasTree : public IDrawable
{
private:
	Triangle body;
	Transformation bodyTransformation;
	Square trunk;
	int bodySize;
public:
	ChristmasTree(SDL_Renderer* _renderer, const Triangle& _body, const int& _bodySize, const Transformation& _bodyTransformation, const Square& _trunk);
	void draw() override;
};

