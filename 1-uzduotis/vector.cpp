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
using std::srand;
using std::sort;
using std::string;
using std::vector;


struct Studentas
{
    string vardas = "A", pavarde = "BB";
    vector<int> paz;
    int egz;
    double vid, med;
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
    cout << left << setw(10) << "Vardas" << left << setw(20) << "Pavarde" << right << setw(20) << "Galutinis (Vid.)" << right << setw(20) << "Galutinis (Med.)"<< endl;
    cout << left << setw(10) << "----------------------------------------------------------------------" << endl;
    for (auto A : grupe)
        cout << left << setw(10) << A.vardas << left << setw(20) << A.pavarde << right << setw(20) << fixed << setprecision(2) << A.vid << right << setw(20) << A.med << endl;

}


void inputas(vector<Studentas>& grupe)
{
    srand(time(NULL));
    Studentas A;
    while(true)
    {
        cout << "Iveskite 0, kad baigti ivedinet duomenis" << endl;
        cout << "Iveskite varda ir pavarde: ";
        cin >> A.vardas;
        if(A.vardas == "0")
            break;
        cin >> A.pavarde;
        cout << "Iveskite semestro ivercius. Kai baigsite iveskite 0" << endl;
        cout << "Jeigu pageidaujate, kad pazymiai butu atsitiktiniai, iveskite -1" << endl;
        int sum = 0;
        int temp = -2;
        int i = 1;
        while(true)
        {
            cout << "Iveskite " << i << " pazymi: ";
            cin >> temp;
            if(temp == -1)
            {
                temp = rand() % 10 + 1;
                cout << "Sugeneruotas pazymys: " << temp << endl;
            }
            if(temp == 0)
                break;
            A.paz.push_back(temp);
            sum += temp;
            i++;
        }
        cout << "Jeigu pageidaujate, kad egzamino rezultatas butu atsitiktiniai, iveskite -1" << endl;
        cout << "Iveskite egzamino invertinima: ";
        cin >> temp;
        if(temp == -1)
        {
            A.egz = rand() % 10 + 1;
            cout << "Sugeneruotas pazymys: " << A.egz << endl;
        }
        else
            A.egz = temp;
        int length = A.paz.size();
        sort(A.paz.begin(), A.paz.end());
        if(length == 0)
        {
            A.med = A.egz * 0.6;
            A.vid = A.med;
        }
        else if (length % 2 == 0)
        {
            A.med = (A.paz[length / 2 - 1] + A.paz[length / 2]) / 2.0 * 0.4 + A.egz * 0.6;
            A.vid = sum * 1.0 / (length * 1.0) * 0.4 + A.egz * 0.6;
        }
        else
        {
            A.med = A.paz[length / 2] * 0.4 + A.egz * 0.6;
            A.vid = sum * 1.0 / (length * 1.0) * 0.4 + A.egz * 0.6;
        }

        grupe.push_back(A);
        A.paz.clear();
    }
}