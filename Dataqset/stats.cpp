#pragma once
#include "include.h"


using namespace std;

void countUnderage(vector<osoba>& baza) // Powinno dzia³aæ dla poprawionego wylicz_wiek(), obecnie liczy wszystkich, bo wiek to l. ujemna 
{
	int c = 0;
	for (auto p : baza)
		if (p.zwroc_wiek() < 18)
			c++;
	cout << "Liczba niepe³nolietnich: " << c << "\n";
}

void cityStats(vector<osoba> & baza)
{
	sortByCityAtoZ(baza);
	int c = 1;
	for (auto& p : baza) //(auto x = baza.begin(); x != baza.end() - 1; ++x)
	{
		if ((*(&p + 1)).miasto == p.miasto)
			c++;
		else
		{
			cout << p.miasto << " -  liczba mieszkañców to: " << c << endl;
			c = 1;
		}
	}
}
void countByGender(vector<osoba> & baza)
{
	int m = 0, w = 0;
	for (auto p : baza)
	{
		if (p.PESEL[10] % 2 == 0)
			w++;
		else
			m++;
	}
	cout << "Liczba mê¿czyzn: " << m << endl << "Liczba kobiet: " << w << endl;
}

void oldestAndYoungest(vector<osoba> & baza)
{
	int minim = 999, maxim = 0;
	osoba oldest, youngest;
	for (auto p : baza)
	{
		if (p.zwroc_wiek() < minim) {
			minim = p.zwroc_wiek();
			youngest = p;
		}
	}
	for (auto p : baza)
	{
		if (p.zwroc_wiek() > maxim) {
			maxim = p.zwroc_wiek();
			oldest = p;
		}
	}
	cout << "Najstarsza osoba (" << oldest.zwroc_wiek() << " lat) to " << oldest.imie << " " << oldest.nazwisko << endl;
	cout << "Najm³odsza osoba (" << youngest.zwroc_wiek() << " lat) to " << youngest.imie << " " << youngest.nazwisko << endl;
}

void averageAge(vector<osoba> & baza)
{
	int c = 0;
	long long total = 0;
	for (auto p : baza)
	{
		total += p.zwroc_wiek();
		c++;
	}
	cout <<"Œrednia wieku to: "<< total / c << endl;
}
