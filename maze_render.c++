#include "maze.h"

void drawVerticalLine(int x, int drawStart, int drawEnd, SDL_Color color)
{
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_RenderDrawLine(renderer, x, drawStart, x, drawEnd);
}


void drawMiniMap()
{
    int miniMapWidth = 200;                        // Width of the mini-map
    int miniMapHeight = 200;                       // Height of the mini-map
    int miniMapTileSize = miniMapWidth / mapWidth; // Calculate tile size based on mini-map width

    // Draw the mini-map background
    SDL_SetRenderDrawColor(renderer, 50, 50, 50, 255); // Dark grey background
    SDL_Rect miniMapRect = {0, 0, miniMapWidth, miniMapHeight};
    SDL_RenderFillRect(renderer, &miniMapRect);

    // Draw the maze on the mini-map
    for (int y = 0; y < mapHeight; y++)
    {
        for (int x = 0; x < mapWidth; x++)
        {
            SDL_Rect rect = {x * miniMapTileSize, y * miniMapTileSize, miniMapTileSize, miniMapTileSize};
            // Only draw walls on the mini-map
            if (worldMap[x][y] == 1)
            {
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255); // White for walls
                SDL_RenderFillRect(renderer, &rect);
            }
            switch (worldMap[x][y])
            {
            case 1:
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
                break;
                // Red

            case 2:
                SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
                break;
                // Green

            case 3:
                SDL_SetRenderDrawColor(renderer, 0, 0, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
                break; // Blue

            case 4:
                SDL_SetRenderDrawColor(renderer, 255, 255, 0, 255);
                SDL_RenderFillRect(renderer, &rect);
                break; // Yellow

            case 5:
                SDL_SetRenderDrawColor(renderer, 255, 0, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
                break; // Purple

            default:
                SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
                SDL_RenderFillRect(renderer, &rect);
                break; // White
            }
        }
    }

    // Draw the player's position on the mini-map
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red for player
    SDL_Rect playerRect = {(int)(player.x * miniMapTileSize), (int)(player.y * miniMapTileSize), miniMapTileSize, miniMapTileSize};
    SDL_RenderFillRect(renderer, &playerRect);
}
