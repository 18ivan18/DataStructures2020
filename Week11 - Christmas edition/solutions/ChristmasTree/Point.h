#pragma once
#include "Color.h"
#include "IDrawable.h"

struct Transformation
{
	double scaleX;
	double scaleY;
	double translateX;
	double translateY;
};

class Point : public IDrawable
{
private:
	double x;
	double y;
	Color color;
public:
	Point(SDL_Renderer* _renderer, double _x, double _y, const Color& _color = Color());
	double getX() const;
	double getY() const;
	Color getColor() const;
	void transform(const Transformation& transformation);
	void colorize();
	void draw() override;
	~Point() override;
};

