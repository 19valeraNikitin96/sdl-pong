#pragma once
#include "Player.h"
class Bot :
	public Player
{
public:

	Bot(SDL_Renderer* renderer, int startX, int startY, int width, int height, int speed, GameObject &target);

	virtual void move();

private:

	GameObject target;
};

