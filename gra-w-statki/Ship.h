#pragma once

#include <utility>
#include <iostream>

enum Direction {
	POZIOMO = 1,
	PIONOWO,
};

struct ShipPosition {
	int row;
	int col;
	Direction direction;
	int length;

	ShipPosition(int, int, Direction, int);
};

struct Field {
	int row;
	int col;

	Field();
	Field(int, int);
};

class Ship {
public:
	int length;                     // D³ugoœæ statku
	int lives;                      // Ilosc pozosta³ych niezatopionych czêœci
	Field* positions;               // Tablica pozycji
	Direction direction;			// Orientacja statku (POZIOMO / PIONOWO)

public:
	Ship();
	// Przypisuje d³ugoœæ i pozycje gdzie znajduje siê statek
	void setShip(ShipPosition);
	// Sprawdza czy statek zosta³ trafiony
	bool isHitted(Field);
	// Po trafieniu. Zmniejsza ilosc zyc o 1
	void hitted();
	// Zwraca czy statek jest zatopiony
	bool isDestroyed();
	~Ship();
private:
	Ship& operator=(const Ship& s);
};

