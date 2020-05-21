#pragma once
#include"DisplayObject.h"
#include "SDL.h"
#include "SDL_image.h"
class GameObject
	: public DisplayObject
{
protected:
	struct Movement
	{
		bool moveUp = false;
		bool moveDown = false;
	} movementVertical;
	int speedY;

public:

	int getCenterX() { return (dimensions->x + dimensions->w / 2); }

	int getCenterY() { return (dimensions->y + dimensions->h / 2); }

	int distanceTo(GameObject &another);

	GameObject(int startX, int startY, int width, int height, int speed);

	~GameObject();
	
	virtual void move();

	void changePosition(int xDelta, int yDelta);

	int getX() {return dimensions->x;}

	int getY() {return dimensions->y;}

	int getWidth() { return dimensions->w; }

	int getHeight() { return dimensions->h; }

	SDL_Texture *getTexture() { return texture; }

	SDL_Rect* getRect() { return dimensions; }

	void setMoveUp(bool moveUp) { movementVertical.moveUp = moveUp; }

	void setMoveDown(bool moveDown) { movementVertical.moveDown = moveDown; }
};

