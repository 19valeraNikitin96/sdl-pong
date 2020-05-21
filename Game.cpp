#include "Game.h"
#include<list>

Ball *ball;
Human *human;
Bot *bot;
ScoreBanner* humanBanner;
ScoreBanner* botBanner;

std::list<DisplayObject*> children;

Game::Game() {}
Game::~Game() {}

void Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
	int flags = (fullscreen) ? SDL_WINDOW_FULLSCREEN  : 0;
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
		std::cout << "Subsystem initialised" << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		if (window) 
			std::cout << "Window created" << std::endl;
		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer) {
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created" << std::endl;
		}
		isRunning = true;
		ball = new Ball(renderer, 200, 200, 24, 24, 8, width, height);
		human = new Human(renderer, width * 0.1, height/2 - 60 / 2, 60, 60, 5);
		bot =	new Bot	 (renderer,	width * 0.9 - 60, height/2-60/2, 60, 60, 5, *ball);
		TTF_Init();
		int centerX = width / 2;
		{
			ScoreBanner::font = TTF_OpenFont("fonts\\arial.ttf", 25);
			ScoreBanner::renderer = renderer;
			humanBanner = new ScoreBanner(centerX - 50, 25, 50, 50, *human);
			botBanner = new ScoreBanner(centerX + 50, 25, 50, 50, *bot);
		}
		human->attach(humanBanner);
		bot->attach(botBanner);
		children = { ball, human, bot,humanBanner, botBanner};
		
	}
	else {
		isRunning = false;
	}
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_KEYDOWN:
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			human->setMoveUp(true); break;
		case SDLK_DOWN:
			human->setMoveDown(true); break;
		}
		break;
	case SDL_KEYUP:
		switch (event.key.keysym.sym) {
		case SDLK_UP:
			human->setMoveUp(false); break;
		case SDLK_DOWN:
			human->setMoveDown(false); break;
		}
		break;
	case SDL_QUIT:
		isRunning = false;break;
	default:
		break;
	}
}

void Game::update()
{
	ball->move();
	human->move();
	bot->move();
	if (ball->crossLeftBorder()) {
		bot->scoreUp();
		ball->initialPosition();
		ball->disableVerticalMovement();
		return;
	}
	if (ball->crossRightBorder()) {
		human->scoreUp();
		ball->initialPosition();
		ball->disableVerticalMovement();
		return;
	}
	human->collisionWithBall(*ball);
	bot->collisionWithBall(*ball);
}

void Game::render()
{
	SDL_RenderClear(renderer);
	for (auto it = children.begin(); it != children.end(); it++)
		(**it).render(renderer);
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	TTF_Quit();
}

bool Game::running()
{
	return Game::isRunning;
}