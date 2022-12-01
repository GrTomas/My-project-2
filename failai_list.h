#pragma once
#include <fstream>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <random>
#include <sstream>
#include <chrono>
#include <cmath>
#include <string>
#include <list>

using std::string;
using std::ifstream;
using std::list;
using std::cout;
using std::endl;
using std::setw;
using std::left;

void duomenu_issaugojimas_list(string eilute, Studentas& studentas);
void isvedimai_auto_failams_list(list<Studentas> failai, string pavadinimas);
void darbas_su_auto_failu_list(string pav, int kiek, int variantas);
void pirmos_strategijos_dalijimas(list <Studentas> stud, list <Studentas>& pirmieji, list <Studentas>& antrieji);
void antros_strategijos_dalijimas(list <Studentas>& stud, list <Studentas>& antrieji);