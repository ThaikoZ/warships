#pragma once

#include "Engine.h"

class Game : public Engine {
public:
	bool isOn;

public:
	Game();
	void play();
protected:
	virtual void showBoard(bool) = 0;
	virtual ShipPosition getFieldToSetShip(const int&) = 0;
	virtual Field getFieldToShoot() = 0;
	virtual void switchPlayer() = 0;
	virtual void setPlayerNames() = 0;
private:
	Game& operator=(const Game& g);
};

