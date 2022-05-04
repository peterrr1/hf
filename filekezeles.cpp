#include "filekezeles.h"


void File::fileBeolvas(Lista& lista) {
	std::fstream file;

	file.open("telefonkonyv.txt", std::ios::out);
	if (!file){
		throw std::runtime_error("\nHiba a fajl megnyitasa kozben!\n");
	}
	else {
		std::string nev, becenev, lakcim, email, munka, privat;
		char c;
		while (!file.eof()) {
			file >> nev >> c >> becenev >> c >> lakcim >> email >> c >> munka >> c >> privat;
			Adatok ujAdat(nev, becenev, lakcim, email, munka, privat);
			lista.hozzaad(ujAdat);
		}
		file.close();
	}
}


void File::fileKiir(Lista& lista) {
	std::fstream file;

	file.open("telefonkonyv.txt", std::ios::out);
	if (!file){
		throw std::runtime_error("\nHiba a fajl megnyitasa kozben!\n");
	}
	else {
		for (Lista::Elem* tmp = lista.elso; tmp != NULL; tmp = tmp->kov){
			file << tmp->adat.getNev() << ':' << tmp->adat.getBecenev() << ':' <<
			tmp->adat.getLakcim() << ':' << tmp->adat.getEmail() << ':' <<
			tmp->adat.getMunkahelyi() << ':' << tmp->adat.getPrivat() << '\n';
		}
		file.close();
	}
}