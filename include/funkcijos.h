#pragma once
#include <iostream>
#include <string>
#include <cstdio>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <fstream>
#include <chrono>
#include <sstream>
#include <random>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;
using std::ifstream;

void ivedimas(Studentas& studentas, int a);
void nuskaitymas(Studentas& studentas, string eilute);
double galutinis_pagal_vidurki(vector<int> paz);
double galutinis_pagal_mediana(vector<int> paz);
void isvedimas(vector <Studentas> stud, string pasirinkimas);
void isvedimas_is_failo(vector<Studentas> stud);