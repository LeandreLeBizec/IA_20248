#ifndef IA2048_GAME_H
#define IA2048_GAME_H

#include <iostream>
#include <array>
#include <ctime>
#include <cstdlib>

using namespace std;

class Game{
private:
    static int const boardSize = 4;
    array<array<int, boardSize>, boardSize> board;

    int score;
    // score += valeur résultante de la tuile fusionné.
public:
    Game();
    pair<int, int> generateNewTileIndex();
    int generateNewTileValue();
    void display();
    void play();
    void moveRight();
    void moveLeft();
    void moveUp();
    void moveDown();
};

#endif /*IA2048_GAME_H*/