#pragma once

#include "Ship.h"
#include "Player.h"
#include <vector>
#include <stdlib.h>

class Engine {
public:
	Player p1;
	Player p2;
	Player* currentPlayer;
	Player* enemyPlayer;

public:
	Engine();
	~Engine();
protected:
	bool checkWinCondition();
private:
	Engine& operator=(const Engine& e);
};

