#include "Kasyno.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <fstream>
#include <iomanip>


#define talia_size 52
//ADD TEMPLETE TO CIN FUNCTION TO HAVE DIFFERENT TYPES

void Kasyno::play()
{

    shuffle();
    for (int i=0; i<2; i++)
    p1.wezKarte(dajKarte());
    for (int i = 0; i < 2; i++)
    p2.wezKarte(dajKarte());
    
    p1.set_name("Matteo");
    p2.set_name("Lampa");
    
   
    while (true)
    {
 
        if (!p1.pass_acc())
        {
            p1.show();
            std::cout << std::endl;
            std::cout << "Gracz 1, czy dobierasz kartê? (t/n): ";
            char choice;
            while (1)
            {
                std::cin >> choice;
                if (std::cin.fail() == true)
                {
                    std::cout << "wrong input, type again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max()
                        , '\n');
                }
                else break;
            }
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
            while (1)
            {
                std::cin >> choice;
                if (std::cin.fail() == true)
                {
                    std::cout << "wrong input, type again" << std::endl;
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max()
                        , '\n');
                }
                else break;
            }
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
void Kasyno::save_game()
{
    std::ofstream file;
    file.open("C:\\Users\\Matteo\\source\\repos\\blackjack_game\\blackjack_game\\save.txt", std::ofstream::out);
    file << std::left << std::setw(20) << p1.get_name() ;
    
    for (int i = 0; i < p1.ammount_get(); i++)
    {
        file << std::left << p1.return_cards()[i].getFigura() << p1.return_cards()[i].getKolor();
    }
  
    file <<std::right<< std::setw(20 - p1.ammount_get() * 2) << p1.get_points() << std::endl;






    file << std::left << std::setw(20) << p2.get_name();

    for (int i = 0; i < p2.ammount_get(); i++)
    {
        file << std::left << p2.return_cards()[i].getFigura() << p2.return_cards()[i].getKolor();
    }

    file << std::right << std::setw(20 - p2.ammount_get() * 2) << p2.get_points() << std::endl;

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



