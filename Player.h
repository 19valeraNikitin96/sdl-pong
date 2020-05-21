#pragma once
#include "GameObject.h"
#include<SDL_image.h>
#include "Ball.h"
#include"ISubject.h"

class Player :
	public GameObject, public ISubject
{
public:

	Player(int startX, int startY, int width, int height, int speed);

	~Player();

	bool collisionWithBall(Ball& ball);

	int getScore() { return score; }

	void scoreUp() { score++; notify(); };

	/*******Observer*********/

	void attach(ScoreIObserver* observer) override { this->observer = observer; }

	void detach() override { observer = nullptr; }

	void notify() { 
		if (observer != nullptr) observer->update(score); }

private:
	int score = 0;
	ScoreIObserver* observer;
};

