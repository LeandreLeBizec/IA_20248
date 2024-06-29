#include <vector>
#include "game.h"

using namespace std;

pair<int, int> Game::generateNewTileIndex(){
    vector<pair<int, int>> zero;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (board[i][j] == 0) {
                zero.push_back(make_pair(i, j));
            }
        }
    }
    srand(time(0));
    int random_index = rand() % zero.size();
    pair<int, int> chosen_index = zero[random_index];
    return chosen_index;
}

Game::Game(){
    score = 0;
    board = {{{16,4,2,2},{0,0,0,0},{0,0,0,0},{0,0,0,0}}};
//    for(int i=0; i<boardSize; i++){
//        for(int j=0; j<boardSize; j++){
//            board[i][j] = 0;
//        }
//    }
//    pair<int, int> pos1 = generateNewTileIndex();
//    board[pos1.first][pos1.second] = 2;
//    pair<int, int> pos2 = generateNewTileIndex();
//    board[pos2.first][pos2.second] = 2;
}

void Game::display() {
    cout <<"===== Score : " << score << " =========" << endl;
    for (int i=0; i<boardSize; i++){
        for(int j=0; j<boardSize; j++){
            if(board[i][j] == 0){
                cout << "  .  ";
            }else{
                cout << "  " << board[i][j] << "  ";
            }
        }
        cout << endl;
    }
}

int Game::generateNewTileValue() {
    std::srand(std::time(0));
    int randomNum = std::rand() % 5 + 1;
    return randomNum == 5 ? 4 : 2;
}


void Game::moveRight() {
    bool generateTile = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 2; j >= 0; j--) {
            if (board[i][j] != 0) {
                int k = j+1;
                while (k < 4 && board[i][k] == 0) {
                    k++;
                }
                if (board[i][k] == board[i][j]) {
                    board[i][k] *= 2;
                    board[i][j] = 0;
                    generateTile = true;
                    score += board[i][k];
                } else {
                    if(j<k-1){
                        board[i][k-1] = board[i][j];
                        board[i][j] = 0;
                        generateTile = true;
                    }
                }
            }
        }
    }
    if(generateTile){
        pair<int, int> pos2 = generateNewTileIndex();
        board[pos2.first][pos2.second] = generateNewTileValue();
    }
}

void Game::moveLeft() {
    bool generateTile = false;
    for (int i = 0; i < 4; i++) {
        for (int j = 1; j < 4; j++) {
            if (board[i][j] != 0) {
                int k = j - 1;
                while ( k >= 0 && board[i][k] == 0) {
                    k--;
                }
                if (board[i][k] == board[i][j]) {
                    board[i][k] *= 2;
                    board[i][j] = 0;
                    generateTile = true;
                    score += board[i][k];
                } else {
                    if (k < j - 1) {
                        board[i][k + 1] = board[i][j];
                        board[i][j] = 0;
                        generateTile = true;
                    }
                }
            }
        }
    }
    if(generateTile) {
        pair<int, int> pos2 = generateNewTileIndex();
        board[pos2.first][pos2.second] = generateNewTileValue();
    }
}

void Game::moveUp() {
    bool generateTile = false;
    for (int j = 0; j < 4; j++) {
        for (int i = 1; i < 4; i++) {
            if (board[i][j] != 0) {
                int k = i - 1;
                while (k >= 0 && board[k][j] == 0) {
                    k--;
                }
                if (k >= 0 && board[k][j] == board[i][j]) {
                    board[k][j] *= 2;
                    board[i][j] = 0;
                    generateTile = true;
                    score += board[k][j];
                } else {
                    if (k < i - 1) {
                        board[k + 1][j] = board[i][j];
                        board[i][j] = 0;
                        generateTile = true;
                    }
                }
            }
        }
    }
    if(generateTile) {
        pair<int, int> pos2 = generateNewTileIndex();
        board[pos2.first][pos2.second] = generateNewTileValue();
    }
}

void Game::moveDown() {
    bool generateTile = false;
    for (int j = 0; j < 4; j++) {
        for (int i = 2; i >= 0; i--) {
            if (board[i][j] != 0) {
                int k = i + 1;
                while (k < 4 && board[k][j] == 0) {
                    k++;
                }
                if (k < 4 && board[k][j] == board[i][j]) {
                    board[k][j] *= 2;
                    board[i][j] = 0;
                    generateTile = true;
                    score += board[k][j];
                } else {
                    if (k > i + 1) {
                        board[k - 1][j] = board[i][j];
                        board[i][j] = 0;
                        generateTile = true;
                    }
                }
            }
        }
    }
    if(generateTile) {
        pair<int, int> pos2 = generateNewTileIndex();
        board[pos2.first][pos2.second] = generateNewTileValue();
    }
}

void Game::play() {
    srand(time(0));
    while(true){
        display();
        char userCommand;
        cin >> userCommand;
        switch (userCommand) {
            case 'z':
                moveUp();
                break;
            case 'q':
                moveLeft();
                break;
            case 'd':
                moveRight();
                break;
            case 's':
                moveDown();
                break;
        }
    }
}