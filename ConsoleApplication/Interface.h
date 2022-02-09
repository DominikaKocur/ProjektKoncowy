#pragma once
#include <iostream>
#include "Firma.h"

using namespace std;

class Interface
{
public:
	Interface() : f(Firma()), stan(true) {}
	bool get_stan() { return stan; }
	void polecenie()
	{
		string p;
		cin >> p;
		if (p == "drukuj")
		{
			f.drukuj();
		}
		else if (p == "dodaj")
		{
			dodaj_pojazd();
		}
		else if (p == "usun")
		{
			usun_pojazd();
		}
		else if (p == "wyczysc")
		{
			wyczysc();
		}
		else if (p == "zapisz")
		{
			zapisz();
		}
		else if (p == "wczytaj")
		{
			odczytaj();
		}
		else if (p == "zamknij")
		{
			stan = false;
		}
		else
			cout << "Nieznana komenda" << '\n';
	}

	void dodaj_pojazd()
	{
		string t1;
		string ma1, mo1;
		int r1;
		cout << "Jaki pojazd dodac do bazy:" << '\n' << "Osobowy, Ciezarowy, Motocykl ?" << '\n';
		cin >> t1;
		cout << "Podaj marke pojazdu:" << '\n';
		cin >> ma1;
		cout << "Podaj model pojazdu:" << '\n';
		cin >> mo1;
		cout << "Podaj rok pojazdu:" << '\n';
		cin >> r1;
		f.dodaj(t1, ma1, mo1, r1);
	}


	void usun_pojazd()
	{
		string pd;
		cout << "Jaki pojazdu usunac z bazy:" << '\n' << "Osobowy, Ciezarowy, Motocykl ?" << '\n';
		cin >> pd;
		string c;
		cout << "Podaj marke, model i rok pojazdu ktory chcesz usunac:" << '\n';
		cin >> c;
		f.usun(c, pd);
	}
	void zapisz() {
		string nazwa;
		cout << "Podaj nazwe pliku binarnego do ktorego chcesz zapisac baze :" << '\n';
		cin >> nazwa;
		f.zapis(nazwa);
	}
	void odczytaj() {
		string nazwa;
		cout << "Podaj nazwe pliku binarnego z ktorego chcesz odczytaæ baze :" << '\n';
		cin >> nazwa;
		f.odczyt(nazwa);
	}
	void wyczysc() {
		char d;
		cout << "Czy na pewno chcesz usunac baze? t/n" << '\n';
		cin >> d;
		if (d == 't') {
			f.czysc();
		}
	}
private:
	Firma  f;
	bool stan;



};