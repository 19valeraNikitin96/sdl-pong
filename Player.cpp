#include "Player.h"

Player::Player(int startX, int startY, int width, int height, int speed)
	:GameObject(startX, startY, width, height, speed)
{}

Player::~Player()
{}

bool Player::collisionWithBall(Ball & ball)
{
	int currentCenter = getCenterX();
	int ballCenterX = ball.getCenterX();
	int distance = this->distanceTo(ball);
	bool res = 
		distance < (this->dimensions->w / 2 + ball.getRect()->w / 2)
		&&
		distance < (this->dimensions->h / 2 + ball.getRect()->h / 2);
	/*bool xInterplay =  < ;
	bool yInterplay =
		(this->dimensions->y <= ball.getCenterY() && this->dimensions->y + this->dimensions->h >= ball.getCenterY())
		||
		(ball.getRect()->y <= this->getCenterY() && ball.getRect()->y + ball.getRect()->h >= this->getCenterY());
	*/
	if (res) {
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
		return true;
	}
	return false;
}
