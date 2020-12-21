#include "Transformation.h"

Transformation::Transformation(const double& _scaleX, const double& _scaleY, const double& _translateX, const double& _translateY) :
	scaleX(_scaleX), scaleY(_scaleY), translateX(_translateX), translateY(_translateY)
{
}

double Transformation::getScaleX() const
{
	return this->scaleX;
}

double Transformation::getScaleY() const
{
	return this->scaleY;
}

double Transformation::getTranslateX() const
{
	return this->translateX;
}

double Transformation::getTranslateY() const
{
	return this->translateY;
}

void Transformation::transform(Point& point)
{
	point.setX(this->scaleX * point.getX() + this->translateX);
	point.setY(this->scaleY * point.getY() + this->translateY);
}
