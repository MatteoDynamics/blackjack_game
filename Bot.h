#pragma once
#include "Player.h"
class Kasyno;
class Bot: public Player
{
	int odwaga=1;
public:
	Bot();
	//void wezKarte(Karta* _karta);
	void set_odwaga(int odwaga) { this->odwaga = odwaga; };
	int get_odwaga() { return odwaga; };
};

