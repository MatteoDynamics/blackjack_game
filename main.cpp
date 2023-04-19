#include <iostream>
#include "Karta.h"
#include "Kasyno.h"
#define _CRT_SECURE_NO_WARNINGS	
using namespace std;

int main()
{
	Kasyno k1;
	k1.pokaz();
	k1.shuffle();
	cout << endl;
	cout << endl;
	k1.pokaz();
	k1.p1.wezKarte(k1.dajKarte());
	cout << endl;
	k1.p1.show();
}