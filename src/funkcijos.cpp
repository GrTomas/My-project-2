#include "studentas.h"
#include "funkcijos.h"


/**
 * Funkcija i kuria kreipiamasi kai vartotojas nori ivesti studento duomenis.
 *
 * Siai funkcijai pateikiami Studentas klases kintamasis studentas ir int tipo kintamasis a kuris isvedant klausimus nurodys apie kelinta studenta yra kalbama. Pirmiausiai sukuriamas
 * kintamasis vardas. Tada vartotojo prasoma ivesti studento varda. Analogiskai daroma ir su pavarde. Tada sukuriami du string tipo kintamieji dadejimas ir ats kurie bus reikalingi
 * norint suzinoti kokius pasirinkimus vatotojas darys toliau. Taip pat sukuriamas bool tipo kintamasis pabaiga ir prilygamas false. Jis taps true tik tada kai vartotojas
 * baigs vesti duomenis. Tada vartotojas nusprendzia ar nori kad duomeys butu atsitiktiniai. ir while cikle tikrinama ar jis teisingai ivede atsakymo raide ir prasoma vartotojo
 * vesti raide tol, kol ji yra ivedama teisingai.
 *
 * Tada eina if salyga kuri parodo, kad vartotojas nori ne atsitiktiniu duomenu. Pradedama egzamino ivertinimo sukurimu, jo irasimu ir issaugojimu. Tada vartotojo klausiama ar jis
 * nori dadeti namu darbu ir tikrinama ar teisingai iveda atsakymo zodi. Jeigu jis nori prideti ivertinima tada jis turi ivesti ivertinima ir tas ivertinimas saugomas vektoriuje
 * pavadinimu nd. Kai ivertinimu daugiau vartotojas nebenori prideti, tada namu darbai seterio pagalba issaugomi. Jeigu zmogus pasirenka, kad nori automatiskai generuotu duomenu, tada
 * su random_device yra automatiskai generuojamas egzamino ivertinimas ir tada vartoojo klausiama ar jis nori prideti namu darbu ivertinima ir kol jis pasirenka t, tol automatiskai
 * generuojami namu darbu ivertinimai ir saugomi vektoriuje nd. Kai parasome n, tada seterio pagalba duomenys issaugomi.
 *
 * @param studentas Studentas klases kintamasis kuriame saugomi ivedami duomenys.
 * @param a skaicius kuris nurodo kelintas studentas irasomas.
 * @return funkcija nieko negrazina o tiesiog leidzia issaugoti ivedamus duomenis.
 */
