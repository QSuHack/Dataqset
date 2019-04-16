#pragma once
#include "include.h"
using namespace std;
osoba znajdz_poj_osobe(std::vector<osoba>& baza, std::string szukana_wartosc)
{
	for (auto x : baza){
	if (x.PESEL==szukana_wartosc || x.imie == szukana_wartosc || x.nazwisko== szukana_wartosc || x.miasto == szukana_wartosc)
	{
		return x;
	}
	}
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
			break;
		}
	}
	
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
		plik >> c.imie >> c.nazwisko >> c.PESEL >> c.miasto;
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
	cout << "\nPodaj imię: ";
	cin >> os.imie;
	cout << "\nPodaj nazwisko: ";
	cin >> os.nazwisko; // TODO sprawdzi� czy nie puste etc.
	bool flag = false;
	while (!flag)
	{
		cout << "\nPodaj PESEL: ";
		cin >> os_tmp;
		flag = check_pesel(os_tmp);
		if (!flag)
		{
			cout << "Niepoprawny format, spr�buj jeszcze raz!";
		}
	}
	cout << "Podaj miasto: ";
	cin >> os.miasto;
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








