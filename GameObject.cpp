#include "GameObject.h"

GameObject::GameObject(
	int startX,
	int startY,
	int width,
	int height,
	int speed)
	:DisplayObject(startX, startY, width, height)
{
	this->speedY = speed;
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
}

int GameObject::distanceTo(GameObject &another)
{
	return sqrt(
		pow(
		(this->dimensions->x - another.dimensions->x), 2) 
		+ 
		pow(
		(this->dimensions->y - another.dimensions->y), 2));
}

void GameObject::move()
{
	int deltaY = 0;
	if (movementVertical.moveDown)
		deltaY += speedY;
	if (movementVertical.moveUp)
		deltaY -= speedY;
	changePosition(0, deltaY);
}

void GameObject::changePosition(int xDelta, int yDelta)
{
	GameObject::dimensions->x += xDelta;
	GameObject::dimensions->y += yDelta;
}
