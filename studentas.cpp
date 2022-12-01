#include "studentas.h"

void Studentas::setVardas(string vard) {
	vardas_ = vard;
}

void Studentas::setPavarde(string pav) {
	pavarde_ = pav;
}

void Studentas::setND(vector <int>& nd) {

	for (int i = 0; i < nd.size(); i++) {
		nd_.push_back(nd[i]);
	}
}

void Studentas::setEgz(double egz) {
	egzaminas_ = egz;
}

void Studentas::setGal_vid(double gal_vid) {

	galutinis_vid = gal_vid;
}

void Studentas::setGal_med(double gal_med) {
	galutinis_med = gal_med;
}

string Studentas::vardas() {
	return vardas_;
}

string Studentas::pavarde() {
	return pavarde_;
}

vector<int> Studentas::paz() {
	return nd_;
}

double Studentas::egz() {
	return egzaminas_;
}

double Studentas::galut_vid() {
	return galutinis_vid;
}

double Studentas::galut_med() {
	return galutinis_med;
}

bool comparePagalVarda(Studentas& x, Studentas& y) {
	return x.vardas() < y.vardas();
}

bool comparePagalVidurki(Studentas& x, Studentas& y) {
	return x.galut_vid() < y.galut_vid();
}


Studentas::Studentas(const Studentas& studentas) {
    vardas_ = studentas.vardas_;
    pavarde_ = studentas.pavarde_;
    nd_ = studentas.nd_;
    egzaminas_ = studentas.egzaminas_;
    galutinis_vid = studentas.galutinis_vid;
    galutinis_med = studentas.galutinis_med;
}

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
