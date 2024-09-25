# 3D Raycasting Game

## Introduction

Welcome to the **3D Raycasting Game** project! This project aims to create an engaging 3D game using raycasting techniques, inspired by classic first-person shooters. Players will navigate through a dynamically rendered environment, featuring walls, movement mechanics, collision detection, and a map parser.

- **Author's LinkedIn**: [https://www.linkedin.com/in/rania-fathallah-56511b218/](#)
- **Project Video**: [https://youtu.be/FcLwcL49bsM](#)

## Installation

### Requirements

- Ubuntu 14.04 LTS
- GCC version 4.8.4
- SDL2 library

### Steps to Install

1. Update your package list and install SDL2:
   ```bash
   sudo apt-get update
   sudo apt-get install libsdl2-dev
   ```

2. Clone this repository:
   ```bash
   git clone <repository-url>
   cd <repository-directory>
   ```

3. Compile the project using the Makefile:
   ```bash
   make
   ```

## Usage

To run the game, execute the compiled binary with the path to your map file:
```bash
./your_game_executable <path-to-map-file>
```

You can navigate through the game using the following controls:
- **W**: Move forward
- **A**: Move left
- **S**: Move backward
- **D**: Move right
- **Arrow Keys / Mouse**: Rotate the camera

## Features

1. **Walls Rendering**:
   - Create a window using SDL2.
   - Render walls using raycasting.
   - Differentiate wall colors from the ground/ceiling.

2. **Orientation**:
   - Change wall colors based on their orientation (NORTH/SOUTH vs. EAST/WEST).

3. **Camera Rotation**:
   - Implement camera rotation using keyboard or mouse input.

4. **Camera Movement**:
   - Enable camera movement using WASD keys.

5. **Collision Detection**:
   - Handle player-wall collisions, allowing the player to slide along walls.

6. **Map Parser**:
   - Implement a parser to read the map from a file.
   - Define custom standards for the map (characters for walls and empty spaces, file extension, etc.).
   - The program requires a parameter for the map file path upon execution.

7. **Map Drawing**:
   - Draw the parsed map on the window.
   - Provide the ability to enable/disable map rendering during execution.
   - Include the player’s line of sight in the map rendering.


## Structure

- `Makefile`: Build script for compiling the project.

## Contributing

Contributions are welcome! If you would like to contribute to this project, please follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature/YourFeature`).
3. Make your changes and commit them (`git commit -m 'Add some feature'`).
4. Push to the branch (`git push origin feature/YourFeature`).
5. Open a pull request.

## Related Projects

- [https://github.com/aminosbh/sdl2-samples-and-projects](#)
- [https://github.com/vinibiavatti1/RayCastingTutorial](#)


## Licensing

This project is licensed under the MIT License.

## Acknowledgments

- Special thanks to the SDL2 community and various online resources that contributed to the development of this project.

## Enjoy!

Feel free to reach out if you have any questions or need assistance. Have fun building your 3D raycasting game!


