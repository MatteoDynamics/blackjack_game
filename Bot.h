#pragma once
#include "Player.h"
//class Kasyno;
class Bot: public Player
{
	int odwaga;
	static int number;
	
public:
	Bot() :Player(), odwaga(1) {
		
		static_inc();
		std::cout << "bot_num: " << number << std::endl;
		
		
	};
	void wezKarte(Karta* _karta);
	void set_odwaga(int odwaga) { this->odwaga = odwaga; };
	int get_odwaga() { return odwaga; };
	void set_name();
	bool reset_stats();
	static void static_inc() {
		number++;
	}
};

