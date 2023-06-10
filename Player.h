#pragma once
#include "Karta.h"
class Kasyno;
class Player
{

	std::string name;
	Karta** cards;
	Kasyno* kasyno;
	int ammount;
	int points;
	bool pass;
public:
	bool pass_acc() { return pass; };
	void pass_set(bool passed) { pass = passed; };
	Player() : cards(nullptr), ammount(0), points(0), pass(false) {};
	~Player()
	{
		if (cards != nullptr)
		{
			delete[] cards;
		}
	}
	Player(const Player& kopia) = delete;
	Player& operator=(const Player& przypisanie) = delete;
	void wezKarte(Karta* _karta);
	void show()const;
	int get_points() { return points; };
	void setpoints(int point) { points = point; };
	bool reset_stats();
	void set_name();
	void set_name(const std::string& name) { this->name = name; }
	std::string get_name() { return name; };
	Karta* return_cards(int index) { return cards[index]; };
	int ammount_get() { return ammount; };
	void add_points(int wartosc) { points += wartosc; };
	
};
