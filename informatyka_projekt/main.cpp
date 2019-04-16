

#include "include.h"
#include <chrono>
#include <locale.h>

using namespace std;
void output(const vector<osoba>& dat)
{
	for (vector<osoba>::const_iterator iter = dat.begin(); iter != dat.end(); iter++)
		cout << (*iter).imie << "\t\t" << (*iter).nazwisko << "\t" << (*iter).miasto << (*iter).PESEL << "\t" << endl;
	cout << endl;
}
bool cityZtoASortCondition(osoba& s1, osoba& s2)
{
	return s1.miasto > s2.miasto;
}
void sortByCityZtoA(vector<osoba>& baza)
{
	sort(baza.begin(), baza.end(), cityZtoASortCondition);
	output(baza);
}

void cityStats(vector<osoba>& baza)
{
	sortByCityZtoA(baza);
	int c = 1;
	for (auto &p : baza) //(auto x = baza.begin(); x != baza.end() - 1; ++x)
	{
		if ((*(&p + 1)).miasto == p.miasto)
			c++;
		else
		{
			cout << p.miasto << " - liczba mieszkañców to: " << c << endl;
			c = 1;
		}
	}
}

using namespace std;


int main()
{

	archiwizuj("dane.txt", "wyj.txt");
	setlocale(LC_ALL, "polish");
	//pobierz_dane(baza);	
	//wstep();
	//ranga();

	auto start = std::chrono::system_clock::now();

	
	pobierz_dane(baza);
	cityStats(baza);
	
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


