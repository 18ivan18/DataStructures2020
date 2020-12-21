#pragma once
#include <SDL_render.h>

class IDrawable
{
private:
	SDL_Renderer* SDLRender;
public:
	IDrawable(SDL_Renderer* _renderer);
	SDL_Renderer* getRenderer();
	virtual void draw() = 0;
	virtual ~IDrawable();
};

#define setColor(r,g,b) SDL_SetRenderDrawColor(getRenderer(),r,g,b,SDL_ALPHA_OPAQUE);
#define drawPixel(x,y) SDL_RenderDrawPoint(getRenderer(),x,y);
#define drawLine(x1,y1,x2,y2) SDL_RenderDrawLine(getRenderer(),x1,y1,x2,y2);