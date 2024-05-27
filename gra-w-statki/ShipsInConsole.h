#pragma once

#include "Game.h"

class ShipsInConsole : public Game {
public:
	string alphabet;

	ShipsInConsole();
	void showBoard(bool);
	ShipPosition getFieldToSetShip(const int&);
	Field getFieldToShoot();
	void switchPlayer();
	void setPlayerNames();

private:
	ShipsInConsole& operator=(const ShipsInConsole& s);
};

