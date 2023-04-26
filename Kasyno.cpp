#include "Kasyno.h"
#include <cstdlib>
#include <ctime>
#include <random>
#define talia_size 52

void Kasyno::play()
{
    shuffle();
    std::cout << std::endl;
    std::cout << "punkty: " << p1.get_points() << std::endl;
    std::cout << std::endl; std::cout << std::endl;
    std::cout << "punkty: " << p2.get_points() << std::endl;
    std::cout << std::endl;
    
    p1.wezKarte(dajKarte());
    p1.wezKarte(dajKarte());
    p2.wezKarte(dajKarte());
    p2.wezKarte(dajKarte());

   
    while (true)
    {
 
        if (!p1.pass_acc())
        {
            p1.show();
            std::cout << std::endl;
            std::cout << "Gracz 1, czy dobierasz kartê? (t/n): ";
            char choice;
            std::cin >> choice;
            if (choice == 't')
            {
                p1.wezKarte(dajKarte());
            }
            else
            {
                p1.pass_set(true);
            }
            p1.show();
            std::cout << std::endl;
            std::cout << "punkty: " << p1.get_points()<<std::endl;
            std::cout << std::endl;
            
        }

        
        if (!p2.pass_acc())
        {
            p2.show();

            std::cout << std::endl;
            std::cout << "Gracz 2, czy dobierasz kartê? (t/n): ";
            char choice;
            std::cin >> choice;
            if (choice == 't')
            {
                p2.wezKarte(dajKarte());
            }
            else
            {
                p2.pass_set(true);
            }
            p2.show();
            std::cout << std::endl;
            std::cout << "punkty: " << p2.get_points() << std::endl;
            std::cout << std::endl;
        }

       
        if (p1.get_points() > 21)
        {
            std::cout << "Gracz 2 wygrywa!" << std::endl;
            break;
        }
        if (p2.get_points() > 21)
        {
            std::cout << "Gracz 1 wygrywa!" << std::endl;
            break;
        }

        
        if (p1.pass_acc() && p2.pass_acc())
        {
            if (p1.get_points() == 21 || p1.get_points() > p2.get_points() && p1.get_points() <= 21 || p2.get_points() > 21)
            {
                std::cout << "Gracz 1 wygrywa!" << std::endl;
            }
            else if (p2.get_points() == 21 || p2.get_points() > p1.get_points() && p2.get_points() <= 21 || p1.get_points() > 21)
            {
                std::cout << "Gracz 2 wygrywa!" << std::endl;
            }
            else
            {
                std::cout << "Remis!" << std::endl;
            }
            break;
        }
        
    }

    
    std::cout << "New Game(y/n)?" << std::endl;
    char new_game;
    std::cin >> new_game;
    if (new_game == 'y')
    {
        shuffle();
        this->p1.reset_stats();
        this->p2.reset_stats();
        this->play();
    }
    else
    {
        return;
    }
    
    
}


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
    for (int i = 0; i < 100; i++) 
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

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dis(0, talia_size - 1);
    int los;

    do {
        los = dis(gen);
    } while (wydane_karty[los]);
    wydane_karty[los] = true;
    wydane++;

    return &talia[los];
}



