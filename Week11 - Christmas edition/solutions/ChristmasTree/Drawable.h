#pragma once
#include <SDL_render.h>
#include "Color.h"

class Drawable
{
private:
	SDL_Renderer* SDLRender;
	Color color;
public:
	Drawable(SDL_Renderer* _renderer, Color _color = Color(0, 0, 0));
	SDL_Renderer* getRenderer();
	Color getColor() const;
	void colorize();
	virtual void draw() = 0;
	virtual ~Drawable();
};

#define setColor(r,g,b) SDL_SetRenderDrawColor(getRenderer(),r,g,b,SDL_ALPHA_OPAQUE);
#define drawPixel(x,y) SDL_RenderDrawPoint(getRenderer(),x,y);
#define drawLine(x1,y1,x2,y2) SDL_RenderDrawLine(getRenderer(),x1,y1,x2,y2);