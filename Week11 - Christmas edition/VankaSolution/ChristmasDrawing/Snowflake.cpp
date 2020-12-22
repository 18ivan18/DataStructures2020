#include "Snowflake.h"

void Snowflake::computeBounds()
{
	bounds.x = centre.x - 4;
	bounds.y = centre.y - 4;
	bounds.w = 9;
	bounds.h = 9;
}

Snowflake::Snowflake(SDL_Renderer* renderer, SDL_Point centre): renderer(renderer), centre(centre)
{
	computeBounds();
}

bool Snowflake::Render()
{
	if (!renderer) return false;

	SDL_SetRenderDrawColor(renderer, 255, 250, 250, SDL_ALPHA_OPAQUE);
	for (int x = -4; x < 5; x++)
	{
		for (int y = -4; y < 5; y++)
		{
			if(x == y || x == 5 - y || y == 0 || x == 0){
				SDL_RenderDrawPoint(renderer, x + centre.x, y + centre.y);
			}
		}
	}
	return true;
}

void Snowflake::translate(SDL_Point vec)
{
	centre.x += vec.x;
	centre.y += vec.y;

	bounds.x += vec.x;
	bounds.y += vec.y;
}

SDL_Rect Snowflake::getBounds()
{
	return bounds;
}

