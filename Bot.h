#pragma once
#include "Player.h"
class Kasyno;
class Bot: public Player
{
	int odwaga;
	int number;
	
public:
	Bot() :Player(), odwaga(1) {
		static int bot_num;
		bot_num++;
		number = bot_num;
		std::cout << "bot_num: " << bot_num << std::endl;
	};
	void wezKarte(Karta* _karta);
	void set_odwaga(int odwaga) { this->odwaga = odwaga; };
	int get_odwaga() { return odwaga; };
	void set_name();
	void reset_stats();
};

