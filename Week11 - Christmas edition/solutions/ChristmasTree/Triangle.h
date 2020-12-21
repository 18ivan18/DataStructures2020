#pragma once
#include <vector>
#include "Point.h"

class Triangle : public IDrawable
{
private:
	std::vector<Point> points;
	Color color;
public:
	Triangle(SDL_Renderer* _renderer, std::vector<Point> _points, Color _color);
	void transform(Transformation transformation);
	void draw() override;
	~Triangle() override;
};

