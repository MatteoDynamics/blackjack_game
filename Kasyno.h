#pragma once
#include "Karta.h"
#include "Player.h"
#include "Bot.h"
class Kasyno
{
private:
	Karta talia[52];
	bool wydane_karty[52];
	int wydane;
	int p_num;
	int b_num;
	Player* players;
	Bot* bots;
	
public:
	void play();
	Kasyno();
	~Kasyno() { delete[] players; delete[] bots;}
	Kasyno(const Kasyno& kopia) = delete;
	Kasyno& operator=(const Kasyno& przypisanie) = delete;
	void pokaz();
	void shuffle();
	Karta* dajKarte();
	void save_game();
	int get_bnum() { return b_num; };
	void alocate_players();
	void alocate_bots();
	void init_table();
	void set_bot_risk();
	void show_table()const;
	void pass_or_not();
	void new_game();
	void who_won();
	int ret_wydane() { return wydane; };
};

