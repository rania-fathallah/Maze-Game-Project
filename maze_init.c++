#include "maze.h"

void init()
{
    SDL_Init(SDL_INIT_VIDEO);
    window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                              WINDOW_WIDTH, WINDOW_HEIGHT, 0);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}

void render()
{
    if (miniMapVisible) // Check if mini-map should be drawn
    {
        drawMiniMap(); // Draw the mini-map if visible
    }
    SDL_RenderPresent(renderer);
}

void clearScreen()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

