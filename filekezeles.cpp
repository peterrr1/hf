#include "filekezeles.h"
#include <sstream>

void File::fileBeolvas(Lista& lista) {
	std::fstream file;

	file.open("telefonkonyv.txt", std::ios::in);
	if (!file) {
		throw std::runtime_error("\nHiba a fajl megnyitasa kozben!\n");
	}
	else {
		std::string sor;
		while (std::getline(file, sor)) {

			std::istringstream ss(sor);

			std::string tmpNev, tmpBecNev, tmpCim, tmpEmail, tmpMSzam, tmpPSzam;

			std::getline(ss,tmpNev, ':');
			std::getline(ss, tmpBecNev, ':');
			std::getline(ss, tmpCim, ':');
			std::getline(ss, tmpEmail, ':');
			std::getline(ss, tmpMSzam, ':');
			std::getline(ss, tmpPSzam, ':');

			Adatok ujAdat(tmpNev, tmpBecNev, tmpCim, tmpEmail, tmpMSzam, tmpPSzam);

			lista.hozzaad(ujAdat);
		}
	}
	file.close();
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