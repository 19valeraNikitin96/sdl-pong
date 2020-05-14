
#include "SDL.h"

int main(int argc, char * argv[])
{

    // retutns zero on success else non-zero 
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* win = SDL_CreateWindow("GAME",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);
    SDL_Renderer* renderer = SDL_CreateRenderer(win, -1, 0);
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    SDL_Delay(3000);

    //while (1);

    return 0;
}
