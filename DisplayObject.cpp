#include "DisplayObject.h"

DisplayObject::DisplayObject(int xpos, int ypos, int width, int height)
{
	dimensions = new SDL_Rect();
	dimensions->x = xpos;
	dimensions->y = ypos;
	dimensions->w = width;
	dimensions->h = height;
}

DisplayObject::~DisplayObject()
{
	SDL_DestroyTexture(texture);
}

void DisplayObject::render(SDL_Renderer* renderer)
{
	SDL_RenderCopy(renderer, texture, NULL, dimensions);
}
