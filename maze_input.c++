#include "maze.h"

void handleInput(SDL_Event &event)
{
    switch (event.type)
    {
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym)
        {
        case SDLK_w: // Move forward
            if (!isColliding(player.x + player.dirX * player.speed, player.y + player.dirY * player.speed))
            {
                player.x += player.dirX * player.speed;
                player.y += player.dirY * player.speed;
            }
            break;
        case SDLK_s: // Move backward
            if (!isColliding(player.x - player.dirX * player.speed, player.y - player.dirY * player.speed))
            {
                player.x -= player.dirX * player.speed;
                player.y -= player.dirY * player.speed;
            }
            break;
        case SDLK_a: // Strafe left
            if (!isColliding(player.x - player.dirY * player.speed, player.y + player.dirX * player.speed))
            {
                player.x -= player.dirY * player.speed;
                player.y += player.dirX * player.speed;
            }
            break;
        case SDLK_d: // Strafe right
            if (!isColliding(player.x + player.dirY * player.speed, player.y - player.dirX * player.speed))
            {
                player.x += player.dirY * player.speed;
                player.y -= player.dirX * player.speed;
            }
            break;
        case SDLK_LEFT: // Rotate left
            player.angle += player.rotationSpeed;
            player.dirX = sin(player.angle);
            player.dirY = cos(player.angle);
            break;
        case SDLK_RIGHT:
            player.angle -= player.rotationSpeed;
            player.dirX = sin(player.angle);
            player.dirY = cos(player.angle);
            break;
        case SDLK_m:                          // Check if "M" key is pressed
            miniMapVisible = !miniMapVisible; // Toggle mini-map visibility
            break;
        }
        break;
    }
}