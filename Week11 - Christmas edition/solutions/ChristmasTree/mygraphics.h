/*
���������� ��� �� ������������� Visual Studio
� SDL2 ���� �� ������ ���:
http://www.willusher.io/sdl2%20tutorials/2013/08/15/lesson-0-visual-studio/
�� Linux & Mac ��������� ���������� Makefile.
� � ����� ������ � ���������� ����� ��
����������� SDL2.
*/

#ifndef __SDL_WRAPPER_
#define __SDL_WRAPPER_

#include <SDL.h>
#include <cassert>
#include <iostream>

//global variables for SLD window and renderer
SDL_Window* SDLWin = 0;
SDL_Renderer* SDLRen = 0;

void SDLStart() {
	std::cout << "Starting SDL...\n";

	assert(SDL_Init(SDL_INIT_VIDEO) == 0);

	SDLWin = SDL_CreateWindow("Merry Christmas!", 100, 100, 600, 600, SDL_WINDOW_SHOWN);
	assert(SDLWin != nullptr);

	SDLRen = SDL_CreateRenderer(SDLWin, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	assert(SDLRen != nullptr);

	SDL_RenderClear(SDLRen);
};

#define updateGraphics() SDL_RenderPresent(SDLRen);

void SDLEnd()
{
	SDL_DestroyRenderer(SDLRen);
	SDL_DestroyWindow(SDLWin);
	SDL_Quit();
}

class init
{
public:
	init() { SDLStart(); }
	~init() { SDLEnd(); }
};

//global variable: constructor/destructor
//will handle SLD init/destroy
inline init sdlInit;

#endif