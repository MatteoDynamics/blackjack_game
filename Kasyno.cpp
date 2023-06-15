#include "Kasyno.h"
#include <cstdlib>
#include <ctime>
#include <random>
#include <fstream>
#include <iomanip>
#include "Player.h"
#define _CRT_SECURE_NO_WARNINGS
constexpr int risky = 3;
constexpr int normal = 2;
constexpr int safe = 1;
using namespace std;
#define talia_size 52
//ADD TEMPLETE TO CIN FUNCTION TO HAVE DIFFERENT TYPES
int Kasyno::ile_wydano() {
    return wydane;
}
bool all_players_passed(Player* players, Bot* bots, int p_num, int b_num);
void Kasyno::play()
{
    //PLAYER NUMBER INPUT
    alocate_players();
    alocate_bots();
    //NAME INPUT

    for (int i = 0; i < p_num; i++)
    {
        players[i].set_name();
        players[i].setKasyno(this);
    }


    init_table();

    for (int i = 0; i < p_num; i++)
    {
            players[i].show();
            cout << endl;
    }

    for (int i = 0; i < b_num; i++)
    {
        bots[i].set_name();
        bots[i].setKasyno(this);
    }

    for (int i = 0; i < b_num; i++)
    {
        bots[i].show();
        cout << endl;
    }
    /////////////////////////////////////////////////////////////////
    set_bot_risk();
    pass_or_not();
    
    who_won();
    //ile_wydano();
    new_game();
    
    
}
void Kasyno::new_game()
{
    while (true)
    {
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
            }delete[]players;
            for (int i = 0; i < b_num; i++)
            {
                bots[i].reset_stats();
            }delete[]bots;
            wydane = 0;
            play();
            break;
        }
        else
        {
            break;
        }
    }
}

void Kasyno::pass_or_not()
{
    while (true)
    {

        for (int i = 0; i < p_num; i++)
        {
            if (!players[i].pass_acc())
            {
                char choice;
                players[i].show();
                cout << "Player " << players[i].get_name() << " points: " << players[i].get_points() << std::endl;
                std::cout << "Player " << players[i].get_name() << ", czy dobierasz kartê ? (y / n) : ";
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
                    if (players[i].ammount_get() >= 10)
                    {
                        std::cerr << "Max cards is 10!";
                        return;
                    }
                    players[i].wezKarte(dajKarte());
                }
                else
                {
                    players[i].pass_set(true);
                }

            }
            

            players[i].show();
            cout << "points: " << players[i].get_points() << std::endl;
            cout << std::endl;
        }
        
        for (int i = 0; i < b_num; i++)
        {
            if (bots[i].ammount_get() >= 10)
            {
                std::cerr << "Max cards is 10!";
                return;
            }
            bots[i].wezKarte(dajKarte());
        }
        break;
    }
}

void Kasyno::who_won()
{
    bool all_pass = false;
    while (!all_pass)
    {
        all_pass = all_players_passed(players, bots, p_num, b_num);
        if (all_pass)
        {
            int max_points = -1;
            int winner = -1;
            int bot_winner = -1;
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
            for (int i = 0; i < b_num; i++)
            {
                int points = bots[i].get_points();
                if (points > max_points && points <= 21)
                {
                    max_points = points;
                    bot_winner = i;
                    winner = -1;
                    tie = false;
                }
                else if (points == max_points && points <= 21)
                {
                    tie = true;
                }
            }

            if (tie)
            {
                cout << "*****************************" << endl;
                std::cout << "Remis!" << std::endl;
                cout << "*****************************" << endl;
                std::cout << std::endl;
                std::cout << std::endl;
                show_table();
                break;
            }
            else if (winner >= 0)
            {
                cout << "*****************************" << endl;
                std::cout << players[winner].get_name() << " wygrywa!" << std::endl;
                cout << "*****************************" << endl;
                std::cout << std::endl;
                std::cout << std::endl;
                show_table();
                break;
            }
            else if (bot_winner >= 0)
            {
                cout << "*****************************" << endl;
                std::cout << "Bot " << bot_winner + 1 << " wygrywa!" << std::endl;
                cout << "*****************************" << endl;
                std::cout << std::endl;
                std::cout << std::endl;
                show_table();
                break;
            }
            break;
        }
        for (int i = 0; i < p_num; i++)
        {
            if (!players[i].pass_acc())
            {
                pass_or_not();
            }
        }
        for (int i = 0; i < b_num; i++)
        {
            if (!bots[i].pass_acc())
            {
                pass_or_not();
            }
        }
        show_table();
    }
}




void Kasyno::show_table()const
{
    std::cout << "TABLE SHOW" << endl;
    cout << "_____________________________" << endl;
    for (int i = 0; i < p_num; i++)
    {
        players[i].show();
    }

    for (int i = 0; i < b_num; i++)
    {
        bots[i].show();
    }
}

void Kasyno::set_bot_risk()
{
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
            for (int i = 0; i < b_num; i++)
            {
                bots[i].set_odwaga(risk);
            }
            break;
    }
}

bool all_players_passed(Player* players, Bot *bots, int p_num, int b_num)
{
    for (int i = 0; i < p_num; i++)
    {
        if (players[i].get_points()>21)
        {
            return true;
        }
        if (!players[i].pass_acc())
        {
            return false;
        }
    }
    for (int i = 0; i < b_num; i++)
    {
        if (bots[i].get_points() > 21)
        {
            return true;
        }
        if (!bots[i].pass_acc())
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
    if (file.fail())
    {
        std::cerr << "File couldnt be open";
        file.clear();
    }
    for (int i = 0; i < p_num; i++)
    {
        file << setw(20) << left << players[i].get_name();
        for (int j = 0; j < players[i].ammount_get(); j++)
        {
            file << players[i].return_cards(j)->getFigura() << (int)players[i].return_cards(j)->getKolor();
            // file << players[i].return_cards()->getKolor();
        }
        file << setw(20 - players[i].ammount_get() * 2) << right << players[i].get_points();
        file << endl;

    }

    for (int i = 0; i < b_num; i++)
    {
        file << setw(20) << left << bots[i].get_name();
        for (int j = 0; j < bots[i].ammount_get(); j++)
        {
            file << bots[i].return_cards(j)->getFigura() << (int)bots[i].return_cards(j)->getKolor();
            // file << players[i].return_cards()->getKolor();
        }
        file << setw(20 - bots[i].ammount_get() * 2) << right << bots[i].get_points();
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



