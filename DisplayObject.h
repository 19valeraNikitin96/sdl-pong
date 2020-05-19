#pragma once
#include<SDL.h>
class DisplayObject
{
protected:
	SDL_Texture* texture;
	SDL_Rect* dimensions;

public:

	DisplayObject(int xpos, int ypos, int width, int height);

	~DisplayObject();

	void render(SDL_Renderer* renderer);
};

