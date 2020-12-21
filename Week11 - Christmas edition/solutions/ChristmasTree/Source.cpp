#include <iostream>
#include "mygraphics.h"
#include "Color.h"
#include "Point.h"
#include <vector>
#include "ChristmasTree.h"
#include "Square.h"
#include "Transformation.h"
#include "Triangle.h"


int main(int argc, char* argv[])
{
	Color green(0, 255, 0);
	Color trunkColor(160, 82, 42);
	Transformation transformation (0.8, 0.8, 60, -40 );
	
	std::vector<Point> trianglePoints;
	trianglePoints.push_back(Point(SDLRen, green,   0, 550));
	trianglePoints.push_back(Point(SDLRen, green, 600, 550));
	trianglePoints.push_back(Point(SDLRen, green, 300, 250));
	
	Triangle triangle(SDLRen, green, trianglePoints);
	Square square(SDLRen, trunkColor,275, 550, 50);
	ChristmasTree tree(SDLRen, triangle, 4, transformation, square);
	
	tree.draw();
	
	updateGraphics()
	std::cout << "Press any key to continue...";
	
	std::cin.get();
	return 0;
}
