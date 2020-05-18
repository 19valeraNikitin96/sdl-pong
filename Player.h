#pragma once
#include "GameObject.h"
#include "Ball.h"
class Player :
	public GameObject
{
public:

	Player(SDL_Texture* texture, int startX, int startY, int width, int height, int speed);

	~Player();

	bool collisionWithBall(Ball& ball);

private:
	int score = 0;
};

