#ifndef FILLED_POLYGON
#define FILLED_POLYGON
#include "Object.h"
#include <vector>
class FilledPolygon :
    public Object
{
private:
	void computeBounds(); 
	std::vector<SDL_Point> vertexList; 
	SDL_Renderer* renderer; 
	Color color;
	SDL_Rect bounds;
public:
	FilledPolygon(SDL_Renderer* renderer, std::vector<SDL_Point> vertexList, Color color);
	SDL_Rect getBounds();
	void translate(SDL_Point);
	void scale(std::pair<double, double>);
	bool Render();
};


#endif // !FILLED_POLYGON

