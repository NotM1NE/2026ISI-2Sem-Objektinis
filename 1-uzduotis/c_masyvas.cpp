#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <limits>

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

const string vardai[] = {"Jonas", "Mantas", "Tomas", "Lukas", "Karolis", "Darius", "Paulius", "Mindaugas", "Justas", "Rokas", "Agne", "Ieva", "Egle", "Gabija", "Monika", "Karolina", "Viktorija", "Emilija", "Justina", "Greta"};

const string vyr_pavardes[] = {"Kazlauskas", "Jankauskas", "Petrauskas", "Stankevicius", "Zukauskas", "Butkus", "Pocius", "Urbonas", "Mockus", "Savickas"};

const string mot_pavardes[] = {"Kazlauskiene", "Jankauskiene", "Petrauskiene", "Stankeviciene", "Zukauskiene", "Butkiene", "Pociene", "Urboniene", "Mockiene", "Savickiene"};

struct Studentas
{
    string vardas = "A", pavarde = "BB";
    double *C = nullptr;
    int talpa = 0;
    int kiek = 0;

    int egz;
    double vid, med;
};

void inputas(Studentas *&grupe, int &n, int &talpaS);
void outputas(Studentas *grupe, int n);
void MedVidSkaciavimas(Studentas *grupe, int n, int length, int sum);
void randomVardasPavarde(string &vardas, string &pavarde);

void UztikrintiVietosPazymiams(Studentas &grupe, int reikalinga);
void UztikrintiVietosStudentams(Studentas *&grupe, int &talpaS, int reikalinga);

void intInput(int &temp);

int main()
{
    Studentas *grupe = nullptr;

    int talpaS = 0;
    int n;
    inputas(grupe, n, talpaS);
    outputas(grupe, n);
    // atlaisviname atmintyje uzimta vieta
    for (int i = 0; i < n; i++)
        delete[] grupe[i].C;
    delete[] grupe;

    return 0;
}

void outputas(Studentas *grupe, int n)
{
    int temp;
    cout << "Pasirinkite norima buda isvesti duomenis" << endl;
    cout << "1 - generuoti tik Vidurki\n2 - generuoti tik Mediana\n3 - generuoti ir Vidurki ir Mediana\n";
    intInput(temp);
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
        cout << right << setw(20) << "Galutinis (Vid.)" << right << setw(20) << "Galutinis (Med.)" << endl;
        cout << left << setw(10) << "----------------------------------------------------------------------" << endl;
        for (int i = 0; i < n; i++)
            cout << left << setw(10) << grupe[i].vardas << left << setw(20) << grupe[i].pavarde << right << setw(20) << fixed << setprecision(2) << grupe[i].vid << right << setw(20) << grupe[i].med << endl;
    }
}

