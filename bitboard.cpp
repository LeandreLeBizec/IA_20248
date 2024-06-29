#include <iostream>
#include "GameBoard.h"
#include <vector>
#include <iostream>

using namespace std;

/*void rollout(Game *g){
    Game currentGame = *g;
    for(int i = 0; i < 500000010; i++){
        currentGame.generate1Son();
    }
    g->setScore(currentGame.getScore());
}*/

void montecarlo_simple(GameBoard &root){
    GameBoard current_game = root;
    vector<GameBoard::GameAction> actions = current_game.legalActions();
    vector<int> scoresPotentielsFils(actions.size(), 0);
    do{
        for(int i = 0; i < actions.size(); i++){
            //return legals.at(action);
            GameBoard copie = current_game.next(actions[i]);
            for(int j = 0; j<10; j++){
                vector<GameBoard::GameAction> actionsCopie = copie.legalActions();
                std::uniform_int_distribution<unsigned int> rand_action(0, actionsCopie.size()-1);
                auto action = rand_action(default_generator());
                copie = copie.next(actionsCopie[action]);
            }
            scoresPotentielsFils[i] = copie.getScore();
        }

        int indice = 0;
        int scoreMax = 0;
        //int tmax = 0;

        for(int k = 0; k < actions.size(); k++){
            if(scoresPotentielsFils[k] > scoreMax){
                indice = k;
                scoreMax = scoresPotentielsFils[k];
            }
        }
        current_game = current_game.next(actions[indice]);
        std::cout << current_game << std::endl;
        actions = current_game.legalActions();
    }while(!actions.empty());

    std::cout << current_game << std::endl;
    cout<<"fin de partie, score : "<<current_game.getScore()<<endl;
}

int main() {
    srand(time(0));
    GameBoard game;
    montecarlo_simple(game);
    //game.play();

    return 0;
}
