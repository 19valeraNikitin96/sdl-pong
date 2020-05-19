#pragma once
#include"DisplayObject.h"
#include <SDL_ttf.h>
#include"Player.h"

class ScoreBanner
	: public DisplayObject, public ScoreIObserver
{
public:

	ScoreBanner(SDL_Renderer *renderer, int xpos, int ypos, int width, int height, Player& player);

	/*******Observer***********/

	void update(const int newDisplayedScore) override { updateState(newDisplayedScore); };

private:

	void updateState(int newDisplayedScore);

private:
	Player& player;
private:
	static SDL_Color color;
	static TTF_Font* font;
	static SDL_Renderer* renderer;
};

