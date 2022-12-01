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
	
	public:
		Studentas() : egzaminas_(0) { }
		Studentas(string eilute);
		void setVardas(string vard);
		void setPavarde(string pav);
		void setND(vector <int>& nd);
		void setEgz(double egz);
		void setGal_vid(double gal_vid);
		void setGal_med(double gal_med);
		void NDClear();

		string vardas();
		string pavarde();
		vector<int> paz();
		double egz();
		double galut_vid();
		double galut_med();
};

bool comparePagalVarda(Studentas& x, Studentas& y);
bool comparePagalVidurki(Studentas& x, Studentas& y);