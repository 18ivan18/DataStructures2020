#include "App.h"
#include "Circle.h"
#include "FilledPolygon.h"
#include "Snowflake.h"
#include <iostream>
const std::string App::WINDOW_NAME = "Merry Christmas";
const int App::WIDTH = 1280;
const int App::HEIGHT = 720;

App::App()
{
	isRunning = true;
	window = nullptr;
	renderer = nullptr;
}

int App::onExecute()
{
	SDL_Event e;
	if (onInit() == false) {
		return -1;
	}
	std::cout << "Starting SDL...\n";
	while (isRunning)
	{
		while (SDL_PollEvent(&e) != 0) {
			onEvent(&e);
		}
		onLoop();
		onRender();
	}
	onExit();
	return 0;
}

bool App::onInit()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		return false;
	}
	window = SDL_CreateWindow(WINDOW_NAME.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (window != nullptr) {
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	}
	else {
		return false;
	}
	//std::vector<SDL_Point> vertices;
	//vertices.push_back({ 0, 300 });
	//vertices.push_back({ 650, 300 });
	//vertices.push_back({ 325, 0 });
	//objectList.push_back(new Circle(renderer, SDL_Point{ 640, 360 }, 100, Color{ 255, 0, 0 }));
	//objectList.push_back(new FilledPolygon(renderer, vertices, Color{ 255, 69, 0 }));

	//vectorList.push_back({-1, 1});
	//vectorList.push_back({1, -1});
	//scaleVectorList.push_back({0.9, 0.8});
	//scaleVectorList.push_back({0.9, 0.9});

	Color green{ 34, 139, 34 };
	Color trunkColor{ 160, 82, 42 };
	SDL_Point translate{ 40 + HEIGHT / 8, -40 };
	std::pair<double, double> scale = { 0.8, 0.8 };

	std::vector<SDL_Point> trianglePoints;
	trianglePoints.push_back({ 0, 550 });
	trianglePoints.push_back({ 600, 550 });
	trianglePoints.push_back({ 300, 250 });

	//275, 550, 50
	std::vector<SDL_Point> squarePoints;
	squarePoints.push_back({ 275, 550 });
	squarePoints.push_back({ 325, 550 });
	squarePoints.push_back({ 325, 600 });
	squarePoints.push_back({ 275, 600 });

	FilledPolygon triangle(renderer, trianglePoints, green);
	FilledPolygon square(renderer, squarePoints, trunkColor);
	tree = new ChristmasTree(renderer, triangle, 4, scale, translate, square);
	tree->translate({ HEIGHT / 2, 0 });

	return true;
}

void App::onEvent(SDL_Event* e)
{
	if (e->type == SDL_QUIT) {
		isRunning = false;
	}
	/*if (e->type == SDL_MOUSEBUTTONDOWN) {
	}*/
}

// takes care of changes or modifications
void App::onLoop()
{
	if ((float)rand() / RAND_MAX < 0.7) {
		objectList.push_back(new Snowflake(renderer, SDL_Point{ rand() % WIDTH, rand() % 20}));
	}
	for (int i = 0; i < objectList.size(); i++)
	{
		SDL_Rect objBounds = objectList[i]->getBounds();

		if (objBounds.x < 0 || objBounds.x + objBounds.w > WIDTH || objBounds.y < 0 || objBounds.y + objBounds.h > HEIGHT) {
			delete objectList[i];
			objectList.erase(objectList.begin() + i);
		}
		else {
			objectList[i]->translate({ 1, 1 });
		}
	}
}

// just rendering
void App::onRender()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);
	tree->Render();
	for (const auto& currentObj: objectList)
	{
		currentObj->Render();
	}
	SDL_RenderPresent(renderer);

	SDL_Delay(5);
}

void App::onExit()
{
	delete tree;
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
}

