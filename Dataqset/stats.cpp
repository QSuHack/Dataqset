#pragma once
#include "include.h"


using namespace std;

void countUnderage(vector<osoba>& baza) // Powinno dzia�a� dla poprawionego wylicz_wiek(), obecnie liczy wszystkich, bo wiek to l. ujemna 
{
	int c = 0;
	for (auto p : baza)
		if (p.zwroc_wiek() < 18)
			c++;
	cout << "Liczba niepe�nolietnich: " << c << "\n";
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
			cout << p.miasto << " -  liczba mieszka�c�w to: " << c << endl;
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
	cout << "Liczba m�czyzn: " << m << endl << "Liczba kobiet: " << w << endl;
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
	cout << "Najm�odsza osoba (" << youngest.zwroc_wiek() << " lat) to " << youngest.imie << " " << youngest.nazwisko << endl;
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
	cout <<"�rednia wieku to: "<< total / c << endl;
}

void name_length(vector <osoba> baza) {
	int i = 0, n = 0, m = 0;
	for (auto t : baza)
	{
		if (t.imie.length() > i)
			i = t.imie.length();
		if (t.imie.length() > n)
			n = t.nazwisko.length();
		if (t.imie.length() > m)
			m = t.miasto.length();
	}
	cout << "Najd�u�sze nazwisko ma d�ugo�� : " << n << endl;
	cout << "Najd�u�sze imi� ma d�ugo��: " << i << endl;
	cout << "Najd�u�sza nazwa miasta ma d�ugo��: " << m << endl;
}