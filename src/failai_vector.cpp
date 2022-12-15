#include "studentas.h"
#include "failai_vector.h"
#include "funkcijos.h"

/**
 * Si funkcija sukuria faila su studentu informacija ir atsitiktiniais duomenimis.
 *
 * Siai funkcijai pateikiamas string tipo kintamasis pav, kuris nurodo failo pavadinima, int tipo kintamasis kiekis, kuris nurodo kiek studentu bus kuriama ir
 * int tipo kintamasis nd_sk kuris nurodo kiek faile turi buti naumu darbu ivertinimu. Pirmiausiai sioje funkcijoje atidaromas failas, kuris ir bus rasomas.
 * Tada naudojant random_device sukuriamas atsitiktiniu skaiciu generatorius. Tada i faila irasoma pirmoji eilute kuri nurodo kas yra kuriame stulpelyje. Po to yra pradedami
 * rasyti studentu vardai, pavardes pridedant skaiciu pradzioje, kad nesikartotu ir tada ju ivertinimai kurie nustatomi atsitiktinai ir galiausiai atsitiktinis egzamino
 * ivertinimas.
 *
 * @param param1 pav kintamasis nurodantis failo pavadinima
 * @param param2 kiekis kintamasis nurodantis kiek faile bus studentu
 * @param param3 skaicius nurodantis kiek faile bus namu darbu stulpeliu.
 * @return si funkcija negrazina nieko, bet issaugo automatiskai sukurta faila kompiuterio atmintyje.
 */
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

/**
 * Funkcija skirta isvesti rezultatus, kai yra dirbama su vekroriais ir rezultatai isvedami faile.
 *
 * Siai funkcijai yra paduodamas vektorius failai ir failo pavadinimas. Praazdioje atidaromas rezultatu failas, kurio pavadinimui naudoju jau paduota kintamaji.
 * Tada patikrinu ar failas sekmingai atsidarë ir jeigu taip, tada pirmiausiai isvedu stulpeliu pavadinimus i faila, tada eilute bruksneliu, kuri padeda atskirti
 * stulpelius nuo duomenu ir tada einant per visa vektoriu for siklu, kurio ilgi nusistatau imant vektoriaus dydi atspausdinu failo eilutese gautus studento duomenis.
 *
 * @param param1 failai kintamasis kuris pateikia funkcijai vektoriu su studentais. Jame talpinami Studentas klases kintamieji.
 * @param param2 pavadinimas string tipo kintamasis kuris nurodo koks bus isvestu rezultatu failo pavadinimas.
 * @return si funkcija negrazina nieko, o tiesiog kompiuteryje issaugo faila su gautais studentu rezultatais.
 */
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

/**
 * Funkcija kuri paimdama Studentas klases kintamaji patikrina ar jo galutinis rezultatas pagal vidurki yra mazesnis uz 5.
 *
 * @param param1 a Studentas klases kintamasis
 * @return grazina reiksme true, jeigu galutinis_vid mazesnis uz 5 ir false priesingu atveju.
 */
bool ArDaugiau(Studentas& a) { return a.galut_vid() < 5.0; }

/**
 * Funkcija padalijanti studentus i galvocius ir nuskriaustukus.
 *
 * Ğiai funkcijai pateikiami vektoriai su studentu informacija ir tuscias vektorius, kuriame bus saugoma informacija. Pirmiausiai naudojant copy_if() funkcija yra nukopijuojami
 * studentu duomenys kuriu rezultatai galutiniai pagal vidurki mazesni uz 5 i duota tuscia vektoriu. Tada su erase funkcija ir remove_if naikinu duomenys is bendro
 * studentu vektoriaus tu duomenu, kurie buvo nukopijuoti.
 *
 * @param param1 stud vektorius su visu studentu informacija
 * @param param2 antrieji tuscias vektorius, kuriame bus saugoma informacija studentu kuriu galutinis_vid mazesnis uz 5
 * @return si funkcija negrazina jokio kintamojo bet atiduoda du pakeistus vektorius.
 */
void trecios_strategijos_dalijimas(vector <Studentas>& stud, vector <Studentas>& antrieji) {

    std::copy_if(stud.begin(), stud.end(), std::back_inserter(antrieji), ArDaugiau);
    stud.erase(std::remove_if(stud.begin(), stud.end(), ArDaugiau), stud.end());

}

/**
 * Funkcija skirta, kad nuskaityta informacija is failo butu apdorota ir pateikta i du kitus naujus failus.
 *
 * Siai funkcijai yra paduodamas string tipo kintamasis pav, kuris yra failo vardas ir kintamasis kiek, kuris nurodo kiek studentu yra faile. Pirmiausiai yra atidaromas
 * ir nuskaitoma faile esanti informacija, bet pries tai dar rezervuojama vektoriaus vieta. Kai failo duomenys issaugoti, tada pradedamas laiko matavimas ismatuoti
 * kiek laiko atliekami zingsniai po to. Taigi toliau duomenys rusiuojami pagal galutinius rezultatus pagal vidurki ir tada duomenys yra dalinami i galvocius ir
 * nuskriaustukus. Po siu dvieju dalyku laiko matavimas yra sustabdomas ir isvedamas ekrane. Tada failas uzdaromas. Paskui sukuriamas pavadinimas isvesti galvociu failui,
 * kreipiamasi i funkcija isvedimai_auto_failams ir kai funkcija atlikta, duomenys istrinami. Tai daroma dar karta, kadangi pries tai buvo daroma su galvociais ir antrasis
 * kartas yra daromas su nuskriaustukais.
 *
 * @param param1 pav kintamasis nurodantis failo pavadinima.
 * @param param2 kiek kintamasis nurodantis keliu studentu informacija yra gaunama.
 */
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