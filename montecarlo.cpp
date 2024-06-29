#include <iostream>
#include "game.h"
#include "Node.h"
#include <cmath>
#include <chrono>

using namespace std;
//std::chrono::milliseconds const thinkingtime(50);

void rollout(Node* n){ //generates x random mooves
    /*chrono::steady_clock::time_point start = chrono::steady_clock::now();
    chrono::steady_clock::time_point now = chrono::steady_clock::now();
    while(now < start + thinkingtime){
        n->generate1Son();
        n = n->getSons()[0];
        now = chrono::steady_clock::now();
    }*/
    for(int i = 0; i < 1000; i++){
        n->generate1Son();
        n = n->getSons()[0];
    }
    n->propagate();
}

Node* selectBestNode(Node * ncourrant, Node * root){ //select the best son of ncourant
    int indicemax = 0;
    int max = 0;
    int stop = 0;
    int i;
    for(i = 0; i < ncourrant->getSons().size() && !stop; i++){
        if(ncourrant->getSons()[i]->getN() == 0){
            indicemax = i;
            stop = 1;
        }else{
            Node *n = ncourrant->getSons()[i];
            Game g = n->getCurrentGame();
            if(max < ((g.getScore()/n->getN()) + 2 * sqrt(log(root->getN())/n->getN()))){
                max = (g.getScore()/n->getN()) + 2 * sqrt(log(root->getN())/n->getN());
                indicemax = i;
            }
        }
    }
    ncourrant = ncourrant->getSons()[indicemax];
    return ncourrant;
}

void montecarlo(Node* root, int iteration){ //algorthm of the montecarlo-tree-search
    if(iteration < 400){ //defines how many iterations we will do beefore taking the decision of a moove.
        Node* currentNode = root;

        /*phase 1 : while the current Node isn't a leaf, we select the best son of this node*/
        while(! currentNode->getSons().empty()){ //phase 1 of the algorithm : select the best leaf Node
            currentNode = selectBestNode(currentNode, root);
        }

        /*phase 2 : generate random mooves */
        /* if the current node hasn't been explored, we generate random mooves from this node*/
        /* else, we generate the sons of this node and we generate random mooves from the first son*/
        if(currentNode->getN() == 0){
            rollout(currentNode);
            currentNode->forget();
            iteration++;
            montecarlo(root, iteration);
        }else{
            currentNode->generateSons();
            if(!currentNode->getSons().empty()){
                rollout(currentNode->getSons()[0]);
                currentNode->getSons()[0]->forget();
            }else{
                currentNode->propagate();
            }
            iteration++;
            montecarlo(root, iteration);
        }
    }
}

void applyMontecarlo(Node* root, int indice){ // used to define how many mooves we will do
    /*chrono::steady_clock::time_point start = chrono::steady_clock::now();
    chrono::steady_clock::time_point now = chrono::steady_clock::now();
    while(now < start + thinkingtime){
        montecarlo(root);
        now = chrono::steady_clock::now();
    }
    root = selectBestNode(root, root);
    root->getCurrentGame().display();
    indice++;
    applyMontecarlo(root, indice);*/
    montecarlo(root, 0);
    while(!root->getSons().empty()){
        Game g = selectBestNode(root, root)->getCurrentGame();
        indice++;
        delete root;
        applyMontecarlo(new Node(g, nullptr), indice);
    }
}

int main() {
    std::srand(std::time(0));
    Game game;

    Node* root = new Node(game, nullptr);
    applyMontecarlo(root, 0);

    root->getCurrentGame().display();
    cout << "fin de partie, score : " << root->getCurrentGame().getScore() << endl;

    return 0;
}
