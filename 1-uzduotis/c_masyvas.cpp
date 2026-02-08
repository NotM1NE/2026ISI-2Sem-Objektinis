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
    cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavarde" << right << setw(20) << "Galutinis (Vid.)" << right << setw(20) << "Galutinis (Med.)" << endl;
    cout << left << setw(10) << "----------------------------------------------------------------------" << endl;
    for (int i = 0; i < n; i++)
        cout << left << setw(10) << grupe[i].vardas << left << setw(20) << grupe[i].pavarde << right << setw(20) << fixed << setprecision(2) << grupe[i].vid << right << setw(20) << grupe[i].med << endl;
}

void inputas(Studentas grupe[], int &n)
{
    srand(time(NULL));
    n = 0;
    while (true)
    {
        if (n >= N)
        {
            cout << "Pasiektas maksimalus studentu kiekis: " << N << endl;
            break;
        }
        cout << "Iveskite 0, kad baigsite iveskite duomenis" << endl;
        cout << "Iveskite varda ir pavarde: ";
        cin >> grupe[n].vardas;
        if (grupe[n].vardas == "0")
            break;
        cin >> grupe[n].pavarde;
        cout << "Iveskite semestro ivercius. Kai baigsite iveskite 0" << endl;
        cout << "Jeigu pageidaujate, kad pazymiai butu atsitiktiniai, iveskite -1" << endl;
        int sum = 0;
        int temp = -1;
        int i = 0;
        while (true)
        {
            if (i >= N)
            {
                cout << "Pasiektas maksimalus pazymiu kiekis: " << N << endl;
                break;
            }
            cout << "Iveskite " << i + 1 << " pazymi: ";
            cin >> temp;
            if(temp == -1)
            {
                temp = rand() % 10 + 1;
                cout << "Sugeneruotas pazymys: " << temp << endl;
            }
            if (temp == 0)
                break;
            grupe[n].C[i] = temp;
            sum += temp;
            i++;
        }
        cout << "Jeigu pageidaujate, kad egzamino rezultatas butu atsitiktiniai, iveskite -1" << endl;
        cout << "Iveskite egzamino invertinima: ";
        cin >> temp;
        if(temp == -1)
        {
            grupe[n].egz = rand() % 10 + 1;
            cout << "Sugeneruotas pazymys: " << grupe[n].egz << endl;
        }
        else
            grupe[n].egz = temp;
        int length = i;
        sort(grupe[n].C, grupe[n].C + length);
        if (length == 0)
        {
            grupe[n].med = grupe[n].egz * 0.6;
            grupe[n].vid = grupe[n].med;
        }
        else if (length % 2 == 0)
        {
            grupe[n].med = (grupe[n].C[length / 2 - 1] + grupe[n].C[length / 2]) / 2.0 * 0.4 + grupe[n].egz * 0.6;
            grupe[n].vid = sum * 1.0 / (length * 1.0) * 0.4 + grupe[n].egz * 0.6;
        }
        else
        {
            grupe[n].med = grupe[n].C[length / 2] * 0.4 + grupe[n].egz * 0.6;
            grupe[n].vid = sum * 1.0 / (length * 1.0) * 0.4 + grupe[n].egz * 0.6;
        }
        n++;
    }
}