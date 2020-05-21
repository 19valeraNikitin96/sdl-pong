#include "Bot.h"

Bot::Bot(
	SDL_Renderer *renderer,
	int startX, 
	int startY, 
	int width, 
	int height,
	int speed, 
	GameObject &target)
	:Player(startX, startY, width, height, speed), target(target)
{
	SDL_Surface* tmpSurface = IMG_Load("assets\\pedal2.png");
	texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
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