void ivedimas(Studentas& studentas, int a) {
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

/**
 * si funkcija nuskaito studento duomenis kai jam yra duota eilute is failo su jo duomenimis.
 *
 * Kreipiantis i sia funkcija yra pateikiama Studentas tipo kintamasis studentas ir string tipo kintamasis eilute. Pirmiausiai panaudojus klases destruktoriu yra panaikinama pries
 * tai buvusio kreipimosi i funkcija namu darba. Tada yra sukuriami nauji kintamieji v, kuris saugos duomenis, ss kuriam paduota visa eilue ir temp, kuris laikinai laikys po viena
 * duomeni. Tada pradedamas while ciklas kurio metu visi eilutes duomenys yra sudedami á vektoriu v. Tada pirmasis ir antrasis vektoriaus nariai yra priskiriami studento vardui ir
 * pavardei naudojant seterius. Po to sukuriamas naujas kintamasis nd, kuris saugos studentu duomenis. Ciklas for sudeda visus eiluteje esancius namu darbus i vektoriu nd ir bandoma patikrinti
 * ar eiluteje nebuvo ivesta neteisingu reiksmiu. Tada studentento namu darbu seteriui paeikiami namu darbai ir jie issaugomi. Tada galiausiai issaugomas egzamino ivertinimas. Paskui
 * yra kreipiamasi i funkcijas kurios issaugo studento galutini ivertinima naudojant vidurki ir tada mediana.
 *
 * @param studentas Studentas klases kintamasis kuris yra skirtas issaugoti nuskaitytus duomenis.
 * @param eilute tai yra nuskaityta duomenu eilute is failo.
 * @return si funkcija yra void todel nieko negrazina.
 */
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

/**
 * Funkcija apskaiciuojanti namu darbu vidurki.
 *
 * Siai funkcijai yra pateikiamas vektorius turintis int tipo kintamuosius pavadinimu paz. Jame yra talpinami studento namu darbai. Pirmiausiai sukuriamas naujas kintamasis pavadinimu
 * galutine_suma ir jis prilyginamas accumulate() funkcijai, kuri grazina visu paz nariu suma. Tada su if salyga patikrinama ar ta suma nera lygi nuliui ir jeigu tai yra tiesa, tada
 * grazinamas double tipo kintamasis kuris gaunamas dalinant galutine suma is paz dydzio, kuris gaunamas naudojant size() funkcija. Jeigu if salyga yra neteisinga, tada else salygoje
 * yra grazinmas nulis.
 *
 * @param paz vektorius turintis int tipo kintamuosius kuriame yra talpinami studento namu darbai.
 * @return si funkcija double tipo kintamaji, kuris nurodo vektoriaus paz esanciu nariu vidurki.
 */
double galutinis_pagal_vidurki(vector<int> paz) {

    double galutine_suma = std::accumulate(paz.begin(), paz.end(), 0);
    if (paz.size() != 0) {
        return (double)galutine_suma / paz.size();
    }
    else {
        return 0;
    }
}

/**
 * Si funkcija suskaiciuoja namu darbu mediana.
 *
 * Siai funkcijai yra paduodamas vektorius su int tipo kintamaisiai pavadinimu paz, kas yra studentu namu darbu ivertinimai. Pirmiausiai sie ivertinimai yra surusuojami naudojant
 * sort() funkcija. Tada pirmasis if tikrina ar paz skaicius yra lyginis ir taip pat ar tai nera tuscias vektorius. Jeigu si salyga teisinga, tada yra grazinamas double tipo kintamasis
 * kuris gaunamas imant du viduriniuosius ivertinimus (nes lyginis namu darbu skaicius) ir juos dalinant is 2 taip gaunant mediana. Jeigu nera tenkinamas pirmasis if, tada tikrinamas
 * sekantis if, kuris patikrina ar ivertinimu skaicius nera didesnis uz 0, nes jeigu tai tiesa, tada grazinamas nulis. Tada dar matoma else salygoje yra if, kuris patikrina ar nera
 * vektoriuje tik vienas namu darbu ivertinimas ir jeigu tai yra tiesa, tada grazina butent ji. Ir galiausiai else salyga grazina vidurinyji namu darbu ivertinima kuris yra double tipo.
 *
 * @param paz vektorius turintis int tipo kintamuosius kuriame yra talpinami studento namu darbai.
 * @return grazinamas double tipo kintamasis kuris parodo kokia yra namu darbu mediana.
 */
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

/**
 * Si funkcija isveda rezultatus i ekrana, kai duomenys yra vedami ranka.
 *
 * Siai funkcijai yra pateikiamas vektorius su studentu duomenimis ir string tipo kintamasis pasirinkimas, kuris nurodo ar vartotojas pasirinko, kad galutinis ivertinimas butu skaiciuojamas
 * pagal vidurki, ar pagal mediana. Pirmaiusiai yra isvedama stulpeliu pavadinimai ir isvedant galutinio rezultato studento pavadinima yra tikrinamas vartotojo pasirinkimas su if salyga
 * ir taip nusprendziama ar prie galutinis parasyti vid. ar med. Tada isvedama linija atskirianti stulpeliu pavadinimus nuo duomenu. Galiausiai yra isvedami ivestu studentu duomenys
 * naudojantis for ciklu.
 *
 * @param stud vektorius kuris talpina visu studentu informaciju.
 * @param pasirinkimas yra vartotojo ivesta v arba m reiksme, kuri funkcijoje padeda nustatyti koki rezultata isvesti prie stulpelio pavadinimu "Galutinis".
 * @return si funkcija yra void tipo, todel nieko negrazina, o tiesiog isveda duomenis i ekrana.
 */
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


/**
 * Si funkcija isveda duomenis is failo.
 *
 * Siai funkcijai yra pateikiamas vektorius, kuriame yra sudeti studentai pavadinimu stud. Pradzioje yra atidaromas rezultatu failas, tada su if salyga patikrinama ar tas failas buvo sukurtas.
 * Jeigu failas buvo sekmingai sukurtas, tada is pradziu i faila ivedame stulpeliu pavadinimus ir linija atskiriancia juos nuo gautu duomenu. Tada pradedamas for ciklas
 * kuris eina per visus studentus nuo pirmojo isvesdamas rezultatus naudodamas isvedimo operatoriu is klases studentas.
 *
 * @param stud vektorius kuris talpina visu studentu informaciju.
 * @return si funkcija nieko negrazina, bet issaugoja nauja faila su naujais duomenimis.
 */
void isvedimas_is_failo(vector<Studentas> stud) {

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
            rezultatai << stud[i];
        }
        rezultatai.close();
    }

}
