#include "Kasyno.h"
#include <cstdlib>
#include <ctime>
#define talia_size 52

Kasyno::Kasyno(): p1(), p2()
{
    int index = 0;
    for (int k = 0; k < 4; k++) {
        for (int w = 0; w < 13; w++) {
            talia[index] = Karta(k, w);
            index++;
        }
    }
}

void Kasyno::pokaz()
{
    for (int i = 0; i < talia_size; i++)
    {
        std::cout << " |";
        talia[i].wypisz();
        std::cout << "| ";
    }
}

void Kasyno::shuffle()
{
    srand(time(NULL));
    int los1,los2;
    for (int i = 0; i < 100; i++) //shuffle
    {
        Karta temp;
        los1 = rand() % 52;
        temp = talia[los1];
        los2 = rand() % 52;
        talia[los1] = talia[los2];
        talia[los2] = temp;
    }
}

Karta* Kasyno::dajKarte()
{
    if (wydane == talia_size) {
        std::cerr << "Brak kart w talii!";
        return nullptr;
    }
    int los;
    los = rand() % talia_size;
    wydane++;
    talia[los].wypisz();
    return &talia[los];
}

