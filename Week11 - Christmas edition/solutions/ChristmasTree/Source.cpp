#include <iostream>
#include "mygraphics.h"
#include "Color.h"
#include "Point.h"
#include <vector>
#include "ChristmasTree.h"
#include "Square.h"
#include "Triangle.h"


int main(int argc, char* argv[])
{
	
	Transformation transformation { 0.8, 0.8, 60, -40 };
	Color green(0, 255, 0);
	std::vector<Point> trianglePoints;
	trianglePoints.push_back(Point(SDLRen, 0, 550, green));
	trianglePoints.push_back(Point(SDLRen, 600, 550, green));
	trianglePoints.push_back(Point(SDLRen, 300, 250, green));
	
	Triangle triangle(SDLRen, trianglePoints, Color( 0, 255, 0 ));
	Square square(SDLRen, 275, 550, 50, 160, 82, 42);
	ChristmasTree tree(SDLRen, triangle, 4, transformation, square);
	
	tree.draw();
	
	updateGraphics()
	std::cout << "Press any key to continue...";
	
	std::cin.get();
	return 0;
}
