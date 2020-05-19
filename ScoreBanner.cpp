#include "ScoreBanner.h"
#include<string>

SDL_Color ScoreBanner::color = { 0,0,0 };

TTF_Font* ScoreBanner::font = TTF_OpenFont("C:\\Users\\valera\\source\\repos\\NetgamesTest\\arial.ttf", 25);

SDL_Renderer* ScoreBanner::renderer = nullptr;

ScoreBanner::ScoreBanner(SDL_Renderer *renderer, int xpos, int ypos, int width, int height, Player& player)
	:DisplayObject(xpos, ypos, width, height), player(player)
{
	if (this->renderer == nullptr)
		this->renderer = renderer;
	if(font == NULL)
		font = TTF_OpenFont("C:\\Users\\valera\\source\\repos\\NetgamesTest\\arial.ttf", 25);
	this->texture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(ScoreBanner::font, std::to_string(player.getScore()).c_str(), ScoreBanner::color));
	player.attach(this);
}

void ScoreBanner::updateState(const int newDisplayedScore)
{
	this->texture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(ScoreBanner::font, std::to_string(newDisplayedScore).c_str(), ScoreBanner::color));
}
