#include "Player.h"
#include<iostream>
Player::Player(SDL_Texture* texture, int startX, int startY, int width, int height, int speed)
	:GameObject(texture, startX, startY, width, height, speed)
{}

Player::~Player()
{}

bool Player::collisionWithBall(Ball & ball)
{
	int currentCenter = getCenterX();
	int ballCenterX = ball.getCenterX();
	bool xInterplay = distanceTo(ball) < (this->dimensions->w / 2 + ball.getRect()->w / 2);
	bool yInterplay =
		(this->dimensions->y <= ball.getCenterY() && this->dimensions->y + this->dimensions->h >= ball.getCenterY())
		||
		(ball.getRect()->y <= this->getCenterY() && ball.getRect()->y + ball.getRect()->h >= this->getCenterY());
	if (xInterplay && yInterplay) {
		int distanceToCenter = this->getCenterY() - ball.getCenterY();
		int absValue = abs(distanceToCenter);
		int percentage = absValue * 100 / dimensions->h;
		int newVal = percentage * ball.MAX_SPEED_Y / 100;
		ball.setSpeedY(newVal);
		if (distanceToCenter < 0) {
			ball.setMoveDown(true);
			ball.setMoveUp(false);
		}
		else {
			ball.setMoveUp(true);
			ball.setMoveDown(false);
		}
		ball.reverseHorizontal();
		std::cout << "New speedY: " << distanceToCenter << std::endl;
		return true;
	}
	return false;
}
