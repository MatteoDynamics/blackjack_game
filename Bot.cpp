#include "Bot.h"
#include "Kasyno.h"
#include "Karta.h"
//#include "Player.h"
#include <iostream>
#include <string>
constexpr int bot_types = 3;
constexpr int risky = 3;
constexpr int normal = 2;
constexpr int safe = 1;
int Bot::number = 0;
bool Bot::reset_stats()
{
	Player::reset_stats();
	odwaga = 1;
	number = 0;
	return true;
}

void Bot::wezKarte(Karta* _karta)
{
	if (odwaga == safe) 
	{
		if (get_points() <= 10) 
		{
			Player::wezKarte(_karta);
		}
		else
		{
			pass_set(true);
		}
	}
	else if (odwaga == normal) 
	{
		if (get_points() <= 12) 
		{
			Player::wezKarte(_karta);
		}
		else
		{
			pass_set(true);
		}
	}
	else if (odwaga == risky) 
	{
		if (get_points() <= 18)
		{
			Player::wezKarte(_karta);
		}
		else 
		{
			pass_set(true);
		}
	}
	
	
}



void Bot::set_name() {
	
	
	this->Player::set_name("Bot"+ std::to_string(number));
	
	
	
}




