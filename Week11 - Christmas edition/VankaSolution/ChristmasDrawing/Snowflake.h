#pragma once
#include "Object.h"
class Snowflake :
    public Object
{
private:
    SDL_Renderer* renderer;
    SDL_Point centre;
    SDL_Rect bounds;
    void computeBounds();
public:
    Snowflake(SDL_Renderer* renderer, SDL_Point centre);
    bool Render() ;
    void translate(SDL_Point);
    SDL_Rect getBounds();
};

