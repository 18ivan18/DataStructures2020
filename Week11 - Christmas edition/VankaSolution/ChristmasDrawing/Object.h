#ifndef OBJECT
#define OBJECT
#include <SDL.h>
#include "Color.h"
#include <utility>

class Object
{
private:
	Color color;
public:
	Object();
	~Object();

	bool setColor(Color);
	Color GetColor();
	virtual SDL_Rect getBounds();
	virtual bool Render() = 0;
	// 2 dimentional vector
	virtual void translate(SDL_Point);
	// 2 dimentional vector
	virtual void scale(std::pair<double, double>);
};
#endif // !OBJECT


