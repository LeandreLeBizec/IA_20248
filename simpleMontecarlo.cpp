#include <iostream>
#include "game.h"
#include <vector>
#include <algorithm>

using namespace std;

void montecarlo_simple(Game &root){
    Game current_game = root;
    vector<Game> sons;
    sons = current_game.generateSons();
    do{
        //# pragma omp parallel for num_threads(4)
        for(int i = 0; i < sons.size(); i++){
            sons[i].setScorePotentiel(0);
            //Game copie = sons[i];
            int b;
            int j;
            for(j=0; j<100; j++){
                Game copie = sons[i];
                do{
                    b = copie.generate1Son();
                }while(b);
                sons[i].setScorePotentiel(
                        (sons[i].getScorePotentiel() + copie.getScore()));
            }
            //sons[i].setScorePotentiel(sons[i].getScorePotentiel()/j);
        }

        auto it = max_element(sons.begin(), sons.end(), [](const auto& g, const auto& d){return g.getScorePotentiel() < d.getScorePotentiel();});
        current_game = *it;
        current_game.display();
        sons = current_game.generateSons();
    }while(!sons.empty());

    current_game.display();
    cout<<"fin de partie, score : "<<current_game.getScore()<<endl;
}

int main() {
    srand(time(0));
    Game game;
    int x;
    cout << "If you want to play tape 1 (then use zqsd to play), if you want the IA to show you what a really good player is tape 2 "; // Type a number and press enter
    cin >> x; // Get user input from the keyboard
    switch (x) {
        case 1:
            game.play();
            break;
        case 2:
            montecarlo_simple(game);
            break;
        default:
            cout << "bad input, next time tape 1 or 2"<<endl;
    }

    return 0;
}
