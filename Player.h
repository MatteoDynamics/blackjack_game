#pragma once
#include "Karta.h"
class Kasyno;
class Player
{
private:
	Karta* cards;
	int ammount;
	int points;
	bool pass;
public:
	bool pass_acc() { return pass; };
	void pass_set(bool passed) { pass = passed; };
	Player() : cards(nullptr), ammount(0), points(0), pass(false) {};
	void wezKarte(Karta* _karta);
	void show()const;
	int get_points();
	void setpoints(int point) { points = point; };
	void reset_stats()
	{	
		ammount = 0;
		points = 0;
		pass = false;
		delete[] cards;
		cards = nullptr;
	}
};
