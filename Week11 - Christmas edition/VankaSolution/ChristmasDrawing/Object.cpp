#include "Object.h"

Object::Object()
{
}

Object::~Object()
{
}

bool Object::setColor(Color color)
{
    this->color = color;
    return true;
}

Color Object::GetColor()
{
    return this->color;
}

SDL_Rect Object::getBounds()
{
    return SDL_Rect();
}

void Object::translate(SDL_Point)
{
}

void Object::scale(std::pair<double, double>)
{
}
