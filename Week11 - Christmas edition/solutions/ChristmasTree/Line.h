#pragma once
#include "Point.h"

class Line : public IDrawable
{
private:
	Point a;
	Point b;
	Color color;
public:
	Line(SDL_Renderer* _renderer, const Point& _a, const Point& _b, Color _c);
	void draw() override;
	~Line() override;
};

