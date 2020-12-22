#include "FilledPolygon.h"
#include <climits>

void FilledPolygon::computeBounds()
{
	int minX = INT_MAX;
	int minY = INT_MAX;
	int maxX = INT_MIN;
	int maxY = INT_MIN;
	int x, y;
	for (auto currentPoint: vertexList)
	{
		x = currentPoint.x;
		y = currentPoint.y;
		if (x < minX) {
			minX= x;
		}
		if (y < minY) {
			minY = y;
		}
		if (x > maxX) {
			maxX = x;
		}
		if (y > maxY) {
			maxY = y;
		}
	}
	minX--;
	minY--;
	maxX++;
	maxY++;

	// top left
	bounds.x = minX;
	bounds.y = minY;
	bounds.w = maxX - minX;
	bounds.h = maxY - minY;
}

FilledPolygon::FilledPolygon(SDL_Renderer* renderer, std::vector<SDL_Point> vertexList, Color color):
	renderer(renderer), vertexList(vertexList), color(color)
{
	computeBounds();
}

SDL_Rect FilledPolygon::getBounds()
{
	return bounds;
}

void FilledPolygon::translate(SDL_Point vec)
{
	bounds.x += vec.x;
	bounds.y += vec.y;

	for (auto& point: vertexList)
	{
		point.x += vec.x;
		point.y += vec.y;
	}
}

void FilledPolygon::scale(std::pair<double, double> vec)
{
	bounds.x *= vec.first;
	bounds.y *= vec.second;

	for (auto& point : vertexList)
	{
		point.x *= vec.first;
		point.y *= vec.second;
	}
}

bool FilledPolygon::Render()
{
	if (!renderer) return false;	
	int r = color.r;
	int g = color.g;
	int b = color.b;
	SDL_SetRenderDrawColor(renderer, r, g, b, SDL_ALPHA_OPAQUE);
	int count;
	int n = vertexList.size();
	float u, v;
	int x1, y1;
	int x2, y2;
	int x3, y3;
	int x4, y4;
	int det;
	for (int x = 0; x < bounds.w; x++)
	{
		for (int y = 0; y < bounds.h; y++)
		{
			count = 0;
			for (int i = 0; i < n; i++)
			{
				x1 = x + bounds.x;
				y1 = y + bounds.y;
				x2 = bounds.w + bounds.x;
				y2 = y1;

				x3 = vertexList[i].x;
				y3 = vertexList[i].y;
				x4 = vertexList[(i + 1) % n].x;
				y4 = vertexList[(i + 1) % n].y;

				det = (x1 - x2) * (y4 - y3) - (x4 - x3) * (y1 - y2);

				if (det != 0) {
					u = (float)((y4 - y3) * (x1 - x3) + (x3 - x4) * (y1 - y3)) / (float)det;
					v = (float)((y2 - y1) * (x1 - x3) + (x1 - x2) * (y1 - y3)) / (float)det;

					if (u > 0.0 && u < 1.0 && v > 0.0 && v < 1.0) {
						count++;
					}
				}
			}

			if (count % 2) {
				SDL_RenderDrawPoint(renderer, x1, y1);
			}
		}
	}
	return true;
}
