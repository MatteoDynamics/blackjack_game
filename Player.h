#pragma once
#include "Karta.h"
class Player
{
private:
	std::string name;
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
	void reset_stats();
	void set_name(const std::string&name);
	std::string get_name() { return name; };
	Karta* return_cards(int index) { return &cards[index]; };
	int ammount_get() { return ammount; };
	
};
