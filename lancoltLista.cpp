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
				if (elso = tmp) {
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
				std::cout << "\nHibas formatum.\n" << std::endl;
				break;
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




Lista::~Lista() {
	Elem *current = elso;
	while (current){
		Elem *next = current->kov;
		delete current;
		current = next;
	}
}