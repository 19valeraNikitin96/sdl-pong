#include "Human.h"

Human::Human(SDL_Renderer *renderer, int startX, int startY, int width, int height, int speed)
	:Player(startX, startY, width, height, speed)
{
	SDL_Surface* tmpSurface = IMG_Load("assets\\pedal1.png");
	texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
}
