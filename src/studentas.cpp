#include "studentas.h"

/**
 * Setteris nustatantis zmogaus varda
 * @param vard kintamasis atitinka zmogaus varda
 */
void Zmogus::setVardas(string vard) {
	vardas_ = vard;
}

/**
 * Setteris nustatantis zmogaus pavarde
 * @param pav kintamasis atitinka zmogaus pavarde
 */
void Zmogus::setPavarde(string pav) {
	pavarde_ = pav;
}

/**
 * Getteris nustatantis zmogaus varda
 * @return vardas_ grazina zmogaus varda
 */
string Zmogus::vardas() {
	return vardas_;
}

/**
 * Getteris nustatantis zmogaus pavarde
 * @return pavarde_ grazina zmogaus pavarde
 */
string Zmogus::pavarde() {
	return pavarde_;
}



/**
 * Setteris nustatantis studento namu darbu ivertinimus
 * @param nd kintamasis kuriame pateikti namu darbu ivertinimai
 */
void Studentas::setND(vector <int>& nd) {

	for (int i = 0; i < nd.size(); i++) {
		nd_.push_back(nd[i]);
	}
}

/**
 * Setteris nustatantis studento egzamino ivertinima
 * @param egz kintamasis kuriame pateiktas egzamino ivertinimas
 */
void Studentas::setEgz(double egz) {
	egzaminas_ = egz;
}

/**
 * Setteris nustatantis studento galutini ivertinima pagal vidurki
 * @param gal_vid kintamasis kuriame pateiktas galutinis ivertinimas pagal vidurki
 */
void Studentas::setGal_vid(double gal_vid) {
	galutinis_vid = gal_vid;
}

/**
 * Setteris nustatantis studento galutini ivertinima pagal mediana
 * @param gal_med kintamasis kuriame pateiktas galutinis ivertinimas pagal mediana
 */
void Studentas::setGal_med(double gal_med) {
	galutinis_med = gal_med;
}

/**
 * Getteris grazinantis studento namu darbu ivertinimus
 * @return nd kintamasis kuriame pateikti namu darbu ivertinimai
 */
vector<int> Studentas::paz() {
	return nd_;
}

/**
 * Getteris atiduodantis studento egzamino ivertinima
 * @return egz grazina studento egzamino ivertinima
 */
double Studentas::egz() {
	return egzaminas_;
}

/**
 * Getteris atiduodantis studento galutini ivertinima kuris skaiciuotas pagal vidurki
 * @return gal_vid grazina studento galutinis ivertinima pagal vidurki
 */
double Studentas::galut_vid() {
	return galutinis_vid;
}

/**
 * Getteris atiduodantis studento galutini ivertinima kuris skaiciuotas pagal mediana
 * @return gal_med grazina studento galutinis ivertinima pagal mediana
 */
double Studentas::galut_med() {
	return galutinis_med;
}


/**
 * Kopijavimo konstruktorius
 *
 * Kopijavimo konstruktorius skirtas nukopijuoti studento informacija is vieno i kita surasius juos tokiu budu a(b), cia nukopijuojami a elementai ir pateikiama informacija a elementui
 *
 * @param param1 studentas informacija studento, kurio duomenis kopijuojame.
 * @return sis konstruktorius sulygina du kintamuosius
 */
Studentas::Studentas(const Studentas& studentas) {
	vardas_ = studentas.vardas_;
	pavarde_ = studentas.pavarde_;
	nd_ = studentas.nd_;
	egzaminas_ = studentas.egzaminas_;
	galutinis_vid = studentas.galutinis_vid;
	galutinis_med = studentas.galutinis_med;
}

/**
* Lygybës operatoriaus perdengimas
* @param studentas informacija studento, kuri norime nukopijuoti
* @return nukopijuota Studentas klases kintamaji ir ji priskiria kitam (juos sulygina)
*/
Studentas& Studentas::operator=(const Studentas& studentas) {
	if (&studentas == this) { return *this; }
	nd_.clear();
	vardas_ = studentas.vardas_;
	pavarde_ = studentas.pavarde_;
	nd_ = studentas.nd_;
	egzaminas_ = studentas.egzaminas_;
	galutinis_vid = studentas.galutinis_vid;
	galutinis_med = studentas.galutinis_med;
	return *this;
}

/**
 * Funkcija palyginanti dvieju studentu vardus ir grazinanti juos didejancia tvarka
 *
 * @param param1 x Studentas klasses kintamasis kuris naudojamas palyginimui
 * @param param2 y antrasis Studentas klasses kintamasis kuris naudojamas palyginimui
 * @return bool reikğmë kuri yra true jei x vardas yra maşiau (abeceleje yra auksciau) negu y vardas ir false prieğingu atveju
 */
bool comparePagalVarda(Studentas& x, Studentas& y) {
	return x.vardas() < y.vardas();
}

/**
 * Funkcija palyginanti dvieju studentu galutinius ivertinimus pagal vidurki ir grazinanti juos didejancia tvarka
 *
 * @param param1 x Studentas klasses kintamasis kuris naudojamas palyginimui
 * @param param2 y antrasis Studentas klasses kintamasis kuris naudojamas palyginimui
 * @return bool reikğmë kuri yra true jei x galutinis ivertinimas pagal vidurki yra mazesnis negu y galutinis ir false prieğingu atveju
 */
bool comparePagalVidurki(Studentas& x, Studentas& y) {
	return x.galut_vid() < y.galut_vid();
}