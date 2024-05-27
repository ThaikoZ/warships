#include "Engine.h"


Engine::Engine() {
    currentPlayer = &p1;
    enemyPlayer = &p2;
}

Engine::~Engine() {
    /*delete currentPlayer;
    delete enemyPlayer;*/
}

bool Engine::checkWinCondition() {
    for (int i = 0; i < enemyPlayer->N; i++) {
        if (!enemyPlayer->ships[i].isDestroyed())
            return false;
    }
    return true;
}