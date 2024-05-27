#pragma once

#include <vector>
#include "Ship.h"

using namespace std;

class Player {
public:
	string playerID;					// Nazwa gracza
	static const int N;					// Iloœæ statków dla ka¿dego z graczy
	vector<Field> shots;				// Wspo³rzêdne oddanych strza³ów
	Ship* ships;                        // Przechowuje wskaŸniki do statków
	
public:
	Player();
	int getAliveShipsAmount();			// Zwraca iloœæ niezatopionych statków	
	~Player();
private:
	Player& operator=(const Player& s);
};

