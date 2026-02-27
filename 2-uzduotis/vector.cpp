#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <limits>
#include <fstream>
#include <sstream>
#include <chrono>

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

const vector<string> vardai = {"Jonas", "Mantas", "Tomas", "Lukas", "Karolis", "Darius", "Paulius", "Mindaugas", "Justas", "Rokas", "Agne", "Ieva", "Egle", "Gabija", "Monika", "Karolina", "Viktorija", "Emilija", "Justina", "Greta"};

const vector<string> vyr_pavardes = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Zukauskas", "Butkus", "Pocius", "Urbonas", "Mockus", "Savickas"};

const vector<string> mot_pavardes = {"Kazlauskiene", "Jankauskiene", "Petrauskiene", "Stankeviciene", "Zukauskiene", "Butkiene", "Pociene", "Urboniene", "Mockiene", "Savickiene"};

class Timer
{
    // usage of using
    using hrClock = std::chrono::high_resolution_clock;
    /// using std::chrono::high_resolution_clock;
    using durationDouble = std::chrono::duration<double>;

private:
    std::chrono::time_point<hrClock> start;

public:
    Timer() : start{hrClock::now()} {}
    void reset()
    {
        start = hrClock::now();
    }
    double elapsed() const
    {
        return durationDouble(hrClock::now() - start).count();
    }
};

struct Studentas
{
    string vardas = "A", pavarde = "BB";
    vector<int> paz;
    int egz;
    double vid, med;
};

void inputas(vector<Studentas> &grupe);
void outputas(vector<Studentas> grupe);
void MedVidSkaciavimas(Studentas &A, int sum);
void randomVardasPavarde(string &vardas, string &pavarde);
void fileRead(vector<Studentas> &grupe, string file_name);
void fileTest(vector<Studentas> &grupe, string file_name, int &testKiekis);
void sortByUser(vector<Studentas> &grupe, int temp);

void intInput(int &temp);

int main()
{
    vector<Studentas> grupe;
    inputas(grupe);
    outputas(grupe);
    return 0;
}

void outputas(vector<Studentas> grupe)
{
    int temp;
    cout << "Pasirinkite norima buda isvesti duomenis" << endl;
    cout << "1 - generuoti tik Vidurki\n2 - generuoti tik Mediana\n3 - generuoti ir Vidurki ir Mediana\n";
    intInput(temp);
    sortByUser(grupe, temp);
    cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavarde" << right << setw(20);
    if (temp == 1)
    {
        cout << right << setw(20) << "Galutinis (Vid.)" << endl;
        cout << left << setw(10) << "--------------------------------------------------------" << endl;
        for (auto A : grupe)
            cout << left << setw(10) << A.vardas << left << setw(20) << A.pavarde << right << setw(20) << fixed << setprecision(2) << A.vid << endl;
    }
    if (temp == 2)
    {
        cout << right << setw(20) << "Galutinis (Med.)" << endl;
        cout << left << setw(10) << "---------------------------------------------------------" << endl;
        for (auto A : grupe)
            cout << left << setw(10) << A.vardas << left << setw(20) << A.pavarde << right << setw(20) << fixed << setprecision(2) << A.med << endl;
    }
    if (temp == 3)
    {
        cout << right << setw(20) << "Galutinis (Vid.)" << right << setw(20) << "Galutinis (Med.)" << endl;
        cout << left << setw(10) << "----------------------------------------------------------------------" << endl;
        for (auto A : grupe)
            cout << left << setw(10) << A.vardas << left << setw(20) << A.pavarde << right << setw(20) << fixed << setprecision(2) << A.vid << right << setw(20) << A.med << endl;
    }
}

