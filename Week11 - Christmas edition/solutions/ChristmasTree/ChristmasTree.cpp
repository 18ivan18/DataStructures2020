#pragma once
#include "ChristmasTree.h"

ChristmasTree::ChristmasTree(SDL_Renderer* _renderer, const Triangle& _body, const int& _bodySize, const Transformation& _bodyTransformation, const Square& _trunk) :
	IDrawable(_renderer), body(_body), bodySize(_bodySize), bodyTransformation(_bodyTransformation), trunk(_trunk)
{
}

void ChristmasTree::draw()
{
	for(int i = 0; i < bodySize; i++)
	{
		body.draw();
		body.transform(bodyTransformation);
	}

	trunk.draw();
}
