#pragma once
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;



class Studentas {

private:
	std::string vardas_;
	std::string pavarde_;
	std::vector<int> nd_;
	double egzaminas_;
	double galutinis_vid;
	double galutinis_med;
	char* rodykle;

public:

	Studentas() {
        vardas_ = "";
        pavarde_ = "";
		nd_ = {};
        egzaminas_ = 0;
        galutinis_vid = 0;
        galutinis_med = 0;
    }

    Studentas(string vardas, string pavarde, vector<int> nd, int egzaminas, double vidurki, double mediana) {
        this->vardas_ = vardas;
        this->pavarde_ = pavarde;
		this->nd_ = nd;
		this->egzaminas_ = egzaminas;
		this->galutinis_vid = vidurki;
		this->galutinis_med = mediana;
    }

	~Studentas() { nd_.clear(); }
    Studentas(const Studentas& stud);
    Studentas& operator=(const Studentas& stud);


	void setVardas(string vard);
	void setPavarde(string pav);
	void setND(vector <int>& nd);
	void setEgz(double egz);
	void setGal_vid(double gal_vid);
	void setGal_med(double gal_med);

	string vardas();
	string pavarde();
	vector<int> paz();
	double egz();
	double galut_vid();
	double galut_med();

    

    
	

	
};

bool comparePagalVarda(Studentas& x, Studentas& y);
bool comparePagalVidurki(Studentas& x, Studentas& y);