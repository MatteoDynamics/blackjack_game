#include "Bot.h"
#include "Karta.h"
//#include "Player.h"
#include <iostream>
#include "Kasyno.h"
#include <string>
constexpr int bot_types = 3;
constexpr int risky = 3;
constexpr int normal = 2;
constexpr int safe = 1;

void Bot::reset_stats()
{
	Player::reset_stats();
	odwaga = 1;
	number = 0;
}

void Bot::wezKarte(Karta* _karta)
{
	if (odwaga == safe) {
		if (get_points() <= 5) {
			Player::wezKarte(_karta);
			//add_points(_karta->getWartosc());
		}
	}
	else if (odwaga == normal) {
		if (get_points() <= 12) {
			wezKarte(_karta);
		}
	}
	else if (odwaga == risky) {
		wezKarte(_karta);
	}
	else {
		pass_set(true);
	}
	
}



void Bot::set_name() {
	
	
	this->Player::set_name("Bot"+ std::to_string(number));
	
	
	
}




