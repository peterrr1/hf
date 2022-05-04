#include "filekezeles.h"

int main(){
	Lista ll;
	File f;

	int select;

	do {
		std::cout << "Hozzaadas 1" << std::endl;
		std::cout << "Torles 2" << std::endl;
		std::cout << "Kereses nev alapjan 3" << std::endl;
		std::cout << "Kereses szam alapjan 4" << std::endl;
		std::cout << "Kiiras 5" << std::endl;
		std::cout << "Kilepes 6" << std::endl;
		std::cin >> select;
		std::cin.ignore();

		switch(select) {
			case 1: {
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

				ll.hozzaad(ujAdat);

				break;
			}
			case 2: {
				std::string torlendoSzam;
				std::cout << "Torlendo szemely munkahelyi/privat telefonszama: ";
				std::getline(std::cin, torlendoSzam);

				ll.torles(torlendoSzam);

				break;
			}
			case 3:{
				std::string keresettNev;
				std::cout << "Keresett szemely neve: ";
				std::getline(std::cin, keresettNev);

				ll.nevKeres(keresettNev);
				break;
			}
			case 4: {
				std::string keresettSzam;
				std::cout << "Keresett szemely munkahelyi/privat telefonszama: ";
				std::getline(std::cin, keresettSzam);

				ll.szamKeres(keresettSzam);

				break;
			}
			case 5:
				ll.kiir();

				break;

			case 6:
				f.fileKiir(ll);
				break;
		}
	}while (select != 6);

	return 0;
}