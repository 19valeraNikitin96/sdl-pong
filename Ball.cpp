#include "Ball.h"

Ball::Ball(SDL_Renderer* renderer, int startX, int startY, int width, int height, int speed, int widthLimit, int heightLimit)
	:GameObject(startX, startY, width, height, speed)
{
	SDL_Surface* tmpSurface = IMG_Load("assets\\tennis_ball.png");
	texture = SDL_CreateTextureFromSurface(renderer, tmpSurface);
	SDL_FreeSurface(tmpSurface);
	this->borders.rightX = widthLimit;
	this->borders.downY = heightLimit;
	setMoveRigth(true);
}

Ball::~Ball(){}

void Ball::move()
{
	GameObject::move();
	int deltaX = 0;
	if (movementHorizontal.moveLeft)
		deltaX -= speedX;
	if (movementHorizontal.moveRight)
		deltaX += speedX;
	changePosition(deltaX, 0);
	if (getCenterX() < borders.leftX) {
		movementHorizontal.moveRight = true;
		movementHorizontal.moveLeft = false;
	}
	if (getCenterX() > borders.rightX) {
		movementHorizontal.moveRight = false;
		movementHorizontal.moveLeft = true;
	}
	if (getCenterY() < borders.upY) {
		movementVertical.moveDown = true;
		movementVertical.moveUp = false;
	}
	if (getCenterY() > borders.downY) {
		movementVertical.moveDown = false;
		movementVertical.moveUp = true;
	}
}
