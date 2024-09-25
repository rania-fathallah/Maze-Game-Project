#include "maze.h"

// Function to check for collision
bool isColliding(float newX, float newY)
{
    // Calculate grid position
    int gridX = static_cast<int>(newX);
    int gridY = static_cast<int>(newY);

    // Check boundaries and wall presence
    if (gridX < 0 || gridX >= mapWidth || gridY < 0 || gridY >= mapHeight)
        return true; // Out of bounds

    return worldMap[gridY][gridX] > 0; // Check if there's a wall
}

Uint32 getTicks()
{
    return SDL_GetTicks();
}

void calculateDirectionVector()
{
    player.dirX = cos(player.angle);
    player.dirY = sin(player.angle);
}

void cleanup()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void handleEvents()
{
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT)
        {
            running = false;
        }
        handleInput(event);
    }
}

void render3D()
{
    // Raycasting loop
    for (int x = 0; x < WINDOW_WIDTH; x++)
    {
        // Calculate ray position and direction
        double cameraX = 2 * x / double(WINDOW_WIDTH) - 1; // x-coordinate in camera space
        double rayDirX = player.dirX + planeX * cameraX;
        double rayDirY = player.dirY + planeY * cameraX;

        // Which box of the map we're in
        int mapX = int(player.x);
        int mapY = int(player.y);

        // Length of ray from current position to next x or y-side
        double sideDistX;
        double sideDistY;

        // Length of ray from one x or y-side to next x or y-side
        double deltaDistX = (rayDirX == 0) ? 1e30 : fabs(1 / rayDirX);
        double deltaDistY = (rayDirY == 0) ? 1e30 : fabs(1 / rayDirY);
        double perpWallDist;

        // What direction to step in x or y-direction (either +1 or -1)
        int stepX;
        int stepY;

        int hit = 0; // Was there a wall hit?
        int side;    // Was a NS or EW wall hit?

        // Calculate step and initial sideDist
        if (rayDirX < 0)
        {
            stepX = -1;
            sideDistX = (player.x - mapX) * deltaDistX;
        }
        else
        {
            stepX = 1;
            sideDistX = (mapX + 1.0 - player.x) * deltaDistX;
        }
        if (rayDirY < 0)
        {
            stepY = -1;
            sideDistY = (player.y - mapY) * deltaDistY;
        }
        else
        {
            stepY = 1;
            sideDistY = (mapY + 1.0 - player.y) * deltaDistY;
        }

        // Perform DDA
        while (hit == 0)
        {
            // Jump to next map square, either in x-direction or y-direction
            if (sideDistX < sideDistY)
            {
                sideDistX += deltaDistX;
                mapX += stepX;
                side = 0;
            }
            else
            {
                sideDistY += deltaDistY;
                mapY += stepY;
                side = 1;
            }

            // Check if ray has hit a wall
            if (worldMap[mapX][mapY] > 0)
                hit = 1;
        }

        // Calculate distance projected on camera direction (Euclidean distance will give fisheye effect)
        if (side == 0)
            perpWallDist = (mapX - player.x + (1 - stepX) / 2) / rayDirX;
        else
            perpWallDist = (mapY - player.y + (1 - stepY) / 2) / rayDirY;

        // Calculate height of line to draw on screen
        int lineHeight = (int)(WINDOW_HEIGHT / perpWallDist);

        // Calculate lowest and highest pixel to fill in current stripe
        int drawStart = -lineHeight / 2 + WINDOW_HEIGHT / 2;
        if (drawStart < 0)
            drawStart = 0;
        int drawEnd = lineHeight / 2 + WINDOW_HEIGHT / 2;
        if (drawEnd >= WINDOW_HEIGHT)
            drawEnd = WINDOW_HEIGHT - 1;

        // Choose wall color
        SDL_Color color;
        switch (worldMap[mapX][mapY])
        {
        case 1:
            color = {255, 0, 0, 255};
            break; // Red
        case 2:
            color = {0, 255, 0, 255};
            break; // Green
        case 3:
            color = {0, 0, 255, 255};
            break; // Blue
        case 4:
            color = {255, 255, 0, 255};
            break; // Yellow
        case 5:
            color = {255, 0, 255, 255};
            break; // Purple
        default:
            color = {255, 255, 255, 255};
            break; // White
        }

        // Make the color darker for y-side hits
        if (side == 1)
        {
            color.r /= 2;
            color.g /= 2;
            color.b /= 2;
        }

        // Draw the vertical line
        drawVerticalLine(x, drawStart, drawEnd, color);
    }
}

void updateFrameRate() {
    // Calculate elapsed time
    Uint32 currentTime = SDL_GetTicks();
    double deltaTime = (currentTime - oldTime) / 1000.0;
    oldTime = currentTime;

    // Limit frame rate to 60 FPS
    if (deltaTime < 1.0 / 60.0) {
        SDL_Delay((1.0 / 60.0 - deltaTime) * 1000.0);
    }
}