void inputas(Studentas *&grupe, int &n, int &talpaS)
{
    srand(time(NULL));
    n = 0;
    while (true)
    {
        int t = 0;
        cout << "Pasirinkite norima buda ivesti duomenis" << endl;
        cout << "1 - ranka\n2 - generuoti tik pazymius\n3 - generuoti studentu vardus, pavardes ir pazymius\n4 - baigti darba\n";
        intInput(t);
        if (t == 1)
        {
            while (true)
            {
                UztikrintiVietosStudentams(grupe, talpaS, n + 1);
                cout << "Iveskite 0, kad baigti ivedinet duomenis" << endl;
                cout << "Iveskite varda ir pavarde: ";
                cin >> grupe[n].vardas;
                if (grupe[n].vardas == "0")
                    break;

                cin >> grupe[n].pavarde;
                cout << "Iveskite semestro ivercius. Kai baigsite iveskite 0" << endl;
                int sum = 0;
                int temp = -2;
                grupe[n].kiek = 0;
                while (true)
                {
                    cout << "Iveskite " << grupe[n].kiek + 1 << " pazymi: ";
                    intInput(temp);
                    if (temp < 0 || temp > 10)
                    {
                        cout << "Pazymys turi buti tarp 1 ir 10. Bandykite dar karta." << endl;
                        continue;
                    }
                    if (temp == 0)
                        break;
                    UztikrintiVietosPazymiams(grupe[n], grupe[n].kiek + 1);
                    grupe[n].C[grupe[n].kiek] = temp;
                    sum += temp;
                    grupe[n].kiek++;
                }
                while(true)
                {
                    cout << "Iveskite egzamino invertinima: ";
                    intInput(temp);
                    if (temp < 0 || temp > 10)
                    {
                        cout << "Pazymys turi buti tarp 1 ir 10. Bandykite dar karta." << endl;
                        continue;
                    }
                    break;
                }
                grupe[n].egz = temp;
                MedVidSkaciavimas(grupe, n, grupe[n].kiek, sum);
                n++;
            }
        }
        if (t == 2)
        {
            while (true)
            {
                UztikrintiVietosStudentams(grupe, talpaS, n + 1);
                cout << "Iveskite 0, kad baigti ivedinet duomenis" << endl;
                cout << "Iveskite varda ir pavarde: ";
                cin >> grupe[n].vardas;
                if (grupe[n].vardas == "0")
                    break;
                cin >> grupe[n].pavarde;
                int sum = 0,
                    rand_paz,
                    length = 10;
                grupe[n].kiek = 0;
                for (int i = 1; i <= length; i++)
                {
                    rand_paz = rand() % 10 + 1;
                    UztikrintiVietosPazymiams(grupe[n], grupe[n].kiek + 1);
                    grupe[n].C[grupe[n].kiek] = rand_paz;
                    cout << "Sugeneruotas " << i << " pazymys: " << grupe[n].C[grupe[n].kiek] << endl;
                    sum += rand_paz;
                    grupe[n].kiek++;
                }
                grupe[n].egz = rand() % 10 + 1;
                cout << "Sugeneruotas egzamino invertinimas: " << grupe[n].egz << endl;
                MedVidSkaciavimas(grupe, n, length, sum);
                n++;
            }
        }
        if (t == 3)
        {
            for (int i = 1; i <= 10; i++)
            {
                UztikrintiVietosStudentams(grupe, talpaS, n + 1);
                randomVardasPavarde(grupe[n].vardas, grupe[n].pavarde);
                cout << "Sugeneruotas " << i << " vardas ir pavarde: " << grupe[n].vardas << " " << grupe[n].pavarde << endl;
                int sum = 0,
                    rand_paz,
                    length = 10;
                grupe[n].kiek = 0;
                for (int ii = 1; ii <= length; ii++)
                {
                    rand_paz = rand() % 10 + 1;
                    UztikrintiVietosPazymiams(grupe[n], grupe[n].kiek + 1);
                    grupe[n].C[grupe[n].kiek] = rand_paz;
                    cout << "test: " << rand_paz << endl;
                    cout << "Sugeneruotas " << ii << " pazymys: " << grupe[n].C[grupe[n].kiek] << endl;
                    grupe[n].kiek++;
                    sum += rand_paz;
                }
                grupe[n].egz = rand() % 10 + 1;
                cout << "Sugeneruotas egzamino invertinimas: " << grupe[n].egz << endl;
                MedVidSkaciavimas(grupe, n, length, sum);
                n++;
            }
        }
        if (t == 4)
            break;
    }
}

void MedVidSkaciavimas(Studentas *grupe, int n, int length, int sum = 0)
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

// kad uztikrinti masyvo pletima, draugas pasiule ideja: pries irasant nauja reiksme patikriname, ar masyvas turi pakankamai vietos.
// Jei vietos neuztenka, sukuriame nauja didesni masyva, perkeliame esamus duomenis, rodykle keiciame i nauja masyva ir sena istriname
void UztikrintiVietosPazymiams(Studentas &grupe, int reikalinga)
{
    if (grupe.talpa >= reikalinga)
        return;

    int newTalpa = grupe.talpa;
    if (newTalpa == 0)
        newTalpa = 4; // didiname 4, kad daryti maziau veiksmu
    while (newTalpa < reikalinga)
        newTalpa = newTalpa * 2; // jeigu neuztenka, didiname dvigubai kad daryti maziau veiksmu

    double *newC = new double[newTalpa];
    for (int i = 0; i < grupe.kiek; i++)
        newC[i] = grupe.C[i]; // perkeliame duomenis

    // istriname sena masyva ir rodykle keiciame i nauja masyva
    delete[] grupe.C;
    grupe.C = newC;
    grupe.talpa = newTalpa;
}

void UztikrintiVietosStudentams(Studentas *&grupe, int &talpaS, int reikalinga)
{
    if (talpaS >= reikalinga)
        return;

    int newTalpa = talpaS;
    if (newTalpa == 0)
        newTalpa = 4; // didiname 4, kad daryti maziau veiksmu
    while (newTalpa < reikalinga)
        newTalpa = newTalpa * 2; // jeigu neuztenka, didiname dvigubai kad daryti maziau veiksmu

    Studentas *newGrupe = new Studentas[newTalpa];
    for (int i = 0; i < reikalinga - 1; i++)
        newGrupe[i] = grupe[i]; // perkeliame duomenis

    delete[] grupe;
    grupe = newGrupe;
    talpaS = newTalpa;
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
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
