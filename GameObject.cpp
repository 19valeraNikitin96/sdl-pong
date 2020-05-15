#include "GameObject.h"

GameObject::GameObject(
	SDL_Texture* texture,
	int startX,
	int startY,
	int width,
	int height,
	int speed)
{
	this->texture = texture;
	this->dimensions = new SDL_Rect();
	this->dimensions->x = startX;
	this->dimensions->y = startY;
	this->dimensions->w = width;
	this->dimensions->h = height;
	this->speed = speed;
}

GameObject::~GameObject()
{
	SDL_DestroyTexture(texture);
}

int GameObject::distanceTo(GameObject* another)
{
	if (this == another) {
		throw "Checking the same object!";
		return 0;
	}
	return sqrt(
		pow(
		(this->dimensions->x - another->dimensions->x), 2) 
		+ 
		pow(
		(this->dimensions->x - another->dimensions->x), 2));
}

void GameObject::move()
{
	int deltaY = 0;
	if (movementVertical.moveDown)
		deltaY += speed;
	if (movementVertical.moveUp)
		deltaY -= speed;
	moveTo(0, deltaY);
}

bool GameObject::collisionWith(GameObject* another)
{
	if (this == another) {
		throw "Checking the same object!";
		return false;
	}
	int currentCenter = getCenterX();
	int otherObjCenter = another->getCenterX();
	bool xInterplay = distanceTo(another) < (this->dimensions->w / 2 + another->dimensions->w / 2);
	bool yInterplay =
		(this->dimensions->y <= another->getCenterY() && this->dimensions->y + this->dimensions->h >= another->getCenterY())
		||
		(another->dimensions->y <= this->getCenterY() && another->dimensions->y + another->dimensions->h >= this->getCenterY());
	return xInterplay && yInterplay;
}

void GameObject::moveTo(int x, int y)
{
	GameObject::dimensions->x += x;
	GameObject::dimensions->y += y;
}
