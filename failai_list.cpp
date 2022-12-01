#include "studentas.h"
#include "failai_list.h"
#include "funkcijos.h"

void duomenu_issaugojimas_list(string eilute, Studentas& studentas) {

    list<string> v;
    vector<int> nd;
    std::stringstream ss(eilute);
    string temp;
    while (ss >> temp) {
        v.push_back(temp);
    }
    studentas.setVardas(v.front());
    v.pop_front();
    studentas.setPavarde(v.front());
    v.pop_front();
    studentas.setEgz(stoi(v.back()));
    v.pop_back();
    for (list<string>::iterator it = v.begin(); it != v.end(); ++it) {
        nd.push_back(stoi(*it));
    }
    studentas.setND(nd);
    nd.clear();
    v.clear();
}

void isvedimai_auto_failams_list(list<Studentas> failai, string pavadinimas) {
    std::ofstream rezultatai;
    rezultatai.open(pavadinimas, std::ios::out);
    if (rezultatai.fail()) {
        cout << "Failas nebuvo sukurtas";
    }
    else {
        rezultatai << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
        rezultatai << std::left << std::setw(20) << "Galutinis (vid.)" << std::left << std::setw(20) << "Galutinis (med.)" << endl;
        rezultatai << "----------------------------------------------------------------------------------" << endl;
        for (list<Studentas>::iterator it = failai.begin(); it != failai.end(); ++it) {
            rezultatai << std::left << std::setw(20) << (*it).vardas();
            rezultatai << std::left << std::setw(20) << (*it).pavarde();
            rezultatai << std::left << std::fixed << std::setprecision(2) << std::setw(20) << (*it).galut_vid();
            rezultatai << std::left << std::fixed << std::setprecision(2) << std::setw(20) << (*it).galut_med() << endl;
        }
        rezultatai.close();
    }

}

bool gavoSkolas(Studentas st) {
    if (st.galut_vid() < 5) {
        return true;
    }
    else {
        return false;
    }
}

void pirmos_strategijos_dalijimas(list <Studentas> stud, list <Studentas>& pirmieji, list <Studentas>& antrieji) {


    for (auto a : stud) {
        if (a.galut_vid() >= 5) {
            pirmieji.push_back(a);
        }
        else {
            antrieji.push_back(a);
        }
    }
}

void antros_strategijos_dalijimas(list <Studentas>& stud, list <Studentas>& antrieji) {
    list<Studentas>::iterator it = stud.begin();
    while (it != stud.end()) {
        if (gavoSkolas(*it)) {
            antrieji.push_back(*it);
            it = stud.erase(it);
        }
        else
            ++it;
    }
}



void darbas_su_auto_failu_list(string pav, int kiek, int variantas) {

    list<Studentas> stud;
    Studentas studentas;
    ifstream failas;
    failas.open(pav);
    cout << "Failo is " << kiek << " irasu suskirstymo ir rusiavimo laikas su list naudojant " << variantas << " strategija: ";

    if (failas.is_open()) {
        string eilute;
        std::getline(failas, eilute);
        while (failas) {
            std::getline(failas, eilute);
            duomenu_issaugojimas_list(eilute, studentas);
            studentas.setGal_vid(galutinis_pagal_vidurki(studentas.paz()) * 0.4 + studentas.egz() * 0.6);
            studentas.setGal_med(galutinis_pagal_mediana(studentas.paz()) * 0.4 + studentas.egz() * 0.6);
            stud.push_back(studentas);
        }
    }

    auto start2 = std::chrono::high_resolution_clock::now(); auto st2 = start2;
    list<Studentas> pirmieji;
    list<Studentas> antrieji;
    stud.sort(comparePagalVidurki);

    if (variantas == 1) {
        pirmos_strategijos_dalijimas(stud, pirmieji, antrieji);
        stud.clear();
    }
    else {
        antros_strategijos_dalijimas(stud, antrieji);
    }
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << diff2.count() << endl;

    failas.close();

    if (variantas == 1) {
        std::stringstream pavad;
        pavad << "galvociai" << kiek << "list.txt";
        isvedimai_auto_failams_list(pirmieji, pavad.str());
        pirmieji.clear();
        std::stringstream pavadin;
        pavadin << "nuskriaustukai" << kiek << "list.txt";
        isvedimai_auto_failams_list(antrieji, pavadin.str());
        antrieji.clear();
    }
    else {
        std::stringstream pavad;
        pavad << "galvociai" << kiek << "list.txt";
        isvedimai_auto_failams_list(stud, pavad.str());
        stud.clear();
        std::stringstream pavadin;
        pavadin << "nuskriaustukai" << kiek << "list.txt";
        isvedimai_auto_failams_list(antrieji, pavadin.str());
        antrieji.clear();
    }


}