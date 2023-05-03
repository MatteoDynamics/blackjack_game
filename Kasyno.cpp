#include "Kasyno.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <fstream>
#include <iomanip>
constexpr int risky = 3;
constexpr int normal = 2;
constexpr int safe = 1;
using namespace std;
#define talia_size 52
//ADD TEMPLETE TO CIN FUNCTION TO HAVE DIFFERENT TYPES
bool all_players_passed(Player* players, int p_num);
void Kasyno::play()
{
    //PLAYER NUMBER INPUT
    alocate_players();
    alocate_bots();
    //NAME INPUT

    for (int i = 0; i < p_num; i++)
    {
        players[i].set_name();
    }

    cout << "type bot risk lvl---> 1lowest risk---> 3 highest risk?: " << endl;
    int risk;
    while (1)
    {
        
        std::cin >> risk;
        if (std::cin.fail() == true || risk > 3 || risk < 1)
        {
            std::cout << "wrong input, type again, players <1,3>" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max()
                , '\n');
        }
        else
        break;
    }


    init_table();

    for (int i = 0; i < p_num; i++)
    {
            players[i].show();
            cout << endl;
    }

    for (int i = 0; i < b_num; i++)
    {
        bots[i].show();
        cout << endl;
    }
    /////////////////////////////////////////////////////////////////

    while (true)
    {
        
        for (int i = 0; i < p_num; i++)
        {
            if (!players[i].pass_acc())
            {
                char choice;
                players[i].show();
                cout << "Player "<<players[i].get_name()<<" points: " << players[i].get_points() << std::endl;
                std::cout << "Player "<<i<<", czy dobierasz kartê ? (y / n) : ";
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

                if (choice == 'y')
                {
                    players[i].wezKarte(dajKarte());
                }
                else
                {
                    players[i].pass_set(true);
                }
                
            }
            
            players[i].show();
            cout << std::endl;
            cout << "points: " << players[i].get_points() << std::endl;

            if (all_players_passed(players, p_num))
            {
                int max_points = -1;
                int winner = -1;
                bool tie = false;
                for (int i = 0; i < p_num; i++)
                {
                    int points = players[i].get_points();
                    if (points > max_points && points <= 21)
                    {
                        max_points = points;
                        winner = i;
                        tie = false;
                    }
                    else if (points == max_points && points <= 21)
                    {
                        tie = true;
                    }
                }

                if (tie)
                {
                    std::cout << "Remis!" << std::endl;
                }
                else
                {
                    std::cout << players[winner].get_name() << winner +1 << " wygrywa!" << std::endl;
                }
            }

        }
        bool new_game = false;
        char choice;
        std::cout << "New game? ";
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

        if (choice == 'y')
        {
            for (int i = 0; i < p_num; i++)
            {
                players[i].reset_stats();
            }
            play();
        }
        else
        {
            break;
        }
    }
    //delete[] players;
   // delete[] bots;
}

bool all_players_passed(Player* players, int p_num)
{
    for (int i = 0; i < p_num; i++)
    {
        if (!players[i].pass_acc())
        {
            return false;
        }
    }
    return true;
}

void Kasyno::init_table()
{
    for (int i = 0; i < p_num; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            players[i].wezKarte(dajKarte());
        }
    }

    for (int i = 0; i < b_num; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            bots[i].wezKarte(dajKarte());
            
        }
    }
}

void Kasyno::alocate_players()
{
    cout << "how many players?: " << endl;
    while (1)
    {
        std::cin >> p_num;
        if (std::cin.fail() == true || p_num > 3 || p_num < 1)
        {
            std::cout << "wrong input, type again, players <1,3>" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max()
                , '\n');
        }
        else break;
    }
    players = new Player[p_num];
    if (players == nullptr)
    {
        return;
    }
}

void Kasyno::alocate_bots()
{
    cout << "how many bots?: " << endl;
    while (1)
    {
        std::cin >> b_num;
        if (std::cin.fail() == true || b_num > 3 || b_num < 1)
        {
            std::cout << "wrong input, type again, players <1,3>" << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max()
                , '\n');
        }
        else break;
    }
    bots = new Bot[b_num];
    if (bots == nullptr)
    {
        return;
    }
}


void Kasyno::save_game()
{
    std::ofstream file;
    file.open("save.txt", ofstream::out);
    for (int i = 0; i < p_num; i++)
    {
        file << setw(20) << left << players[i].get_name();
        for (int j = 0; j < players[i].ammount_get(); j++)
        {
            file << players[i].return_cards(j)->getFigura() << (int)players[i].return_cards(j)->getKolor();
           // file << players[i].return_cards()->getKolor();
        }
        file << setw(20- players[i].ammount_get()*2) << right << players[i].get_points();
        file << endl;
        
    }
    file.close();
}


Kasyno::Kasyno() : talia(), wydane_karty(), wydane(0), p_num(0), b_num(0), players(nullptr), bots(nullptr)
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
    srand(time_t(NULL));
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



