#pragma once
#include "include.h"
#include <Windows.h>
#include <limits>
using namespace std;

osoba znajdz_poj_osobe(std::vector<osoba>& baza, std::string szukana_wartosc)
{
	for (auto x : baza){
	if (x.PESEL==szukana_wartosc || x.imie == szukana_wartosc || x.nazwisko== szukana_wartosc || x.miasto == szukana_wartosc)
	{
		return x;
	}
	}
	throw ExBrakOsoby();
}

std::vector<osoba> znajdz_zestaw_osob(std::vector<osoba>& baza, std::string szukana_wartosc)
{
	std::vector<osoba> zestaw;
	osoba a;
	for (auto x : baza)
	{
		if (x.PESEL == szukana_wartosc || x.imie == szukana_wartosc || x.nazwisko == szukana_wartosc || x.miasto == szukana_wartosc)
		{
			a = x;
			zestaw.push_back(a);
		}
	}
	if(zestaw.size()==0 ){
		throw ExBrakOsoby();
	}
	return zestaw;
}


void pokaz_baze(vector<osoba> baza){
	if (baza.size() == 0) {
		cout << "Baza jest pusta.";
		return;
	}
	for (auto it = baza.begin(); it < baza.end(); it++)
	{
		cout << *it << "\n";
	}
}


void usun_osobe(vector <osoba> &baza, osoba os){
	for (auto it=baza.begin();it<baza.end();it++)
	{
		if (*it == os){
			baza.erase(it);
			return;
		}
	}
	throw ExBrakOsoby();
}


vector <osoba> kopia_bazy(vector<osoba>baza){
	vector<osoba>new_baza(baza);
	return new_baza;
}


bool pobierz_dane(vector <osoba> &baza, string nazwa_pliku)
{
	bool flaga = false;
	ifstream plik(nazwa_pliku);
	osoba c;
	while (!plik.eof())
	{
		plik >> c.imie >> c.nazwisko >> c.PESEL;
		getline(plik, c.miasto);
		if (c.PESEL.length() ==11 )
		{
			baza.push_back(c);
		}
	}
	flaga = ustaw_pola(baza);
	plik.close();
	return flaga;
}


bool ustaw_pola2(vector <osoba> &baza){
	for (auto x : baza){
		
		x.wyluskaj_date_urodzenia(x.PESEL);x.wylicz_wiek();
		cout << x.zwroc_wiek() << " ";
	}
	return true;
}
bool ustaw_pola(vector <osoba>& baza) {
	for (vector<osoba>::iterator it = baza.begin(); it < baza.end();it++) {

		it->wyluskaj_date_urodzenia(it->PESEL); it->wylicz_wiek();
		
	}
	return true;
}

void dodaj_osobe(vector <osoba> &baza)
{
	osoba os;
	string os_tmp;
	bool flag = false;
	#undef max
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	_getch();
	cout << "\nPodaj imiê: ";
	cin >> os.imie;
	cout << "\nPodaj nazwisko: ";
	cin >> os.nazwisko; // cin wycina bia³e znaki wiêc nie zapisze pustego.
	flag = false;
	while (!flag)
	{
		cout << "\nPodaj PESEL: ";
		cin >> os_tmp;
		flag = check_pesel(os_tmp);
		if (!flag)
		{
			cout << "Niepoprawny format, spróbuj jeszcze raz!";
		}
	}
	cout << "Podaj miasto: ";
	getline(cin, os.miasto);
	baza.push_back(os);
}


void zapisz(vector<osoba> baza,string nazwa_pliku="archiwum",bool kasuj=true){
	fstream plikw;
	if(kasuj){
		plikw.open((nazwa_pliku + ".txt"), fstream::out | fstream::trunc);
	}
	else
	{
		plikw.open((nazwa_pliku + ".txt"), fstream::app | fstream::out);
	}
	for (auto it = baza.begin();it < baza.end(); it++)
	{
		plikw << *it <<"\n";
	}
	plikw.close();
}

vector <osoba> wyswietl_osoby_w_wieku(int mode, vector<osoba> baza, int wiek){
	if (baza.size() == 0){
		// zg³aszanie wyj¹tku by nie odnosiæ siê do pustych wskaŸników(iterator not deferencable) 
		throw ExBrakOsoby();
	}
	auto it = baza.begin();
	vector <osoba> wynik;
	switch (mode)
	{
	case 0:
		for (it; it < baza.end(); it++)
		{
			if (it->zwroc_wiek() < wiek)
			{
				wynik.push_back(*it);
			}
		}
		break;
	case 1:
		for (it; it < baza.end(); it++)
		{
			if (it->zwroc_wiek() == wiek)
			{
				wynik.push_back(*it);
			}
		}
		break;
	case 2:
		for (it; it < baza.end(); it++)
		{
			if (it->zwroc_wiek() > wiek)
			{
				wynik.push_back(*it);
			}
		}
		break;
	}
	if (wynik.size()==0){
		throw ExBrakOsoby();
	}
		return wynik;

}

//TODO vector <osoba> szyfruj_baze(vector<osoba> baza, string haslo){
	

//}

void edytuj_rekord(osoba &os)
{
	cout << "\nObecne imiê: " << os.imie << "\nPodaj nowe imiê: ";
	cin >> os.imie;
	cout << "\nObecne nazwisko: " << os.nazwisko << "\nPodaj nowe nazwisko: ";
	cin >> os.nazwisko;
	cout << "Czy chcesz zachowaæ numer pesel? (T/N)";
	
	if (_getch() == 'N')
	{
		bool flag = false;
		string os_tmp;
		while (!flag)
		{

			cout << "\nPodaj PESEL: ";
			cin >> os_tmp;
			flag = check_pesel(os_tmp);
			if (!flag)
			{
				cout << "\nNiepoprawny format, spróbuj jeszcze raz!";
			}
		}
		os.PESEL = os_tmp;
		cout << "\nPESEL zmieniono.";
	}
	cout << "\nPodaj miasto: ";
	#undef max
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	getline(cin, os.miasto);
	cout << "\nZmienianie rekordu zakoñczono.";

}

void archiwizuj(string nazwa_in, string nazwa_out) {
	ifstream plik_in(nazwa_in);
	ofstream plik_out(nazwa_out);
	plik_out << plik_in.rdbuf();
}