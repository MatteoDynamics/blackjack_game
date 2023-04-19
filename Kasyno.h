#pragma once
#include "Karta.h"
#include "Player.h"
class Kasyno
{
private:
	Karta talia[52];
	Karta wydane_karty[52];
	int wydane = 0;
	
public:
	Player p1;
	Player p2;
	Kasyno();
	void pokaz();
	void shuffle();
	Karta* dajKarte();
};

