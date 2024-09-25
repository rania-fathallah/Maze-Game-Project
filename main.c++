#include "maze.h"

int main() {
    init();

    player = {
        .x = 12,
        .y = 20,
        .angle = 0,
        .speed = 0.1,
        .rotationSpeed = 0.05,
    };

    // Calculate initial direction vector
    calculateDirectionVector();

    bool running = true;
    SDL_Event event;

    while (running) {
        handleEvents();
        clearScreen();
        render3D();
        updateFrameRate();
    }

    cleanup();

    return 0;
}