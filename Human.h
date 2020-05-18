#pragma once
#include "Player.h"
class Human :
	public Player
{
public:

	Human(SDL_Texture* texture, int startX, int startY, int width, int height, int speed);

};

