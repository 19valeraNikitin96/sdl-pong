#include "ScoreBanner.h"
#include<string>

SDL_Color ScoreBanner::color = { 0,0,0 };

TTF_Font* ScoreBanner::font = nullptr;

SDL_Renderer* ScoreBanner::renderer = nullptr;

ScoreBanner::ScoreBanner(int xpos, int ypos, int width, int height, Player& player)
	:DisplayObject(xpos, ypos, width, height), player(player)
{
	this->texture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(ScoreBanner::font, std::to_string(player.getScore()).c_str(), ScoreBanner::color));
	player.attach(this);
}

void ScoreBanner::updateState(const int newDisplayedScore)
{
	this->texture = SDL_CreateTextureFromSurface(renderer, TTF_RenderText_Solid(ScoreBanner::font, std::to_string(newDisplayedScore).c_str(), ScoreBanner::color));
}