void inputas(vector<Studentas> &grupe)
{
    srand(time(NULL));
    Studentas A;

    while (true)
    {
        int t = 0;
        cout << "Pasirinkite norima buda ivesti duomenis" << endl;
        cout << "1 - ranka\n2 - generuoti tik pazymius\n3 - generuoti studentu vardus, pavardes ir pazymius\n4 - nuskaityti is failo\n5 - baigti darba\n";
        intInput(t);
        if (t == 1)
        {
            while (true)
            {
                cout << "Iveskite 0, kad baigti ivedinet duomenis" << endl;
                cout << "Iveskite varda ir pavarde: ";
                cin >> A.vardas;
                if (A.vardas == "0")
                    break;
                cin >> A.pavarde;
                char c = cin.peek(); // patikriname ar yra papildomu simboliu/zodziu
                if (c != '\n')       // jeigu ne eilutes pabaiga, vadinasi yra papildomu simboliu/zodziu
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ismesti likuti
                    cout << "Iveskite tik 2 zodzius (varda ir pavarde).\n";
                    continue;
                }

                cout << "Iveskite semestro ivercius. Kai baigsite iveskite 0" << endl;
                int sum = 0;
                int temp = -2;
                int i = 1;
                while (true)
                {
                    cout << "Iveskite " << i << " pazymi: ";
                    intInput(temp);
                    if (temp < 0 || temp > 10)
                    {
                        cout << "Pazymys turi buti tarp 1 ir 10. Bandykite dar karta." << endl;
                        continue;
                    }
                    if (temp == 0)
                        break;
                    A.paz.push_back(temp);
                    sum += temp;
                    i++;
                }
                while (true)
                {
                    cout << "Iveskite egzamino invertinima: ";
                    intInput(temp);
                    if (temp < 1 || temp > 10)
                    {
                        cout << "Pazymys turi buti tarp 1 ir 10. Bandykite dar karta." << endl;
                        continue;
                    }
                    break;
                }
                A.egz = temp;
                MedVidSkaciavimas(A, sum);
                grupe.push_back(A);
                A.paz.clear();
            }
        }
        if (t == 2)
        {
            while (true)
            {
                cout << "Iveskite 0, kad baigti ivedinet duomenis" << endl;
                cout << "Iveskite varda ir pavarde: ";
                cin >> A.vardas;
                if (A.vardas == "0")
                    break;
                cin >> A.pavarde;
                char c = cin.peek(); // patikriname ar yra papildomu simboliu/zodziu
                if (c != '\n')       // jeigu ne eilutes pabaiga, vadinasi yra papildomu simboliu/zodziu
                {
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ismesti likuti
                    cout << "Iveskite tik 2 zodzius (varda ir pavarde).\n";
                    continue;
                }
                int sum = 0, rand_paz;
                for (int i = 1; i <= 10; i++)
                {
                    rand_paz = rand() % 10 + 1;
                    cout << "Sugeneruotas " << i << " pazymys: " << rand_paz << endl;
                    A.paz.push_back(rand_paz);
                    sum += rand_paz;
                }
                rand_paz = rand() % 10 + 1;
                cout << "Sugeneruotas egzamino invertinimas: " << rand_paz << endl;
                A.egz = rand_paz;
                MedVidSkaciavimas(A, sum);
                grupe.push_back(A);
                A.paz.clear();
            }
        }
        if (t == 3)
        {
            for (int i = 1; i <= 10; i++)
            {
                randomVardasPavarde(A.vardas, A.pavarde);
                cout << "Sugeneruotas " << i << " vardas ir pavarde: " << A.vardas << " " << A.pavarde << endl;
                int sum = 0, rand_paz;
                for (int ii = 1; ii <= 10; ii++)
                {
                    rand_paz = rand() % 10 + 1;
                    cout << "Sugeneruotas " << ii << " pazymys: " << rand_paz << endl;
                    A.paz.push_back(rand_paz);
                    sum += rand_paz;
                }
                A.egz = rand() % 10 + 1;
                cout << "Sugeneruotas egzamino invertinimas: " << A.egz << endl;
                MedVidSkaciavimas(A, sum);
                grupe.push_back(A);
                A.paz.clear();
            }
        }
        if (t == 4)
        {
            int testKiekis = 5; //default
            double time = 0;
            cout << "Pasirinkite norima duomenu faila" << endl;
            cout << "1 - kursiokai.txt\n2 - studentai10000.txt\n3 - studentai100000.txt\n4 - studentai1000000.txt\n";
            intInput(t);
            Timer timer;
            switch (t)
            {
            case 1:
                fileTest(grupe, "kursiokai.txt", testKiekis);
                break;
            case 2:
                fileTest(grupe, "studentai10000.txt", testKiekis);
                break;
            case 3:
                fileTest(grupe, "studentai100000.txt", testKiekis);
                break;
            case 4:
                fileTest(grupe, "studentai1000000.txt", testKiekis);
                break;
            default:
                break;
            }
            time = timer.elapsed() / testKiekis;
            cout << "Vidutinis failo nuskaitymo laikas: " << fixed << setprecision(6) << time << " sekundes." << endl;
        }
        if (t == 5)
            break;
    }
}

