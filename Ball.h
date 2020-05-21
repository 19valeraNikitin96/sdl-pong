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
	int speedX = speedY;

public:

	bool crossLeftBorder() { return getCenterX() < 0; }

	bool crossRightBorder() { return getCenterX() > borders.rightX; }

	void initialPosition() { 
		dimensions->x = borders.rightX / 2 - dimensions->w/2; 
		dimensions->y = borders.downY / 2 - dimensions->h / 2;
	}

	const int MAX_SPEED_X = 8;
	const int MAX_SPEED_Y = MAX_SPEED_X*2;

	void setSpeedY(int value) {
		speedY = value;
	}

	int getSpeedY() { return speedY; }

	Ball(SDL_Renderer* renderer,
		int startX,
		int startY,
		int width,
		int height,
		int speed, 
		int widthLimit, 
		int heightLimit);

	~Ball();
	//REMOVE IT
	void setMoveRigth(bool moveRight) { movementHorizontal.moveRight = moveRight; }
	//REMOVE IT
	void setMoveLeft(bool moveLeft) { movementHorizontal.moveLeft = moveLeft; }

	virtual void move();

	void reverseMovement() {
		reverseHorizontal();
		reverseVertical();
	}

	void reverseHorizontal() {
		movementHorizontal.moveLeft = !movementHorizontal.moveLeft;
		movementHorizontal.moveRight = !movementHorizontal.moveRight;
	}

	void reverseVertical() {
		movementVertical.moveDown = !movementVertical.moveDown;
		movementVertical.moveUp = !movementVertical.moveUp;
	}

	void disableVerticalMovement() {
		movementVertical.moveDown = false;
		movementVertical.moveUp = false;
	}
};

