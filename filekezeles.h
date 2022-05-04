#ifndef FILEKEZELES_H
#define FILEKEZELES_H

#include <fstream>
#include "lancoltLista.h"

class File {
public:
	//egy .txt fajlbol beolvassa az adatokat a lancolt listaba
	void fileBeolvas(Lista& lista);

	//kiirja egy .txt fajlba a lancolt listaban tarolt adatokat
	void fileKiir(Lista& lista);
};


#endif