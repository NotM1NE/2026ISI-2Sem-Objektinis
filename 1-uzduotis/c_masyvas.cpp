#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::left;
using std::right;
using std::setprecision;
using std::setw;
using std::sort;
using std::string;
using std::vector;

const string vardai[] = {"Jonas", "Mantas", "Tomas", "Lukas", "Karolis", "Darius", "Paulius", "Mindaugas", "Justas", "Rokas", "Agne", "Ieva", "Egle", "Gabija", "Monika", "Karolina", "Viktorija", "Emilija", "Justina", "Greta"};

const string vyr_pavardes[] = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Zukauskas", "Butkus", "Pocius", "Urbonas", "Mockus", "Savickas"};

const string mot_pavardes[] = {"Kazlauskiene", "Jankauskiene", "Petrauskiene", "Stankeviciene", "Zukauskiene", "Butkiene", "Pociene", "Urboniene", "Mockiene", "Savickiene"};

const int N = 100; // maks paz ir studentu kiekis

struct Studentas
{
    string vardas = "A", pavarde = "BB";
    double C[N];
    int egz;
    double vid, med;
};

void inputas(Studentas grupe[], int &n);
void outputas(Studentas grupe[], int n);
void MedVidSkaciavimas(Studentas grupe[], int n, int length, int sum);
void randomVardasPavarde(string &vardas, string &pavarde);

int main()
{
    Studentas grupe[N];
    int n;
    inputas(grupe, n);
    outputas(grupe, n);
    return 0;
}

void outputas(Studentas grupe[], int n)
{
    int temp;
    cout << "Pasirinkite norima buda isvesti duomenis" << endl;
    cout << "1 - generuoti tik Vidurki\n2 - generuoti tik Mediana\n3 - generuoti ir Vidurki ir Mediana\n";
    cin >> temp;

    cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavarde" << right << setw(20);
    if (temp == 1)
    {
        cout << right << setw(20) << "Galutinis (Vid.)" << endl;
        cout << left << setw(10) << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
            cout << left << setw(10) << grupe[i].vardas << left << setw(20) << grupe[i].pavarde << right << setw(20) << fixed << setprecision(2) << grupe[i].vid << endl;
    }
    if (temp == 2)
    {
        cout << right << setw(20) << "Galutinis (Med.)" << endl;
        cout << left << setw(10) << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
            cout << left << setw(10) << grupe[i].vardas << left << setw(20) << grupe[i].pavarde << right << setw(20) << fixed << setprecision(2) << grupe[i].med << endl;
    }
    if (temp == 3)
    {
        cout<< right << setw(20) << "Galutinis (Vid.)" << right << setw(20) << "Galutinis (Med.)" << endl;
        cout << left << setw(10) << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
            cout << left << setw(10) << grupe[i].vardas << left << setw(20) << grupe[i].pavarde << right << setw(20) << fixed << setprecision(2) << grupe[i].vid << right << setw(20) << grupe[i].med << endl;
    }
}

