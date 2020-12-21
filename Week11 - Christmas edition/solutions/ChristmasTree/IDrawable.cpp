#pragma once

#include "IDrawable.h"
IDrawable::IDrawable(SDL_Renderer* _renderer)
{
	this->SDLRender = _renderer;
}

SDL_Renderer* IDrawable::getRenderer()
{
	return SDLRender;
}

IDrawable::~IDrawable() = default;
