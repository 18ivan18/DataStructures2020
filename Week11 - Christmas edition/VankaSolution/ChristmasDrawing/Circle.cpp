#include "Circle.h"

void Circle::computeBounds()
{
	int left = centre.x - radius;
	int top = centre.y - radius;
	int width = 2 * radius;
	int height = 2 * radius;
	bounds.x = left;
	bounds.y = top;
	bounds.w = width;
	bounds.h = height;
}

Circle::Circle(SDL_Renderer* renderer, SDL_Point centre, unsigned int radius, Color color): renderer(renderer), centre(centre), radius(radius), color(color)
{
	computeBounds();
}

Circle::~Circle()
{
}

SDL_Rect Circle::getBounds()
{
	return bounds;
}

void Circle::translate(SDL_Point vector)
{
	centre.x += vector.x;
	centre.y += vector.y;

	bounds.x += vector.x;
	bounds.y += vector.y;
}

void Circle::scale(std::pair<double, double> vector)
{
	centre.x *= vector.first;
	centre.y *= vector.second;

	bounds.x *= vector.first;
	bounds.y *= vector.second;
}

bool Circle::Render()
{
	if (!renderer) return false;
	int r = color.r;
	int g = color.g;
	int b = color.b;
	SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);

	// TODO: should check if all of these variables are between 0 and renderer width and height
	int sX = bounds.x;
	int sY = bounds.y;
	int eX = bounds.x + bounds.w;
	int eY = bounds.x + bounds.h;
	int cX = centre.x;
	int cY = centre.y;
	//int rendererWidth, rendererHeight;
	//SDL_GetRendererOutputSize(renderer, &rendererWidth, &rendererHeight);
	for (int x = sX; x < eX; x++)
	{
		for (int y = sY; y < eY; y++)
		{
			int circleV = (x - cX) * (x - cX) + (y - cY) * (y - cY) - radius * radius;
			if (circleV <= 0) {
				SDL_RenderDrawPoint(renderer, x, y);
			}
		}
	}
	return true;
}
