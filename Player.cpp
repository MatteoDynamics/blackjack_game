#include "Player.h"


void Player::wezKarte(Karta* _karta)
{
	Karta tmp[10];
	
	if (ammount >= 10)
	{
		return;
	}

	points = _karta->getWartosc();
	ammount++;
	
	for (int i = 0; i++; i < ammount)
	{
		tmp[i] = cards[i];
	}tmp[ammount-1] = *_karta;
	if(cards!=nullptr)free(cards);
	cards = new Karta[ammount];

	for (int i = 0;  i < ammount; i++)
	{
		cards[i] = tmp[i];
	}
	
}

void Player::show() const
{
	for (int i = 0; i < ammount; i++)
	{
		cards[i].wypisz();
	}
}
