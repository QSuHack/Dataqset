

#include "include.h"
#include <chrono>
#include <locale.h>

using namespace std;

using namespace std;


int main()
{

	//archiwizuj("dane.txt", "wyj.txt");
	setlocale(LC_ALL, "polish");
	pobierz_dane(baza);	
	menu_statystyki();
	wstep();
	ranga();
	
	auto start = std::chrono::system_clock::now();

	
	//pobierz_dane(baza);
	//cityStats(baza);
	
	for (auto x: baza)
	{

		cout << x.zwroc_wiek() << "\n"; //cout << check_pesel(x.PESEL) << " ";
	}

	
	system("pause");
	/*
 v	auto end = std::chrono::system_clock::now();
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
	zapisz(baza, "archiwum", true);
	_getch();*/
	return 0;
}