void MedVidSkaciavimas(Studentas &A, int sum)
{
    int length = A.paz.size();
    if (length == 0)
    {
        A.med = A.egz * 0.6;
        A.vid = A.med;
        return;
    }
    sort(A.paz.begin(), A.paz.end());
    if (length % 2 == 0)
        A.med = (A.paz[length / 2 - 1] + A.paz[length / 2]) / 2.0 * 0.4 + A.egz * 0.6;
    else
        A.med = A.paz[length / 2] * 0.4 + A.egz * 0.6;
    A.vid = sum * 1.0 / (length * 1.0) * 0.4 + A.egz * 0.6;
}

void randomVardasPavarde(string &vardas, string &pavarde)
{
    vardas = vardai[rand() % vardai.size()];
    if (vardas.back() == 's')
        pavarde = vyr_pavardes[rand() % vyr_pavardes.size()];
    else
        pavarde = mot_pavardes[rand() % mot_pavardes.size()];
}

void intInput(int &temp)
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
            cout << "Netinkamas ivestis. Bandykite dar karta." << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // atminties isvalymas
        }
    }
}

void fileTest(vector<Studentas> &grupe, string file_name, int &testKiekis)
{
    cout << "Kiek kartu norite patestuoti faila: " << endl;
    cin >> testKiekis;
    vector<Studentas> temp_grupe; // testinimui sukuriame laikina vektoriu, kad nebutu itakos originaliam grupe vektoriui, nes fileRead funkcija modifikuoja perduodama vektoriu
    fileRead(grupe, file_name);
    for (int i = 0; i < testKiekis - 1; i++)
    {
        fileRead(temp_grupe, file_name);
        temp_grupe.clear();
    }
}

void fileRead(vector<Studentas> &grupe, string file_name)
{
    Studentas A;
    string temp;
    int balas;
    ifstream duomenys(file_name);
    if (duomenys.is_open())
    {
        getline(duomenys, temp); // skip header
        while (!duomenys.eof())
        {
            duomenys >> A.vardas >> A.pavarde;
            getline(duomenys, temp);
            stringstream x(temp);
            int sum = 0;
            while (x >> balas)
            {
                if (x.eof())
                    A.egz = balas;
                else
                {
                    A.paz.push_back(balas);
                    sum += balas;
                }
            }
            MedVidSkaciavimas(A, sum);
            grupe.push_back(A);
            A.paz.clear();
        }
        duomenys.close();
    }
    else
    {
        cout << "Klaida atidarant faila" << endl;
        return;
    }
}

void sortByUser(vector<Studentas> &grupe, int temp)
{
    int t;
    cout << "Pasirinkite pagal ka rikiuoti studentus" << endl;
    while (true)
    {
        if (temp == 1)
        {
            cout << "1 - pagal varda\n2 - pagal pavarde\n3 - pagal galutini (Vid.)\n";
            intInput(t);
            if (t == 4)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            break;
        }
        if (temp == 2)
        {
            cout << "1 - pagal varda\n2 - pagal pavarde\n3 - pagal galutini (Vid.)\n";
            intInput(t);
            if (t == 4)
            {
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }
            if (t == 3)
            {
                t = 4;
                break;
            }
            break;
        }
        if (temp == 3)
        {
            cout << "1 - pagal varda\n2 - pagal pavarde\n3 - pagal galutini (Vid.)\n4 - pagal galutini (Med.)\n";
            intInput(t);
            break;
        }
    }
    switch (t)
    {
    case 1:
        sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b)
             { return a.vardas < b.vardas; });
        break;
    case 2:
        sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b)
             { return a.pavarde < b.pavarde; });
        break;
    case 3:
        sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b)
             { return a.vid > b.vid; });
        break;
    case 4:
        sort(grupe.begin(), grupe.end(), [](const Studentas &a, const Studentas &b)
             { return a.med > b.med; });
        break;
    default:
        break;
    }
}