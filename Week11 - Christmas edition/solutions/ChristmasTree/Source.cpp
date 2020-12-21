#include <iostream>
#include "mygraphics.h"
#include <cmath>
#include <vector>

struct Point
{
	double x;
	double y;
};

struct Color
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

void colorize(Color color)
{
	setColor(color.r, color.g, color.b)
}

/*
Функция polygon (n,x,y,radius): Рисуване на многоъгълник
параметър n: брой върхове на многоъгълника
параметри x,y: координати на центъра на многоъгълника
параметър radius: разстояние от центъра до върховете
*/
void polygon(int n, double x, double y, double radius)
{
	for (int side = 0; side < n; side++)
	{
		drawLine(radius * cos(side * 2.0 * M_PI / n) + x, radius * sin(side * 2.0 * M_PI / n) + y,
			radius * cos((side + 1) * 2.0 * M_PI / n) + x, radius * sin((side + 1) * 2.0 * M_PI / n) + y)
	}
}

void DrawLine(Point start, Point end)
{
	//sqrt
	double length = sqrt((end.x - start.x) * (end.x - start.x) + (end.y - start.y) * (end.y - start.y)),
		dx = (end.x - start.x) / length,
		dy = (end.y - start.y) / length,
		currentX = start.x,
		currentY = start.y;

	for (int i = 0; i < length; i++)
	{
		drawPixel(currentX, currentY)
		currentX += dx;
		currentY += dy;
	}
}

void square(Point p, double diag, Color color)
{
	colorize(color);
	drawLine(diag * cos(-M_PI / 4) + p.x, diag * sin(-M_PI / 4) + p.y, diag * cos(M_PI / 4) + p.x, diag * sin(M_PI / 4) + p.y)
	drawLine(diag * cos(M_PI / 4) + p.x, diag * sin(M_PI / 4) + p.y, diag * cos(3 * M_PI / 4) + p.x, diag * sin(3 * M_PI / 4) + p.y)
	drawLine(diag * cos(3 * M_PI / 4) + p.x, diag * sin(3 * M_PI / 4) + p.y, diag * cos(5 * M_PI / 4) + p.x, diag * sin(5 * M_PI / 4) + p.y)
	drawLine(diag * cos(5 * M_PI / 4) + p.x, diag * sin(5 * M_PI / 4) + p.y, diag * cos(-M_PI / 4) + p.x, diag * sin(-M_PI / 4) + p.y)
}

void triangle(std::vector<Point> points, Color color)
{
	colorize(color);
	DrawLine(points[0], points[1]);
	DrawLine(points[1], points[2]);
	DrawLine(points[2], points[0]);
}

int main(int argc, char* argv[])
{
	/*

		setColor (0,255,0);
		DrawLine (200,200,0,150);
		setColor (255,255,255);
		for (int i = 0; i < 100; i++)
		{
			drawPixel (i,20);
		}
		setColor (255,0,0);
		for (int i = 0; i < 100; i++)
		{
			drawPixel (i,i);
		}
		setColor (255,255,0);
		for (int i = 0; i < 20; i++)
		{
			drawPixel (i*5,i*i);
			DrawLine (i*5,i*i,(i+1)*5,(i+1)*(i+1));
		}
		setColor (255,0,0);
	*/
	/*
	setColor(255, 255, 255)

	const double //scaleX: коефициент на скалиране по X
		scaleX = 40.0,
		//y0: ордината на началната точка
		y0 = 100,
		//scaleY: коефициент на скалиране по Y
		scaleY = 50.0,
		//stepX: стъпка за нарастване на аргумента
		stepX = 1;
	//nsegments: брой сегменти от кривата
	const int nsegments = 15;

	for (int i = 0; i < nsegments; i++)
	{
		double x = scaleX * i * stepX,
			xnext = scaleX * (i + 1) * stepX,
			y = y0 + scaleY * sin(stepX * i),
			ynext = y0 + scaleY * sin(stepX * (i + 1));

		setColor(255, 255, 255);
		drawLine(x, y, xnext, ynext);
		setColor(255, 0, 0);
		drawLine(x, y0, x, y);
	}
	setColor(255, 0, 0);
	drawLine(0, y0, 800, y0);
	*/
	/*
		for (int i = 0; i < 20; i++)
		{
			square (200,200,75,(M_PI/20)*i);
		}
		setColor (255,255,255);
		for (int i = 3; i < 20; i++)
		{
				polygon (i,200,200,50+5*i);
		}
	*/
	
	std::vector<Point> trianglePoints;
	trianglePoints.push_back(Point{ 0, 271 });
	trianglePoints.push_back(Point{ 600, 271 });	
	trianglePoints.push_back(Point{ 300, 0 });
	

	triangle(trianglePoints, Color{ 0, 255, 0 });

	
	square(Point{ 300, 300 }, 40, Color {160, 82, 42});

	//drawLine (0,0,100,100);

	//-------------------------------------
	updateGraphics()
	std::cout << "Press any key to continue...";
	
	std::cin.get();
	return 0;
}