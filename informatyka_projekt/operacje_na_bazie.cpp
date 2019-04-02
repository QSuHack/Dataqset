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
	if(zestaw.size==0 ){
		throw ExBrakOsoby();
	}
	return zestaw;
}


void pokaz_baze(vector<osoba> baza){
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


bool pobierz_dane(vector <osoba> &baza)
{
	bool flaga = false;
	ifstream plik("dane.txt");
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
	return flaga;
}


bool ustaw_pola(vector <osoba> &baza){
	for (auto x : baza){
		x.data_urodzenia = x.wyluskaj_date_urodzenia(x.PESEL);
		x.wiek = x.wylicz_wiek();
	}
	return true;
}


void dodaj_osobe(vector <osoba> &baza)
{
	osoba os;
	string os_tmp;
	bool flag = false;
/*	#undef max
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	_getch();*/
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


void archiwizuj(vector<osoba> baza,string nazwa_pliku="archiwum",bool kasuj=false){
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
}

vector <osoba> wyswietl_osoby_w_wieku(int mode, vector<osoba> baza, int wiek){
	//DO POPRAWIENIA 
	auto it = baza.begin();
	vector <osoba> wynik;
	switch (mode)
	{

		for (it; it < baza.end(); it++)
		{
	case 0:
		if (it->wiek < wiek)
		{
			wynik.push_back(*it);
			break;
		}
	case 1:
		if (it->wiek == wiek)
		{
			wynik.push_back(*it);
			break;
		}
	case 2:
		if (it->wiek > wiek)
		{
			wynik.push_back(*it);
			break;
		}
		}
	}
		return wynik;

}

//vector <osoba> szyfruj_baze(vector<osoba> baza, string haslo){
	

//}