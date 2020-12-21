#pragma once
#include <vector>
#include "Point.h"
#include "Transformation.h"

class Triangle : public Drawable
{
private:
	std::vector<Point> points;
public:
	Triangle(SDL_Renderer* _renderer, const Color& _color, std::vector<Point> _points);
	void transformPoints(Transformation transformation);
	void draw() override;
	~Triangle() override;
};

