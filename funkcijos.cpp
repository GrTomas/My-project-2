#include "studentas.h"
#include "funkcijos.h"

void ivedimas(Studentas& studentas, int a) {
    int ivertinimu_sk;
    string vardas;
    cout << "Iveskite " << a + 1 << " studento  varda: "; cin >> vardas;
    studentas.setVardas(vardas);
    string pavarde;
    cout << "Iveskite " << a + 1 << " studento  pavarde: "; cin >> pavarde;
    studentas.setPavarde(pavarde);
    string dadejimas = " ";
    string ats = " ";

    bool pabaiga = false;
    cout << "Ar norite kad visi ivertinimai butu atsitiktiniai (T, N)? ";
    cin >> ats;
    while (!pabaiga) {
        try {
            if (ats != "t" && ats != "T" && ats != "n" && ats != "N")
                throw - 1;
            pabaiga = true;
        }
        catch (...) {
            cout << "Neteisinga raide" << endl;
            cout << "Ar norite kad visi ivertinimai butu atsitiktiniai (T, N)? ";
            cin >> ats;
        }
    }

    if (ats == "n" || ats == "N") {
        double egz;
        cout << "Iveskite " << a + 1 << " studento  egzamino ivertinima: "; cin >> egz;
        while (cin.fail() || (egz < 1 || egz > 10)) {
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Neteisinga reiksme" << endl;
            cout << "Iveskite " << a + 1 << " studento  egzamino ivertinima: ";
            cin >> egz;
        }
        studentas.setEgz(egz);

        while (dadejimas != "n" && dadejimas != "N") {

            cout << "Ar norite prideti namu darbu ivertinima (T, N)? "; cin >> dadejimas;
            vector <int> nd;
            if (dadejimas == "t" || dadejimas == "T") {
                int ivertinimas = 0;
                while (cin.fail() || ivertinimas < 1 || ivertinimas > 10) {
                    cin.clear();
                    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                    cout << "Iveskite namu darbu ivertinima: ";
                    cin >> ivertinimas;
                    if (cin.fail() || ivertinimas < 1 || ivertinimas > 10) {
                        cout << "Neteisinga reiksme" << endl;
                    }
                    else {
                        nd.push_back(ivertinimas);
                    }
                }

            }
            studentas.setND(nd);
            if (dadejimas != "n" && dadejimas != "t" && dadejimas != "N" && dadejimas != "T") {
                cout << "Neteisingai ivesta raide" << endl;
            }
        }
    }

    if (ats == "t" || ats == "T") {
        vector <int> nd;
        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<int> dist(1, 10);
        studentas.setEgz(dist(mt));
        cout << "Atsitiktinis egzamino ivertinimas yra: " << studentas.egz() << endl;
        while (dadejimas != "n" && dadejimas != "N") {
            cout << "Ar norite prideti namu darbu ivertinima (T, N)? "; cin >> dadejimas;
            if (dadejimas == "t" || dadejimas == "T") {
                int ivertinimas = dist(mt);
                nd.push_back(ivertinimas);
                cout << "Atsitiktinis namu darbu ivertinimas yra: " << ivertinimas << endl;
            }
            if (dadejimas != "n" && dadejimas != "t" && dadejimas != "N" && dadejimas != "T") {
                cout << "Neteisingai ivesta raide" << endl;
            }
        }
        studentas.setND(nd);
    }
    cout << "--------------------------------------------------------------" << endl;

}


void nuskaitymas(Studentas& studentas, string eilute) {
    
    studentas.~Studentas();
    vector<string> v;
    std::stringstream ss(eilute);
    string temp;
    while (ss >> temp) {
        v.push_back(temp);
    }
    studentas.setVardas(v[0]);
    studentas.setPavarde(v[1]);
    vector<int> nd;
    for (int i = 0; i < v.size() - 3; i++) {
        try {
            nd.push_back(stoi(v[i + 2]));
        }


        catch (std::exception& err)
        {
            cout << "Faile rasta neteisingai ivesta namu darbu reiksme, patikslinkite reiksme:   ";
            int sk;
            cin >> sk;
            nd.push_back(sk);
        }

    }
    studentas.setND(nd);
    studentas.setEgz(stoi(v[v.size() - 1]));
    nd.clear();
    nd.shrink_to_fit();
    v.clear();
    v.shrink_to_fit();

    studentas.setGal_vid(galutinis_pagal_vidurki(studentas.paz()) * 0.4 + studentas.egz() * 0.6);
    studentas.setGal_med(galutinis_pagal_mediana(studentas.paz()) * 0.4 + studentas.egz() * 0.6);
}

double galutinis_pagal_vidurki(vector<int> paz) {

    double galutine_suma = std::accumulate(paz.begin(), paz.end(), 0);
    if (paz.size() != 0) {
        return (double)galutine_suma / paz.size();
    }
    else {
        return 0;
    }
}

double galutinis_pagal_mediana(vector<int> paz) {

    std::sort(paz.begin(), paz.end());
    if (paz.size() % 2 == 0 && paz.size() != 0) {
        return (double)(paz[paz.size() / 2] + paz[(paz.size() - 1) / 2]) / 2.0;
    }
    if (paz.size() <= 0) {
        return 0;
    }
    else {
        if (paz.size() == 1) {
            return (double)paz[0];
        }
        else {
            return (double)paz[paz.size() / 2];
        }
    }
}


void isvedimas(vector <Studentas> stud, string pasirinkimas) {

    cout << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
    cout << std::right << std::setw(5) << "Galutinis (";
    if (pasirinkimas == "v" || pasirinkimas == "V") {
        cout << "vid.)" << endl;
    }
    else {
        cout << "med.)" << endl;
    }
    cout << "--------------------------------------------------------------" << endl;
    for (int z = 0; z < stud.size(); z++) {
        cout << std::left << std::setw(20) << stud[z].vardas() << std::left << std::setw(20) << stud[z].pavarde();
        cout << std::right << std::fixed << std::setprecision(2) << std::setw(5) << stud[z].galut_vid() << endl;
    }
}

void isvedimas_is_failo(vector<Studentas> stud) {
    //std::sort(stud.begin(), stud.end(), compare);
    //TODO: patikrinti ar compare tikrai veikia

    std::ofstream rezultatai;
    rezultatai.open("rezultatai.txt", std::ios::out);
    if (rezultatai.fail()) {
        cout << "Failas nebuvo sukurtas";
    }
    else {
        rezultatai << std::left << std::setw(20) << "Vardas" << std::left << std::setw(20) << "Pavarde";
        rezultatai << std::left << std::setw(20) << "Galutinis (vid.)" << std::left << std::setw(20) << "Galutinis (med.)" << endl;
        rezultatai << "----------------------------------------------------------------------------------" << endl;
        for (int i = 0; i < stud.size(); i++) {
            rezultatai << std::left << std::setw(20) << stud[i].vardas();
            rezultatai << std::left << std::setw(20) << stud[i].pavarde();
            rezultatai << std::left << std::fixed << std::setprecision(2) << std::setw(20) << stud[i].galut_vid();
            rezultatai << std::left << std::fixed << std::setprecision(2) << std::setw(20) << stud[i].galut_med() << endl;
        }
        rezultatai.close();
    }

}





