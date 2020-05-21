#pragma once
#include "Player.h"
class Human :
	public Player
{
public:

	Human(SDL_Renderer *renderer, int startX, int startY, int width, int height, int speed);

};

