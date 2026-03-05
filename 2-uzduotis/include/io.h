#ifndef IO_H
#define IO_H

#include "student.h"
#include <string>
#include <vector>

using std::vector;
using std::string;

void inputas(vector<Studentas> &grupe);
void outputas(vector<Studentas> grupe);

void fileRead(vector<Studentas> &grupe, string file_name);
void fileTest(vector<Studentas> &grupe, string file_name, int &testKiekis);

void sortByUser(vector<Studentas> &grupe, int temp);

void duomenuIrasymasFaile(vector<Studentas> &grupe, int temp, string fileName);
void duomenuIrasymasKonsole(vector<Studentas> &grupe, int temp);

#endif