#include "Ship.h"

ShipPosition::ShipPosition(int row, int col, Direction direction, int length) {
    this->row = row;
    this->col = col;
    this->direction = direction;
    this->length = length;
}
Field::Field(int row, int col) {
    this->row = row;
    this->col = col;
}
Field::Field() {
    row = -1;
    col = -1;
}

void Ship::setShip(ShipPosition sp) {
    this->length = sp.length;
    lives = sp.length;
    direction = sp.direction;
    positions = new Field[length];
    for (int i = 0; i < sp.length; i++) {
        positions[i] = { sp.row, sp.col };
        if (sp.direction == POZIOMO)
            sp.col++;
        else
            sp.row++;
    }
}

Ship::Ship() {
    lives = 0;
    length = 0;
    positions = nullptr;
}
Ship::~Ship() {
    delete[] positions;
}

bool Ship::isHitted(Field position) {
    for (int i = 0; i < length; i++)
        if (positions[i].row == position.row && positions[i].col == position.col)
            return true;
    return false;
}

void Ship::hitted() {
    lives--;
}

bool Ship::isDestroyed() {
    if (lives == 0) {
        std::cout << "destroyed" << std::endl;
    }
    return lives == 0;
}



