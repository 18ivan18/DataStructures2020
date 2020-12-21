#pragma once
#include "Point.h"

class Line : public Drawable
{
private:
	Point a;
	Point b;
	Color color;
public:
	Line(SDL_Renderer* _renderer, const Color _c, const Point& _a, const Point& _b);
	void draw() override;
	~Line() override;
};

