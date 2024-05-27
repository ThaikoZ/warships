#include "Player.h"

const int Player::N = 1;				

Player::Player() {
	ships = new Ship[N];
	playerID = "Player1";
}
Player::~Player() {
	delete[] ships;
}
int Player::getAliveShipsAmount() {
	int amount = 0;
	for (int i = 0; i < N; i++)
		if (ships[i].lives != 0)
			amount++;
	return amount;
}