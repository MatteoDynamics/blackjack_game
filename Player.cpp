#include "Player.h"
void Player::wezKarte(Karta* _karta) {
	if (ammount >= 10) {
		return; // Gracz nie mo¿e mieæ wiêcej ni¿ 10 kart
	}

	points += _karta->getWartosc();
	if (ammount == 0) {
		cards = new Karta[1];
		cards[0] = *_karta;
	}
	else {
		Karta* tmp = new Karta[ammount + 1];
		for (int i = 0; i < ammount; i++) {
			tmp[i] = cards[i];
		}
		tmp[ammount] = *_karta;
		delete[] cards;
		cards = tmp;

	}
	ammount++;
	
}


int Player::get_points()
{
	return points;
}


void Player::show() const
{
	for (int i = 0; i < ammount; i++)
	{
		cards[i].wypisz();
	}
}
