#pragma once
#include "include.h"
#include <chrono>
#include <locale.h>



using namespace std;


int main()
{ 
	setlocale(LC_ALL, "polish");
	vector<osoba>baza;
	pobierz_dane(baza);
	cityStats(baza);
	countByGender(baza);

	
	/*
	wstep();
	ranga();
	auto start = std::chrono::system_clock::now();

	
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
	usun_osobe(baza, znajdz_poj_osobe(baza, "Błażewicz"));
	archiwizuj(baza, "archiwum", true);
	_getch();
	*/
	return 0;
}