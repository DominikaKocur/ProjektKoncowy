#pragma once
#include "Pojazd.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdexcept>
using namespace std;

class Firma
{
public:
	Firma()
	{
		l_o = 0; l_m = 0; l_c = 0;
	}
	void dodaj(string t, string mar, string mod, int r)
	{
		try
		{
			if (any_of(lista_p.cbegin(), lista_p.cend(), [&](auto& it)
				{return  it->get_model() == mod; }))
			{
				throw "Ten model jest juz w bazie!";
			}

			if (t == "Osobowy")
			{
				unique_ptr< Pojazd > p = make_unique< Osobowy >(mar, mod, r);
				lista_p.emplace_back(move(p));
				l_o++;
			}

			else if (t == "Ciezarowy")
			{
				unique_ptr< Pojazd > p = make_unique< Ciezarowy >(mar, mod, r);
				lista_p.emplace_back(move(p));
				l_c++;
			}

			else if (t == "Motocykl")
			{
				unique_ptr< Pojazd > p = make_unique< Motocykl >(mar, mod, r);
				lista_p.emplace_back(move(p));
				l_m++;
			}
			else {
				cout << "BLAD" << '\n';
			}
		}
		catch (const char* e) {
			cout << e << '\n';
		}

	}
	void usun(string mod, string pd)
	{
		try
		{
			if (all_of(lista_p.cbegin(), lista_p.cend(), [&](auto& it)
				{return  it->get_model() != mod; }))
			{
				throw "Nie ma takiego modelu w bazie!";
			}
			auto u = find_if(lista_p.begin(), lista_p.end(), [&](auto& it)
				{
					return (it->get_model() == mod); });
			if (pd == "Osobowy")
			{
				l_o--;
			}

			else if (pd == "Ciezarowy")
			{
				l_c--;
			}

			else if (pd == "Motocykl")
			{
				l_m--;
			}
			lista_p.erase(u);
			cout << "Pojazd usuniety z bazy" << '\n';
		}
		catch (const char* e) {
			cout << e << '\n';
		}
	}
	const void drukuj() {
		if (l_c == 0 && l_m == 0 && l_o == 0) {
			cout << "Baza pojazdow jest pusta " << '\n';
		}
		else {

			cout << "Baza pojazdow: " << '\n';
			for_each(lista_p.begin(), lista_p.end(), [](auto& it) { it->print(); });
			cout << "W bazie jest:" << '\n';
			cout << l_o << " samochodow osobowych" << '\n';
			cout << l_m << " motocykli" << '\n';
			cout << l_c << " samochodow ciezarowych" << '\n';
		}
	};
	void czysc() {
		lista_p.clear();
		l_o = 0; l_m = 0; l_c = 0;
	}
	void zapis(string nazwa) {
		fstream plik;
		plik.open(nazwa, ios::out | ios::binary);
		if (plik.is_open()) {
			for_each(lista_p.begin(), lista_p.end(), [&](auto& it) {
				string t = it->get_typ(), ma = it->get_marka(), mo = it->get_model();
				int r = it->get_rok();
				plik.write(t.c_str(), t.size() + 1);
				plik.write(ma.c_str(), ma.size() + 1);
				plik.write(mo.c_str(), mo.size() + 1);
				plik.write((const char*)&r, sizeof r);
				});
			plik.close();
		}
		else {
			cout << "Nie uda³o siê otworzyæ pliku" << '\n';
		}
	};
	void odczyt(string nazwa) {
		fstream plik;
		plik.open(nazwa, ios::in | ios::binary);
		if (plik.is_open()) {
			do {
				string t, ma, mo;
				int r = 0;
				getline(plik, t, '\0');
				getline(plik, ma, '\0');
				getline(plik, mo, '\0');
				plik.read((char*)&r, sizeof r);
				if (t == "Osobowy") {
					unique_ptr< Pojazd > p = make_unique< Osobowy >(ma, mo, r);
					lista_p.emplace_back(move(p));
					l_o++;
				}
				else if (t == "Motocykl") {
					unique_ptr< Pojazd > p = make_unique< Motocykl >(ma, mo, r);
					lista_p.emplace_back(move(p));
					l_m++;
				}
				else if (t == "Ciezarowy") {
					unique_ptr< Pojazd > p = make_unique< Ciezarowy >(ma, mo, r);
					lista_p.emplace_back(move(p));
					l_c++;
				}

			} while (!plik.eof());
			plik.close();
			cout << "Wczytano baze pojazdow" << '\n';
			drukuj();
		}
		else {
			cout << "Nie uda³o siê otworzyæ pliku" << '\n';
		}
	};
private:
	vector< unique_ptr<Pojazd>> lista_p;
	int l_o, l_m, l_c;
};