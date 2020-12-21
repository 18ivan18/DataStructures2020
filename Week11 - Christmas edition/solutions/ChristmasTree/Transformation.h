#pragma once
#include "Point.h"

class Transformation
{
private:
	double scaleX;
	double scaleY;
	double translateX;
	double translateY;
public:
	Transformation(const double& _scaleX, const double& _scaleY, const double& _translateX, const double& _translateY);

	double getScaleX() const;
	double getScaleY() const;
	double getTranslateX() const;
	double getTranslateY() const;

	void transform(Point& point);
};

