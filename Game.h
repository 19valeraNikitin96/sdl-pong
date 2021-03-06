#pragma once
#ifndef Game_h
#define Game_h
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include "Ball.h"
#include "Human.h"
#include "Bot.h"
#include "ScoreBanner.h"
#include<list>

class Game
{
public:
	const int FPS = 24;
public:
	Game();
	~Game();
	
	void init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

private:
	bool isRunning;
	SDL_Window *window;
	SDL_Renderer *renderer;

	Ball* ball;
	Human* human;
	Bot* bot;
	ScoreBanner* humanBanner;
	ScoreBanner* botBanner;

	std::list<DisplayObject*> children;

};

#endif // !Game_h


