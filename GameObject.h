#pragma once
#include "SDL.h"
#include "SDL_image.h"
class GameObject
{
protected:
	SDL_Texture* texture;
	SDL_Rect* dimensions;
	struct Movement
	{
		bool moveUp = false;
		bool moveDown = false;
	} movementVertical;
	int speed;

private:

	int getCenterX() {return (dimensions->x + dimensions->w / 2);}

	int getCenterY() {return (dimensions->y + dimensions->h / 2);}

	int distanceTo(GameObject *another);

public:

	GameObject(SDL_Texture *texture, int startX, int startY, int width, int height, int speed);

	~GameObject();
	
	virtual void move();

	bool collisionWith(GameObject *another);

	void moveTo(int x, int y);

	int getX() {return dimensions->x;}

	int getY() {return dimensions->y;}

	int getWidth() { return dimensions->w; }

	int getHeight() { return dimensions->h; }

	SDL_Texture *getTexture() { return texture; }

	SDL_Rect* getRect() { return dimensions; }

	void setMoveUp(bool moveUp) { movementVertical.moveUp = moveUp; }

	void setMoveDown(bool moveDown) { movementVertical.moveDown = moveDown; }
};

