#include "studentas.h"
#include "failai_vector.h"
#include "funkcijos.h"

void failo_kurimas(string pav, int kiekis, int nd_sk) {

    std::ofstream failas;
    failas.open(pav, std::ios::out);

    if (failas.fail()) {
        cout << "Failas nebuvo sukurtas";
    }
    else {
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, 10);

        failas << left << setw(20) << "Vardas" << left << setw(20) << "Pavarde";
        for (int i = 1; i <= nd_sk; i++) {
            std::stringstream pavadinimai;
            pavadinimai << "ND" << i;
            failas << left << '\t' << pavadinimai.str();
        }
        failas << left << '\t' << "EGZ" << endl;

        for (int i = 0; i < kiekis; i++) {
            string str_vard = "Vardas";
            str_vard += std::to_string(i + 1);
            string str_pav = "Pavarde";
            str_pav += std::to_string(i + 1);
            if (i == kiekis - 1) {
                std::stringstream eilute;
                eilute << left << setw(20) << str_vard << left << setw(20) << str_pav;
                for (int i = 0; i < nd_sk; i++) {
                    eilute << left << '\t' << dist(mt);
                }
                eilute << left << '\t' << dist(mt);
                failas << eilute.str();
            }
            else {
                std::stringstream eilute;

                eilute << left << setw(20) << str_vard << left << setw(20) << str_pav;
                for (int i = 0; i < nd_sk; i++) {
                    eilute << left << '\t' << dist(mt);
                }
                eilute << left << '\t' << dist(mt) << endl;
                failas << eilute.str();
            }
        }
    }
    failas.close();
}





void isvedimai_auto_failams(vector<Studentas> failai, string pavadinimas) {
    std::ofstream rezultatai;
    rezultatai.open(pavadinimas, std::ios::out);
    if (rezultatai.fail()) {
        cout << "Failas nebuvo sukurtas";
    }
    else {
        rezultatai << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
        rezultatai << std::left << std::setw(20) << "Galutinis (vid.)" << std::left << std::setw(20) << "Galutinis (med.)" << endl;
        rezultatai << "----------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < failai.size(); i++) {
            rezultatai << std::left << std::setw(20) << failai[i].vardas();
            rezultatai << std::left << std::setw(20) << failai[i].pavarde();
            rezultatai << std::left << std::fixed << std::setprecision(2) << std::setw(20) << failai[i].galut_vid();
            rezultatai << std::left << std::fixed << std::setprecision(2) << std::setw(20) << failai[i].galut_med() << endl;
        }
        rezultatai.close();
    }

}

bool ArDaugiau(Studentas& a) { return a.galut_vid() < 5.0; }

void trecios_strategijos_dalijimas(vector <Studentas>& stud, vector <Studentas>& antrieji) {

    std::copy_if(stud.begin(), stud.end(), std::back_inserter(antrieji), ArDaugiau);
    stud.erase(std::remove_if(stud.begin(), stud.end(), ArDaugiau), stud.end());

}

void darbas_su_auto_failu(string pav, int kiek) {

    vector <Studentas> stud;
    stud.reserve(kiek + 1);
    Studentas studentas;
    ifstream failas;
    failas.open(pav);

    cout << "Failo is " << kiek << " irasu suskirstymo ir rusiavimo laikas su vector: ";

    if (failas.is_open()) {
        string eilute;
        std::getline(failas, eilute);
        while (failas) {
            std::getline(failas, eilute);
            nuskaitymas(studentas, eilute);
            stud.push_back(studentas);
        }
    }

    auto start2 = std::chrono::high_resolution_clock::now(); auto st2 = start2;
    vector<Studentas> pirmieji;
    vector<Studentas> antrieji;
    std::sort(stud.begin(), stud.end(), comparePagalVidurki);
    trecios_strategijos_dalijimas(stud, antrieji);

    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff2 = end2 - start2;
    cout << diff2.count() << endl;


    failas.close();

    std::stringstream pavad;
    pavad << "galvociai" << kiek << "vector.txt";
    isvedimai_auto_failams(stud, pavad.str());
    stud.clear();
    stud.shrink_to_fit();
    std::stringstream pavadin;
    pavadin << "nuskriaustukai" << kiek << "vector.txt";
    isvedimai_auto_failams(antrieji, pavadin.str());
    antrieji.clear();
    antrieji.shrink_to_fit();
}