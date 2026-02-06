#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

using std::cin;
using std::cout;
using std::endl;
using std::fixed;
using std::left;
using std::right;
using std::setprecision;
using std::setw;
using std::string;
using std::vector;

struct Studentas
{
    string vardas = "A", pavarde = "BB";
    vector<int> paz;
    int egz;
    double rez;
};

void inputas(vector<Studentas>& grupe);
void outputas(vector<Studentas> grupe);

int main()
{
    vector<Studentas> grupe;
    inputas(grupe);
    outputas(grupe);
    return 0;
}

void outputas(vector<Studentas> grupe)
{
    cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavarde" << right << setw(20) << "Galutinis (Vid.)" << endl;
    cout << left << setw(10) << "----------------------------------------------------" << endl;
    for (auto A : grupe)
        cout << left << setw(10) << A.vardas << left << setw(20) << A.pavarde << right << setw(20) << fixed << setprecision(2) << A.rez << endl;

}


void inputas(vector<Studentas>& grupe)
{
    for (int ii = 0; ii < 2; ii++)
    {
        Studentas A;
        cout << "Iveskite varda ir pavarde: ";
        cin >> A.vardas >> A.pavarde;
        cout << "Iveskite semestro ivercius. Kiek ju bus? ";
        int n, sum;
        cin >> n;
        A.paz.reserve(n);
        for (int i = 0; i < n; i++)
        {
            int temp;
            cout << "Iveskite " << i + 1 << " pazymi: ";
            cin >> temp;
            A.paz.push_back(temp);
            sum += temp;
        }
        cout << "Iveskite egzamino invertinima: ";
        cin >> A.egz;
        A.rez = sum * 1.0 / (n * 1.0) * 0.4 + A.egz * 0.6;
        grupe.push_back(A);
        A.paz.clear();
    }
}