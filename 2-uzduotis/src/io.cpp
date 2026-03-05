#include "io.h"
#include "utils.h"
#include "timer.h"
#include "student.h"

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <ctime>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::getline;
using std::ifstream;
using std::left;
using std::numeric_limits;
using std::ofstream;
using std::right;
using std::setprecision;
using std::setw;
using std::sort;
using std::streamsize;
using std::string;
using std::stringstream;
using std::vector;

void outputas(vector<Studentas> grupe)
{
    int temp, t;
    cout << "Pasirinkite norimu formatu isvesti duomenis" << endl;
    cout << "1 - isvesti tik Vidurki\n2 - isvesti tik Mediana\n3 - isvesti ir Vidurki ir Mediana\n";
    intInput(temp);
    sortByUser(grupe, temp);
    cout << "Pasirinkite norima buda isvesti duomenis" << endl;
    cout << "1 - isvesti i konsole\n2 - isvesti i faila\n";
    intInput(t);
    switch (t)
    {
    case 1:
        duomenuIrasymasKonsole(grupe, temp);
        break;
    case 2:
        duomenuIrasymasFaile(grupe, temp, "Rezultatai.txt");
        break;
    default:
        break;
    }
}