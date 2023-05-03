#include "Bot.h"
#include "Karta.h"
//#include "Player.h"
#include <iostream>

constexpr int bot_types = 3;
constexpr int risky = 3;
constexpr int normal = 2;
constexpr int safe = 1;
Bot::Bot() :Player(),odwaga(0)
{
}
/*void Bot::wezKarte(Karta* _karta)
{
		if (odwaga == safe) {
			if (get_points() <= 10) {
				wezKarte(_karta);
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
}
*/



