#pragma once
#include "include.h"
#include <chrono>

using namespace std;

void pobierz_dane(vector <osoba> &baza)
{

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
	ustaw_pola(baza);
}

void ustaw_pola(vector <osoba> &baza){
	for (auto x : baza){
		x.data_urodzenia = x.wyluskaj_date_urodzenia(x.PESEL);
		x.wiek = x.wylicz_wiek();
	}

}

void dodaj_osobe(vector <osoba> &baza){
	osoba os;
	string os_tmp;
	cout << "\nPodaj imiê: ";
	cin >> os.imie;
	cout << "\nPodaj nazwisko: ";
	cin >> os.nazwisko; // TODO sprawdziæ czy nie puste etc.
	bool flag = false;
	while (!flag)
	{
		cout << "\nPodaj PESEL: ";
		cin >> os_tmp;
		flag = check_pesel(os_tmp);
		if (!flag){
			cout << "Niepoprawny format, spróbuj jeszcze raz!";
		}
	}
	cout << "Podaj miasto: ";
	cin >> os.miasto;
	baza.push_back(os);

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
void pokaz_baze(vector<osoba> baza){
	for (auto it = baza.begin(); it < baza.end(); it++)
	{
		cout << *it << "\n";
	}
}
int main()
{
	auto start = std::chrono::system_clock::now();

	vector <osoba> baza;
	pobierz_dane(baza);
	for (auto x : baza)
	{
		cout << x.PESEL << "\n"; cout << check_pesel(x.PESEL) << " ";
	}


	
	auto end = std::chrono::system_clock::now();
	chrono::duration<double> elapsed_seconds = end - start;
	cout << "elapsed time: " << elapsed_seconds.count() << "s\n";
	auto a = znajdz_poj_osobe(baza, "Sobik");
	for (auto x : znajdz_zestaw_osob(baza, "Skierniewice"))
	{
		cout << x<<"\n";
	}
	pokaz_baze(baza);
	cout << "USUWANIE"<<"\n\n\n";
	usun_osobe(baza, znajdz_poj_osobe(baza, "B³a¿ewicz"));
	pokaz_baze(baza);
	_getch();
	return 0;
}