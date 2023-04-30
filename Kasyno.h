#pragma once
#include "Karta.h"
#include "Player.h"
class Kasyno
{
private:
	Karta talia[52];
	bool wydane_karty[52] = { false };
	int wydane = 0;
	
public:
	void play();
	Player p1;
	Player p2;
	Kasyno();
	void pokaz();
	void shuffle();
	Karta* dajKarte();
	void save_game();

};

