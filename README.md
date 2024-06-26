# Warships - Battleship Game

## Table of Contents
1. [Game Description](#game-description)
2. [Game Rules](#game-rules)
3. [Installation Instructions](#installation-instructions)
4. [Launching the Game](#launching-the-game)
5. [Controls](#controls)
6. [Author](#author)
7. [License](#license)

## Game Description

"Warships" is a classic battleship game where two players attempt to sink each other's fleets. Each player has a 10x10 grid on which they place their ships. The objective of the game is to guess the coordinates of the opponent's ships and sink them before the opponent sinks yours.

## Game Rules

1. **Setting Up Ships**:
    - Each player has a fleet consisting of the following ships:
        - 1x Aircraft Carrier (5 cells)
        - 2x Battleship (4 cells)
        - 3x Cruiser (3 cells)
        - 2x Destroyer (2 cells)
    - Ships can be placed horizontally or vertically, but they cannot touch or overlap.

2. **Gameplay**:
    - Players take turns guessing coordinates on the opponent's grid (e.g., A5, C3).
    - If a guess is a hit, the player marks it on their hit grid.
    - The game ends when all ships of one player are sunk.

## Installation Instructions

To install the game "Warships", follow these steps:

1. **Download the repository**:
    ```bash
    git clone https://github.com/ThaikoZ/gra-w-statki.git
    ```
2. **Navigate to the game directory**:
    ```bash
    cd gra-w-statki/gra-w-statki
    ```
3. **Compile the project**:
    ```bash
    g++ -o gra-w-statki gra-w-statki.cpp Game.cpp Player.cpp Ships.cpp ShipsInConsole.cpp Engine.cpp
    ```

## Launching the Game

To start the game, use the following command in the terminal:

```bash
./gra-w-statki
```

## Controls

- **Setting Ships**: Enter the starting and ending coordinates of the ship.
- **Attack**: Enter the coordinates of the cell you want to attack (e.g., B7).

## Author

- **Adrian Sudak** - Project author.

## License

This project is licensed under the MIT License.

---

## Technical Description

### Directory Structure

```
gra-w-statki/
│
├── gra-w-statki/           # Project directory
│       # Header files
│   ├── Player.h
│   ├── Ships.h
│   ├── ShipsInConsole.h
│   ├── Game.h
│   └── Engine.h
│       # Source files
│   ├── gra-w-statki.cpp
│   ├── Player.cpp
│   ├── Ships.cpp
│   ├── ShipsInConsole.cpp
│   ├── Game.cpp
│   └── Engine.cpp
└── README.md               # README file
```

### Technologies

- **C++** - Main programming language
- **Console** - User interface

### Sample Code

#### gra-w-statki.cpp
```cpp
#include "ShipsInConsole.h"

using namespace std;

int main() {
    ShipsInConsole ships;
    ships.play();

    return 0;
}
```

## Notes

This project is part of the Object-Oriented Programming course requirements.
