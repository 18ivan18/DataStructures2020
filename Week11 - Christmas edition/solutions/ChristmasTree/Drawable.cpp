#pragma once

#include "Drawable.h"
Drawable::Drawable(SDL_Renderer* _renderer, Color _color) : color(_color)
{
	this->SDLRender = _renderer;
}

SDL_Renderer* Drawable::getRenderer()
{
	return SDLRender;
}

Color Drawable::getColor() const
{
	return this->color;
}

void Drawable::colorize()
{
	setColor(color.getR(), color.getG(), color.getB())
}

Drawable::~Drawable() = default;
