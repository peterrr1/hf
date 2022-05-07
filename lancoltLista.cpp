#include "lancoltLista.h"



void Lista::hozzaad(Adatok& ujAdat) {

	Elem *ujElem = new Elem(ujAdat);

	if (elso == NULL){
		elso = ujElem;
	}
	else {
		Elem *tmp = elso;
		while (tmp->kov != NULL){
			tmp = tmp->kov;
		}
		tmp->kov = ujElem;
	}
	std::cout << "\nSikeres adatfelvetel!\n" << std::endl;
}



void Lista::kiir() const {
	for (Elem *it = elso; it != NULL; it = it->kov){
		std::cout << "\nNev: " << it->adat.getNev() << '\n' <<
		"Becenev: " << it->adat.getBecenev() << '\n' <<
		"Lakcim: " << it->adat.getLakcim() << '\n' <<
		"Email: " << it->adat.getEmail() << '\n' <<
		"Munkahelyi telefonszam: " << it->adat.getMunkahelyi() << '\n' <<
		"Privat telefonszam: " << it->adat.getPrivat() << std::endl;
	}
}



void Lista::torles(std::string torlendoSzam) {


	Elem *elozo = NULL;
	bool benne_van = false;
	for (Elem *tmp = elso; tmp != NULL; tmp = tmp->kov) {
		if (tmp->adat.getMunkahelyi() == torlendoSzam || tmp->adat.getPrivat() == torlendoSzam) {
			benne_van = true;
			char megerosites;
			std::cout << "\nNev: " << tmp->adat.getNev() << '\n' <<
			"Becenev: " << tmp->adat.getBecenev() << '\n' <<
			"Lakcim: " << tmp->adat.getLakcim() << '\n' <<
			"Email: " << tmp->adat.getEmail() << '\n' <<
			"Munkahelyi telefonszam: " << tmp->adat.getMunkahelyi() << '\n' <<
			"Privat telefonszam: " << tmp->adat.getPrivat() << std::endl;

			std::cout << "Valoban torolni szeretne a bejegyzest?(i/n)";
	
			std::cin >> megerosites;
			std::cin.ignore();

			if (megerosites == 'i' || megerosites == 'I') {
				if (elso == tmp) {
					elso = tmp->kov;
					delete tmp;
				}
				else {
					elozo->kov = tmp->kov;
					delete tmp;
					tmp = elozo->kov;
				}
				std::cout << "\nSikeres torles!\n" << std::endl;
				break;
			}
			else if (megerosites == 'n' || megerosites == 'N') {
				std::cout << "\nNem tortent torles.\n" << std::endl;
				break;
			}
			else {
				throw std::runtime_error("\nHibas formatum.\n");
 			}
		}
		elozo = tmp;
	}
	if (!benne_van)
		std::cout << "\nNem talalhato szemely a megadott telefonszammal.\n" << std::endl;

}



void Lista::nevKeres(std::string keresettNev) const {


	bool benne_van = false;

	for (Elem* tmp = elso; tmp != NULL; tmp = tmp->kov) {
		if (keresettNev == tmp->adat.getNev()) {
			benne_van = true;
			std::cout << "\nNev: " << tmp->adat.getNev() << '\n' <<
			"Becenev: " << tmp->adat.getBecenev() << '\n' <<
			"Lakcim: " << tmp->adat.getLakcim() << '\n' <<
			"Email: " << tmp->adat.getEmail() << '\n' <<
			"Munkahelyi telefonszam: " << tmp->adat.getMunkahelyi() << '\n' <<
			"Privat telefonszam: " << tmp->adat.getPrivat() << std::endl;
		}
	}

	if (!benne_van) {
		std::cout << "\nNem talalhato szemely a megadott nevvel.\n" << std::endl;
	}
}



void Lista::szamKeres(std::string keresettSzam) const {

	bool benne_van = false;

	for (Elem* tmp = elso; tmp != NULL; tmp = tmp->kov) {
		if (keresettSzam == tmp->adat.getPrivat() || keresettSzam == tmp->adat.getMunkahelyi()) {
			benne_van = true;
			std::cout << "\nNev: " << tmp->adat.getNev() << '\n' <<
			"Becenev: " << tmp->adat.getBecenev() << '\n' <<
			"Lakcim: " << tmp->adat.getLakcim() << '\n' <<
			"Email: " << tmp->adat.getEmail() << '\n' <<
			"Munkahelyi telefonszam: " << tmp->adat.getMunkahelyi() << '\n' <<
			"Privat telefonszam: " << tmp->adat.getPrivat() << std::endl;
		}
	}

	if (!benne_van){
		std::cout << "\nNem talalhato szemely a megadott telefonszammal.\n" << std::endl;
	}
}

void Lista::modosit(std::string telefonszam) {

	bool benne_van = false;
	Elem *elozo = NULL;
	Elem* tmp = elso;
	while (tmp != NULL) {
		if (telefonszam == tmp->adat.getMunkahelyi() || telefonszam == tmp->adat.getPrivat()){
			benne_van = true;
			std::cout << "Modositando bejegyzes: " << std::endl;
			std::cout << "\nNev: " << tmp->adat.getNev() << '\n' <<
			"Becenev: " << tmp->adat.getBecenev() << '\n' <<
			"Lakcim: " << tmp->adat.getLakcim() << '\n' <<
			"Email: " << tmp->adat.getEmail() << '\n' <<
			"Munkahelyi telefonszam: " << tmp->adat.getMunkahelyi() << '\n' <<
			"Privat telefonszam: " << tmp->adat.getPrivat() << std::endl;

			std::cout << "Adja meg az uj adatokat: ";
			std::string UjNev, UjBecenev, UjLakcim, UjEmail, UjMunkahelyi, UjPrivat;

			std::cout << "Nev: ";
			std::getline(std::cin, UjNev);

			std::cout << "Becenev: ";
			std::getline(std::cin, UjBecenev);

			std::cout << "Lakcim: ";
			std::getline(std::cin, UjLakcim);

			std::cout << "Email: ";
			std::getline(std::cin, UjEmail);

			std::cout << "Munkahelyi szam: ";
			std::getline(std::cin, UjMunkahelyi);

			std::cout << "Privat szam: ";
			std::getline(std::cin, UjPrivat);

			Adatok ujAdat(UjNev, UjBecenev, UjLakcim, UjEmail, UjMunkahelyi, UjPrivat);

			Elem *ujElem = new Elem(ujAdat);

			if (elso == tmp){
				ujElem->kov = tmp->kov;
				elso = ujElem;
				delete tmp;
			}
			else {
				ujElem->kov = tmp->kov;
				elozo->kov = ujElem;
				delete tmp;
			}

			break;
		}
		elozo = tmp;
		tmp = tmp->kov;
	}
}




Lista::~Lista() {
	Elem *current = elso;
	while (current){
		Elem *next = current->kov;
		delete current;
		current = next;
	}
}