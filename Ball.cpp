#include "Ball.h"

Ball::Ball(SDL_Texture* texture, int startX, int startY, int width, int height, int speed)
	:GameObject(texture, startX, startY, width, height, speed)
{}

Ball::~Ball(){}

void Ball::move()
{
	GameObject::move();
	int deltaX = 0;
	if (movementHorizontal.moveLeft)
		deltaX -= speed;
	if (movementHorizontal.moveRight)
		deltaX += speed;
	moveTo(deltaX, 0);
	//Move to a separate function!
	if (dimensions->x < borders.leftX) {
		movementHorizontal.moveRight = true;
		movementHorizontal.moveLeft = false;
	}
	if (dimensions->x > borders.rightX) {
		movementHorizontal.moveRight = false;
		movementHorizontal.moveLeft = true;
	}
	if (dimensions->y < borders.upY) {
		movementVertical.moveDown = true;
		movementVertical.moveUp = false;
	}
	if (dimensions->y > borders.downY) {
		movementVertical.moveDown = false;
		movementVertical.moveUp = true;
	}
}
