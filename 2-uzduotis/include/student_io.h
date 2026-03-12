#ifndef STUDENT_IO_H
#define STUDENT_IO_H

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

bool containsDigit(const string &str);
void GenerateStudentsFile(int n);
void splitStudents(const vector<Studentas> &grupe, vector<Studentas> &failed, vector<Studentas> &passed);
int getSortChoice(int temp);

void benchmarkFile(int n, int testKiekis);

#endif