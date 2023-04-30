#include <iostream>
#include "Karta.h"
#include "Kasyno.h"
#define _CRT_SECURE_NO_WARNINGS	
using namespace std;

int main()
{
	std::locale pol("pl_PL");
	std::locale::global(pol);
	std::cout.imbue(pol);
	Kasyno k1;
	k1.play();
	k1.save_game();
	//std::cin.get();
	
	


}