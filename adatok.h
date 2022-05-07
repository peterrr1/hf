#ifndef ADATOK_H
#define ADATOK_H

#include <iostream>


class Adatok {
	std::string Nev;
	std::string Becenev;
	std::string Lakcim;
	std::string Email;
	std::string MunkahelyiSzam;
	std::string PrivatSzam;
public:
	Adatok(std::string aNev = "", std::string aBecenev = "", std::string aLakcim = "", std::string aEmail = "", std::string aMunkahelyiSzam = "", std::string aPrivatSzam = "") :
	Nev(aNev), Becenev(aBecenev), Lakcim(aLakcim), Email(aEmail), MunkahelyiSzam(aMunkahelyiSzam), PrivatSzam(aPrivatSzam) {}

	
	
	std::string getNev() const {
		return Nev;
	} 

	std::string getBecenev() const {
		return Becenev;
	}

	std::string getLakcim() const {
		return Lakcim;
	}

	std::string getEmail() const {
		return Email;
	}

	std::string getMunkahelyi() const {
		return MunkahelyiSzam;
	}

	std::string getPrivat() const {
		return PrivatSzam;
	}

	~Adatok(){}
};

#endif