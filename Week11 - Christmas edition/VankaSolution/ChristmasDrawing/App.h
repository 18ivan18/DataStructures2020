#ifndef APP
#define APP
#include <SDL.h>
#include <string>
#include <vector>
#include "ChristmasTree.h"

class App
{
private:
	bool isRunning;
	SDL_Window* window;
	SDL_Renderer* renderer;
	std::vector<Object*> objectList;
	std::vector<SDL_Point> vectorList;
	std::vector<std::pair<double, double>> scaleVectorList;
	ChristmasTree *tree;

	static const std::string WINDOW_NAME;
	static const int WIDTH;
	static const int HEIGHT;
public:
	App();

	int onExecute();
	bool onInit();
	void onEvent(SDL_Event*);
	void onLoop();
	void onRender();
	void onExit();

};

#endif // !APP


