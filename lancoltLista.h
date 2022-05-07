#ifndef LANCOLTLISTA_H
#define LANCOLTLISTA_H

#include "adatok.h"


class Lista {
	struct Elem {
		Adatok adat;
		Elem *kov;
		Elem(Adatok& adat) : adat(adat), kov(NULL) {}
	};
	Elem *elso;
public:
	Lista() : elso(NULL) {}

	Lista(const Lista& lista);
	
	void hozzaad(Adatok& ujAdat);

	void kiir() const;

	void torles(std::string torlendoSzam);

	void nevKeres(std::string keresettNev) const;

	void szamKeres(std::string keresettSzam) const;

	void modosit(std::string telefonszam);

	~Lista();

	//azert, hogy a filekezles hozzaferjen a lista elso eleméhez, és be tudja jarni a listat
	friend class File;

};

#endif