#include "Bot.h"

Bot::Bot(
	SDL_Texture* texture, 
	int startX, 
	int startY, 
	int width, 
	int height,
	int speed, 
	GameObject &target)
	:Player(texture, startX, startY, width, height, speed)
{
	this->target = target;
}

void Bot::move()
{
	if (target.getX() < 275)
		return;
	if (target.getY() > this->getY()) {
		setMoveDown(true);
		setMoveUp(false);
	}
	else {
		setMoveUp(true);
		setMoveDown(false);
	}
	Player::move();
}