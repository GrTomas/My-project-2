#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <ostream>

using std::string;
using std::vector;
using std::endl;
using std::ostream;
using std::istream;


/**
 * Zmogaus klase yra skirti issaugoti ir pasiimti zmogaus varda ir pavarde. Si klase yra bazine, kas reiskia, kad ji yra pagrindine ir is jos yra isvedamos kitos klases. Zmogaus kintamieji
 * vardas ir pavarde yra apsaugoti, kas reiskia, kad juos gali pasiekti tik kitos klases ir sukurti paprasto zmogaus objekto yra negalima.
 *
 * Sioje klaseje naudojamos funkcijos:
 * vardo ir pavardes seteriai
 * vardo ir pavardes geteriai
 */
class Zmogus {


public:

	void setVardas(string vard);
	void setPavarde(string pav);

	string vardas();
	string pavarde();

	Zmogus() {
		vardas_ = "";
		pavarde_ = "";
	}

protected:
	string vardas_; /**< Apsaugotas vardo kintamasis kuris yra string tipo ir gaunamas tik naudojant klases kurios paveldi */
	string pavarde_; /**< Apsaugotas pavardes kintamasis kuris yra string tipo ir pasiekiamas tik klasems kurios paveldi zmogaus klase*/
};


/**
 * Si klase skirta issaugoti ir naudoti studento informacija. Si klase yra isvestine klase is Zmogus klases ir is ten yra gaunami zmogaus vardas ir pavarde. Sioje klaseje saugomi studento
 * vardas, pavarde, namu darbu ivertinimai, egzamino ivertinimai ir galutiniai rezultatai pagal vidurki ir pagal medaiana.
 *
 * Sioje klaseje naudojamos funkcijos:
 * Konstruktoriai
 * Destruktorius
 * Kopijavimo konstruktorius ir kopijavimo operatorius
 * Ivesties ir isvesties operatoriai
 * namu darbu, egzamino ivertinimo, galutiniu rezultatu seteriai ir geteriai
 * Palyginimo operacijos lyginti studentus pagal ju vardus ir galutinius rezultatus pagal vidurki
 */
class Studentas : public Zmogus {
private:
	std::vector<int> nd_; /**< vector tipo privatusis kintamasis kuris saugoja studento namu darbu ivertinimus */
	double egzaminas_; /**< double tipo privatus kintamasis kuris skirtas saugoti studento egzamino informacija */
	double galutinis_vid; /**< double tipo privatus kintamasis kuris skirtas saugoti studento galutinio ivertinimo skaiciuoto pagal vidurki informacija */
	double galutinis_med; /**< double tipo privatus kintamasis kuris skirtas saugoti studento galutinio ivertinimo skaiciuoto pagal mediana informacija */

public:


	/**
	* Numatytasis konstruktorius sukonstruoje Studentas objekta su tusciomis vardo, pavardes, namu darbu, egzamino ir galutiniais ivertinimais.
	*/
	Studentas() {
		vardas_ = "";
		pavarde_ = "";
		nd_ = {};
		egzaminas_ = 0;
		galutinis_vid = 0;
		galutinis_med = 0;
	}


	/**
	 * Konstruktorius skirtas sukurti objekta pateiktiems duomenims
	 *
	 * Sis konstruktorius sukuria studentas klases kintamaji pagal duotus duomenis
	 *
	 * @param param vardas studento vardas kuri norime sukurti
	 * @param pavarde to studento pavarde
	 * @param nd namu darbu informacija, kurie yra sudeti i vektoriu
	 * @param egzaminas studento informacija su parasytu egzaminu
	 * @return sukuria Studentas klases kintamaiji
	 * @throws ExceptionType Description of the exception that may be thrown by the function.
	 */
	Studentas(string vardas, string pavarde, vector<int> nd, int egzaminas) {
		vardas_ = vardas;
		pavarde_ = pavarde;
		this->nd_ = nd;
		this->egzaminas_ = egzaminas;
	}

	/**
	 * Studentas klaseje esantis destruktorius, kuris panaikina namu darbu informacija
	 *
	 * @return si funkcija tik istrina panaudoto studento namu darbu informacija
	 */
	~Studentas() { nd_.clear(); }
	Studentas(const Studentas& stud);
	Studentas& operator=(const Studentas& stud);

	/**
	 * Isvedimo operacijos funkcijos perdengimas
	 * @param output yra ostream tipo kintamasis kuris grazinamas suvedus studento infocmacija reikiama tvarka
	 * @param stud studento informacija, kuria norima isvesti
	 * @return rezultata koks turi buti isvedamas i ekrana ar faila
	 */
	friend ostream& operator<<(ostream& output, const Studentas& stud) {
		output << std::left << std::setw(20) << stud.vardas_;
		output << std::left << std::setw(20) << stud.pavarde_;
		output << std::left << std::fixed << std::setprecision(2) << std::setw(20) << stud.galutinis_vid;
		output << std::left << std::fixed << std::setprecision(2) << std::setw(20) << stud.galutinis_med << endl;
		return output;
	}

	/**
	 * Ivedimo operacijos funkcijos perdengimas
	 * @param input yra ostream tipo kintamasis kuris grazinamas ivedus studento infocmacija
	 * @param stud studento informacija, kuria norima ivesti
	 * @return rezultata ivesto studento
	 */
	friend istream& operator>>(istream& input, Studentas& stud) {
		int kiek_nd, laikinas;
		input >> stud.vardas_ >> stud.pavarde_ >> kiek_nd;
		for (int i = 0; i < kiek_nd; i++) {
			input >> laikinas;
			stud.nd_.push_back(laikinas);
		}
		input >> stud.egzaminas_;
		return input;
	}

	void setND(vector <int>& nd);
	void setEgz(double egz);
	void setGal_vid(double gal_vid);
	void setGal_med(double gal_med);

	vector<int> paz();
	double egz();
	double galut_vid();
	double galut_med();

};

bool comparePagalVarda(Studentas& x, Studentas& y);
bool comparePagalVidurki(Studentas& x, Studentas& y);
