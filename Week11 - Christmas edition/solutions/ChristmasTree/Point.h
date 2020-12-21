#pragma once
#include "Color.h"
#include "Drawable.h"

class Point : public Drawable
{
private:
	double x;
	double y;
public:
	Point(SDL_Renderer* _renderer, const Color& _color, double _x, double _y);
	void setX(double _x);
	void setY(double _y);
	double getX() const;
	double getY() const;
	void draw() override;
	~Point() override;
};

