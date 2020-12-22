#pragma once
#include "Object.h"
class Circle :
    public Object
{
private:
    void computeBounds();
    SDL_Rect bounds;
    SDL_Point centre;
    Color color;
    unsigned int radius;
    SDL_Renderer* renderer;

public:
    Circle(SDL_Renderer* , SDL_Point centre, unsigned int radius, Color color);
    ~Circle();

    SDL_Rect getBounds();
    void translate(SDL_Point);
    void scale(std::pair<double, double>);

    bool Render();
};

