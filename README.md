# 2048 Game with Monte Carlo AI

## Project Overview
This project is an implementation of the **2048** game, utilizing **Monte Carlo algorithms** to enable an artificial intelligence (AI) to play the game effectively. 

## Key Components

1. **Game Structure**:
   - The `Game` class represents the state of the game, including a 4x4 grid (board), the score, and methods to make moves (up, down, left, right) and generate new tiles.

2. **Tile Generation**:
   - When a player makes a move, new tiles are randomly generated on the board. The value of new tiles is determined by random selection, where 2 is more likely to appear than 4.

3. **Board Display**:
   - The `display()` method allows visualization of the current state of the board and score, facilitating interaction with the player.

4. **Game Movements**:
   - The `moveUp()`, `moveDown()`, `moveLeft()`, and `moveRight()` methods handle the logic of the movements, merging tiles when possible and updating the score accordingly.

5. **Monte Carlo AI**:
   - The AI uses a Monte Carlo algorithm to simulate numerous game scenarios, evaluating potential outcomes for each possible move. It selects the move with the highest potential score, demonstrating an optimal gameplay strategy.

6. **User Interface**:
   - Players can choose to play manually using the keys `z`, `q`, `s`, and `d`, or let the AI play automatically.

## Project Objective
The primary goal is to create an interactive game where users can play against an AI while exploring advanced techniques in artificial intelligence and performance optimization. This project also serves as a platform to understand the challenges related to designing algorithms for strategy games.

## Installation
To run the project, clone the repository and build the code using CMake:

```bash
git clone <repository-url>
cd <project-directory>
mkdir build
cd build
cmake ..
make
