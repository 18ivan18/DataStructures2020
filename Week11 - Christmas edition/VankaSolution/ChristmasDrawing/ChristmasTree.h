#pragma once
#include "Object.h"
#include "FilledPolygon.h"
class ChristmasTree :
    public Object
{
private:
	FilledPolygon body;
	//Transformation bodyTransformation;
	FilledPolygon trunk;
	int bodySize; 
	SDL_Renderer* renderer; 
	SDL_Point translateVector;
	std::pair<double, double> scale;
public:
	ChristmasTree(SDL_Renderer*, const FilledPolygon&, const int, const std::pair<double, double>&, const SDL_Point&, const FilledPolygon&);
	bool Render();
	void translate(SDL_Point);
};

