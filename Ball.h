#pragma once
#include "GameObject.h"
const class Ball :
	public GameObject
{

private:
	struct MovementHorizontal
	{
		bool moveRight = false;
		bool moveLeft = false;
	} movementHorizontal;
	struct BordersCoords {
		int leftX = 0;
		int rightX = 600;
		int upY = 0;
		int downY = 400;
	} borders;

public:

	Ball(SDL_Texture* texture,
		int startX,
		int startY,
		int width,
		int height,
		int speed);

	~Ball();

	void setMoveRigth(bool moveRight) { movementHorizontal.moveRight = moveRight; }

	void setMoveLeft(bool moveLeft) { movementHorizontal.moveLeft = moveLeft; }

	virtual void move();

};