void inputas(Studentas grupe[], int &n)
{
    srand(time(NULL));
    n = 0;
    while (true)
    {
        int t = 0;
        cout << "Pasirinkite norima buda ivesti duomenis" << endl;
        cout << "1 - ranka\n2 - generuoti tik pazymius\n3 - generuoti studentu vardus, pavardes ir pazymius\n4 - baigti darba\n";
        cin >> t;
        if (t == 1)
        {
            while (true)
            {
                cout << "Iveskite 0, kad baigti ivedinet duomenis" << endl;
                cout << "Iveskite varda ir pavarde: ";
                cin >> grupe[n].vardas;
                if (grupe[n].vardas == "0")
                    break;

                cin >> grupe[n].pavarde;
                cout << "Iveskite semestro ivercius. Kai baigsite iveskite 0" << endl;
                int sum = 0;
                int temp = -2;
                int i = 0;
                while (true)
                {
                    cout << "Iveskite " << i + 1 << " pazymi: ";
                    cin >> temp;
                    if (temp == 0)
                        break;
                    grupe[n].C[i] = temp;
                    sum += temp;
                    i++;
                }
                cout << "Iveskite egzamino invertinima: ";
                cin >> grupe[N].egz;
                MedVidSkaciavimas(grupe, n, i, sum);
                n++;
                if (n >= N)
                {
                    cout << "Pasiektas maksimalus studentu skaicius" << endl;
                    break;
                }
            }
        }
        if (t == 2)
        {
            while (true)
            {
                cout << "Iveskite 0, kad baigti ivedinet duomenis" << endl;
                cout << "Iveskite varda ir pavarde: ";
                cin >> grupe[n].vardas;
                if (grupe[n].vardas == "0")
                    break;
                cin >> grupe[n].pavarde;
                int sum = 0,
                    rand_paz,
                    length = 10;
                for (int i = 1; i <= length; i++)
                {
                    rand_paz = rand() % 10 + 1;
                    grupe[n].C[i - 1] = rand_paz;
                    cout << "Sugeneruotas " << i << " pazymys: " << grupe[n].C[i - 1] << endl;
                    sum += rand_paz;
                }
                rand_paz = rand() % 10 + 1;
                cout << "Sugeneruotas egzamino invertinimas: " << rand_paz << endl;
                MedVidSkaciavimas(grupe, n, length, sum);
                n++;
                if (n >= N)
                {
                    cout << "Pasiektas maksimalus studentu skaicius" << endl;
                    break;
                }
            }
        }
        if (t == 3)
        {
            for (int i = 1; i <= 10; i++)
            {
                randomVardasPavarde(grupe[n].vardas, grupe[n].pavarde);
                cout << "Sugeneruotas " << i << " vardas ir pavarde: " << grupe[n].vardas << " " << grupe[n].pavarde << endl;
                int sum = 0,
                    rand_paz,
                    length = 10;
                for (int ii = 1; ii <= length; ii++)
                {
                    rand_paz = rand() % 10 + 1;
                    grupe[n].C[ii - 1] = rand_paz;
                    cout << "Sugeneruotas " << ii << " pazymys: " << grupe[n].C[i - 1] << endl;
                    sum += rand_paz;
                }
                grupe[n].egz = rand() % 10 + 1;
                cout << "Sugeneruotas egzamino invertinimas: " << grupe[n].egz << endl;
                MedVidSkaciavimas(grupe, n, length, sum);
                n++;
                if (n >= N)
                {
                    cout << "Pasiektas maksimalus studentu skaicius" << endl;
                    break;
                }
            }
        }
        if (t == 4)
            break;
    }
}

void MedVidSkaciavimas(Studentas grupe[], int n, int length, int sum = 0)
{

    if (length == 0)
    {
        grupe[n].med = grupe[n].egz * 0.6;
        grupe[n].vid = grupe[n].med;
        return;
    }
    sort(grupe[n].C, grupe[n].C + length);
    if (length % 2 == 0)
        grupe[n].med = (grupe[n].C[length / 2 - 1] + grupe[n].C[length / 2]) / 2.0 * 0.4 + grupe[n].egz * 0.6;
    else
        grupe[n].med = grupe[n].C[length / 2] * 0.4 + grupe[n].egz * 0.6;
    grupe[n].vid = sum * 1.0 / (length * 1.0) * 0.4 + grupe[n].egz * 0.6;
}

void randomVardasPavarde(string &vardas, string &pavarde)
{
    vardas = vardai[rand() % sizeof(vardai) / sizeof(vardai[0])];
    if (vardas.back() == 's')
        pavarde = vyr_pavardes[rand() % sizeof(vyr_pavardes) / sizeof(vyr_pavardes[0])];
    else
        pavarde = mot_pavardes[rand() % sizeof(mot_pavardes) / sizeof(mot_pavardes[0])];
}
