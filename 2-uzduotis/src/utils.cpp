#include "utils.h"
#include <iostream>
#include <limits>
#include <cstdlib>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::numeric_limits;
using std::streamsize;
using std::rand;

const vector<string> vardai = {"Jonas", "Mantas", "Tomas", "Lukas", "Karolis", "Darius", "Paulius", "Mindaugas", "Justas", "Rokas",
                                         "Agne", "Ieva", "Egle", "Gabija", "Monika", "Karolina", "Viktorija", "Emilija", "Justina", "Greta"};

const vector<string> vyr_pavardes = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Zukauskas", "Butkus", "Pocius", "Urbonas", "Mockus", "Savickas"};

const vector<string> mot_pavardes = {"Kazlauskiene", "Jankauskiene", "Petrauskiene", "Stankeviciene", "Zukauskiene", "Butkiene", "Pociene", "Urboniene", "Mockiene", "Savickiene"};

void intInput(int& temp)
{
    int input;
    while (true)
    {
        if (cin >> input)
        {
            temp = input;
            return;
        }
        else
        {
            cout << "Netinkamas ivestis. Bandykite dar karta.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

void randomVardasPavarde(string& vardas, string& pavarde)
{
    vardas = vardai[rand() % vardai.size()];
    if (!vardas.empty() && vardas.back() == 's')
        pavarde = vyr_pavardes[rand() % vyr_pavardes.size()];
    else
        pavarde = mot_pavardes[rand() % mot_pavardes.size()];
}