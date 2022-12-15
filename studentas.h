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
	string vardas_;
	string pavarde_;
};



class Studentas : public Zmogus {
private:
	std::vector<int> nd_;
	double egzaminas_;
	double galutinis_vid;
	double galutinis_med;

public:
	Studentas() {
		nd_ = {};
		egzaminas_ = 0;
		galutinis_vid = 0;
		galutinis_med = 0;
	}

	Studentas(string vardas, string pavarde, vector<int> nd, int egzaminas) {
		vardas_ = vardas;
		pavarde_ = pavarde;
		this->nd_ = nd;
		this->egzaminas_ = egzaminas;
	}

	~Studentas() { nd_.clear(); }
	Studentas(const Studentas& stud);
	Studentas& operator=(const Studentas& stud);

	friend ostream& operator<<(ostream& output, const Studentas& stud) {
		output << std::left << std::setw(20) << stud.vardas_;
		output << std::left << std::setw(20) << stud.pavarde_;
		output << std::left << std::fixed << std::setprecision(2) << std::setw(20) << stud.galutinis_vid;
		output << std::left << std::fixed << std::setprecision(2) << std::setw(20) << stud.galutinis_med << endl;
		return output;
	}

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



