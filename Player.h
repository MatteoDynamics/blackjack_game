#pragma once
#include "Karta.h"

class Player
{
private:
	Karta* cards;
	int ammount;
	int points;
public:
	Player() : cards(nullptr), ammount(0), points(0) {};
	void wezKarte(Karta* _karta);
	void show()const;
};
