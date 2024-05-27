#include "ShipsInConsole.h"


ShipsInConsole::ShipsInConsole() {
    alphabet = "ABCDEFGHIJ";
}
void clearConsole() {
    system("CLS");
}

void ShipsInConsole::showBoard(bool prepare) {
    clearConsole();
    vector<Field> fields;
    if (prepare) {
        for (int i = 0; i < currentPlayer->N; i++) {
            for (int j = 0; j < currentPlayer->ships[i].length; j++)
                fields.push_back(Field(currentPlayer->ships[i].positions[j].row, currentPlayer->ships[i].positions[j].col));
        }
    }
    else {
        for (int i = 0; i < enemyPlayer->N; i++) {
            for (int j = 0; j < enemyPlayer->ships[i].length; j++)
                fields.push_back(Field(enemyPlayer->ships[i].positions[j].row, enemyPlayer->ships[i].positions[j].col));
        }
    }

    // TODO: Wygeneruj tablice 2 wymiarowa, nastepnie nadpisuj stan kazdego z okienek. Uprosc stawianie statków.

    for (int i = 0; i < 10; i++) {
        if (i == 0) {
            cout << "  ";
            for (int j = 0; j < 10; j++) {
                cout << " " << j;
                if (j != 9)  cout << " |";
                else cout << endl;
            }
        }
        cout << alphabet[i] << " ";
        for (int j = 1; j <= 10; j++) {
            cout << " ";
            if (prepare) {
                // Ustawianie statków
                bool isShip = false;
                for (int k = 0; k < fields.size(); k++) {
                    if (fields[k].row == i && fields[k].col == j - 1) {
                        isShip = true;
                        break;
                    }
                }
                if (isShip) cout << "o";
                else cout << " ";
            }
            else {
                int isShoot = 0;
                for (int k = 0; k < currentPlayer->shots.size(); k++) {
                    if (currentPlayer->shots[k].row == i && currentPlayer->shots[k].col == j - 1) {
                        isShoot = 1;
                        for (int l = 0; l < fields.size(); l++) {
                            if (currentPlayer->shots[k].row == fields[l].row
                                && currentPlayer->shots[k].col == fields[l].col) {
                                isShoot = 2;
                                break;
                            }
                        }
                    }
                }

                if (isShoot == 1) cout << ".";
                else if (isShoot == 2) cout << "x";
                else cout << " ";
            }
            if (j != 10)  cout << " |";
            else cout << endl;
        }
        cout << "-----";
        for (int j = 1; j < 10; j++) {
            cout << "|---";
        }
        cout << endl;
    }
}

ShipPosition ShipsInConsole::getFieldToSetShip(const int& length) {
    string fieldID;
    int direction;
    int isCorrect = 1;
    int row = 0, col = 0;

    vector<Field> fields;
    for (int i = 0; i < currentPlayer->N; i++) {
        for (int j = 0; j < currentPlayer->ships[i].length; j++)
            fields.push_back(Field(currentPlayer->ships[i].positions[j].row, currentPlayer->ships[i].positions[j].col));
    }

    do {
        if (isCorrect == 2)
            cout << "Niepoprawne pole. Wpisz na przyklad A6." << endl;
        else if (isCorrect == 3)
            cout << "Nie ma takiego kierunku." << endl;
        else if (isCorrect == 4)
            cout << "Statek sie nie miesci na planszy." << endl;
        else if (isCorrect == 5)
            cout << "Probujesz postawic statek za blisko innego." << endl;

        cout << "Gracz " << currentPlayer->playerID << " ustawia teraz " << length << ". Podaj pole: ";
        cin >> fieldID;
        cout << "W ktorym kierunku? (1 - Poziomo, 2 - Pionowo): ";
        cin >> direction;

        row = 0;
        col = 0;
        isCorrect = 1;
        while (row < alphabet.length()) {
            if (fieldID[0] == alphabet[row])
                break;
            row++;
        }
        while (col < alphabet.length()) {
            if (static_cast<int>(fieldID[1]) - 48 == col)
                break;
            col++;
        }
        if (row == alphabet.length() || col == alphabet.length() || fieldID.length() != 2)
            isCorrect = 2;
        else if (direction != POZIOMO && direction != PIONOWO)
            isCorrect = 3;
        else if ((direction == POZIOMO && col + length > alphabet.length())
            || (direction == PIONOWO && row + length > alphabet.length()))
            isCorrect = 4;
        else {
            // Czy w polu +1 znajduje sie statek
            if (direction == POZIOMO) {
                for (int i = row, j = col - 1; j <= col + length; j++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int k = 0; k < fields.size(); k++) {
                            if (fields[k].row == i + dx && fields[k].col == j)
                                isCorrect = 5;
                        }
                    }
                }
            }
            else if (direction == PIONOWO) {
                for (int i = row - 1, j = col; i <= row + length; i++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        for (int k = 0; k < fields.size(); k++) {
                            if (fields[k].row == i && fields[k].col == j + dx)
                                isCorrect = 5;
                        }
                    }
                }
            }
        }
    } while (isCorrect != 1);


    return ShipPosition(row, col, static_cast<Direction>(direction), length);
}

Field ShipsInConsole::getFieldToShoot() {
    int isCorrect = 0;
    string fieldID;
    int row, col;

    do {
        if (isCorrect == 1)
            cout << "Niepoprawne pole. Sprobuj ponownie." << endl;
        else if (isCorrect == 2)
            cout << "Strzal juz zostal oddany w to pole. Sprobuj inne." << endl;
        cout << "Ruch gracza " << currentPlayer->playerID << endl;
        cout << "Podaj pole do strzalu: ";
        cin >> fieldID;

        // Walidacja pola czy istnieje literka i liczba
        isCorrect = 0;
        int validated = 0;
        for (int i = 0; i < alphabet.length(); i++) {
            if (fieldID[0] == alphabet[i])
                validated++;
            if (fieldID.length() == 2 && static_cast<int>(fieldID[1]) - 48 == i)
                validated++;
        }
        if (validated != 2)
            isCorrect = 1;

        // Sprawdziæ strza³ zosta³ oddany w to pole
        row = static_cast<int>(fieldID[0]) - 65;
        col = static_cast<int>(fieldID[1]) - 48;
        for (int i = 0; i < currentPlayer->shots.size(); i++) {
            if (row == currentPlayer->shots[i].row && col == currentPlayer->shots[i].col) {
                isCorrect = 2;
                break;
            }
        }

    } while (isCorrect != 0);

    return Field(row, col);
}

void ShipsInConsole::setPlayerNames() {
    cout << "Podaj nazwe gracza 1: ";
    cin >> p1.playerID;
    cout << "Podaj nazwe gracza 2: ";
    cin >> p2.playerID;
}

void ShipsInConsole::switchPlayer() {
    if (currentPlayer == &p1) {
        currentPlayer = &p2;
        enemyPlayer = &p1;
    }
    else {
        currentPlayer = &p1;
        enemyPlayer = &p2;
    }
}
