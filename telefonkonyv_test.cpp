#include <iostream>
#include "lancoltLista.h"
#include "filekezeles.h"
#include "adatok.h"

int main() {

	//lista példányosítása
	Lista ll;

	//file osztály példányosítása
	File f;

	//adatok beolvasása a láncolt listaba (ha vannak adatok a .txt fájlban)
	f.fileBeolvas(ll);

	//egy uj adat osztály példány
	Adatok kontakt_1("Peter", "Peti", "Budapest", "peti@gmail.com", "06304445544", "06303334333");

	//új lista bejegyzés, Adatok típusu referenciaként veszi át a paramétert
	ll.hozzaad(kontakt_1);

	//kiírósik a láncolt listában található összes bejegyzés
	//jelenleg a kontakt_1 adatai íródnak ki
	ll.kiir();


	//egy újabb Adatok pédányosítás
	Adatok kontakt_2("Vivien", "Vivi", "Budapest", "vivien@gmail.com", "-", "06305798203");

	//újabb elem hozzáadása a láncolt listához
	ll.hozzaad(kontakt_2);

	//kiírja a kontakt_1 és kontakt_2 adatait
	ll.kiir();

	//kitörli a listából az adott telefonszámmal rendelkező személyt, jelen esetben kontakt_1-et
	ll.torles("06303334333");

	//ismét kiíródik a lista minden eleme
	ll.kiir();

	//még egy Adatok példány 
	Adatok kontakt_3("Gabor", "Gabi", "Godollo", "gabi@gmail.com", "06708888888", "06202222222");

	//kontakt_3 hozzáadása a listához
	ll.hozzaad(kontakt_3);

	//megkeresi hogy van-e listában Gabor névvel rendelkező személy, ebben az esetben van, így tehát kiírja az adatait
	ll.nevKeres("Gabor");

	//megkeresi hogy van-e Janos névvel rendelkező személy a listában, ebben az esetben nincsen, kiírja, hogy nem található a megadott személy 
	ll.nevKeres("Janos");

	//megkeresi, hogy van-e a megadott telefonszámmal személy a listában, jelenleg van, kiírja kontakt_2 adatait 
	ll.szamKeres("06305798203");

	//megkeresi hogy van-e a megadott telefonszammal személy a listában, jelenleg nincs, kiírja, hogy nincsen ilyen telefonszámmal rendelkező személy
	ll.szamKeres("06908734332");

	//kiírja a listában szereplő adatokat, jelenleg kontakt_2 és kontakt_3 adatait
	ll.kiir();

	//megkeresi, hogy rendelkezik-e az adott telefonszámmal személy, mivel most rendelkezik ezért bekéri a személy új adatait
	ll.modosit("06708888888");

	//megkeresi, hogy rendelkezik-e az adott telefonszámmal személy, mivelé most nincs ilyen telefonszám a listában kiírja, hogy nincsen ilyen telefonszám a listában
	ll.modosit("06201111111");

	//a listában található adatok egy .txt fájlba íródnak
	f.fileKiir(ll);


	return 0;



}