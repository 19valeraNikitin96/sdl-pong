
#include "Game.h"

using namespace std;

Game* game = nullptr;

int main(int argc, char * argv[])
{
    game = new Game();
    game->init("Netgames Test", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 550, 400, false);
    int time;
    while (game->running()) {
        time = SDL_GetTicks();
        game->handleEvents();
        game->update();
        game->render();
        time = SDL_GetTicks() - time;
        if (time < 1000 / game->FPS) 
            SDL_Delay((1000 / game->FPS) - time);
    }
    game->clean();
    return 0;
}
