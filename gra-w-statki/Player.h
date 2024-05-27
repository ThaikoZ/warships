#pragma once

#include <vector>
#include "Ship.h"

using namespace std;

class Player {
public:
	string playerID;					// Nazwa gracza
	static const int N;					// Ilo�� statk�w dla ka�dego z graczy
	vector<Field> shots;				// Wspo�rz�dne oddanych strza��w
	Ship* ships;                        // Przechowuje wska�niki do statk�w
	
public:
	Player();
	int getAliveShipsAmount();			// Zwraca ilo�� niezatopionych statk�w	
	~Player();
private:
	Player& operator=(const Player& s);
};

