#pragma once
#include "Karta.h"
#include "Player.h"
class Kasyno
{
private:
	Karta talia[52];
	bool wydane_karty[52];
	int wydane;
	int p_num;
	Player* players;
	
public:
	void play();
	Kasyno();
	void pokaz();
	void shuffle();
	Karta* dajKarte();
	void save_game();

};

