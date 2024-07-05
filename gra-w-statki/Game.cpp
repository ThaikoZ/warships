#include "Game.h"

Game::Game() {
    isOn = true;
}

void Game::play() {
    currentPlayer = &p1;
    int shipsQueue[] = { 5, 4, 4, 3, 3, 3, 2, 2 };

    setPlayerNames();

    // Ustawianie statków
    for (int k = 0; k < 8; k++) {
        for (int i = 0; i < currentPlayer->N; i++) {
            showBoard(true);
            currentPlayer->ships[i].setShip(getFieldToSetShip(shipsQueue[i]));
        }
        switchPlayer();
    }

    // Rozgrywka
    while (isOn) {
        bool hitted;
        do {
            hitted = false;
            showBoard(false);
            Field field = getFieldToShoot();
            for (int i = 0; i < enemyPlayer->N; i++) {
                Ship& ship = enemyPlayer->ships[i];
                if (ship.isHitted(field)) {
                    ship.hitted();
                    if (ship.isDestroyed()) {
                        for (int j = 0; j < ship.length; j++) {
                            for (int horiz = -1; horiz <= 1; horiz++) {
                                for (int vert = -1; vert <= 1; vert++) {
                                    Field f(ship.positions[j].row + vert, ship.positions[j].col + horiz);
                                    bool shotExist = false;
                                    for (int k = 0; k < currentPlayer->shots.size(); k++) {
                                        if (currentPlayer->shots[k].row == f.row
                                            && currentPlayer->shots[k].col == f.col) {
                                            shotExist = true;
                                            break;
                                        }
                                    }
                                    if (!shotExist)
                                        currentPlayer->shots.push_back(f);
                                }
                            }
                        }
                    }
                    hitted = true;
                    break;
                }
            }
            currentPlayer->shots.push_back(field);

            if (checkWinCondition()) {
                isOn = false;
                hitted = false;
            }
            
        } while (hitted);
        
        if(isOn)
            switchPlayer();
    }

    showBoard(false);
    cout << "Wygrywa gracz " << currentPlayer->playerID << ". Gratulacje! " << endl;

}
