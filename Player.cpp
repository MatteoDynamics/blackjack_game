#include "Player.h"
#include"Kasyno.h"
void Player::set_name()
{
	std::cout << "Type name: " << std::endl;
	std::string name;
	while (1)
	{
		std::cin >> name;
		if (std::cin.fail() == true)
		{
			std::cout << "wrong input, type again" << std::endl;
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max()
				, '\n');
		}
		else
			this->name = name;
		break;
	}
	
}

bool Player::reset_stats() {
	ammount = 0;
	points = 0;
	pass = false;
	for (int i = 0; i < ammount; i++) {
		delete cards[i];
	}
	delete[] cards;
	cards = nullptr;
	return true;
}


void Player::wezKarte(Karta* _karta) {

	//if (kasyno->ret_wydane() == 52)
	//{
	//	std::cerr << "Brak kart w talii!";//wszystkie karty wydane
//		return; 
//	}
	points += _karta->getWartosc();

	if (ammount == 0) {
		cards = new Karta*[1];
		cards[0] = _karta;
	}
	else {
		Karta** tmp = new Karta * [ammount + 1];
		for (int i = 0; i < ammount; i++) {
			tmp[i] = cards[i];
		}
		tmp[ammount] = _karta;
		delete[] cards;
		cards = tmp;
	}
	ammount++;
}




void Player::show() const {
	std::cout << name << std::endl;
	for (int i = 0; i < ammount; i++) {
		cards[i]->wypisz();
	}
	std::cout << "Punkty: " << points << std::endl << std::endl;
}

