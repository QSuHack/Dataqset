#pragma once
#include "include.h"


using namespace std;

void countUnderage(vector<osoba>&baza) // Powinno działać dla poprawionego wylicz_wiek(), obecnie liczy wszystkich, bo wiek to l. ujemna 
{
	int c = 0;
	for (auto p : baza)
		if (p.wiek < 18)
			c++;
	cout << c;
}

void cityStats(vector<osoba>&baza)
{
	sortByCityZtoA(baza);
	int c = 1;
	for(auto p:baza) //(auto x = baza.begin(); x != baza.end() - 1; ++x)
	{
		if ((*(&p+1)).miasto == p.miasto)
			c++;
		else
		{
			cout << p.miasto << " - liczba mieszkańców to: " << c << endl;
			c = 1;
		}
	}
}
void countByGender(vector<osoba>&baza)
{
	int m = 0, w = 0;
	for (auto p : baza) 
	{
		if (p.PESEL[10] % 2 == 0)
			w++;
		else
			m++;
	}
	cout << "Liczba mężczyzn: " << m << endl << "Liczba kobiet: " << w << endl;
}

void oldestAndYoungest(vector<osoba>&baza)
{
	int minim = 999, maxim = 0;
	osoba oldest, youngest;
	for (auto p : baza)
	{
		if (p.wiek < minim)
			minim = p.wiek;
		    youngest = p;
		    
	}
	for (auto p : baza)
	{
		if (p.wiek > maxim)
			maxim = p.wiek;
		    oldest = p;
	}
	cout << "Najstarsza osoba (" << oldest.wiek << " lat) to " << oldest.imie << " " << oldest.nazwisko << endl;
	cout << "Najmłodsza osoba (" << youngest.wiek << " lat) to " << youngest.imie << " " << youngest.nazwisko << endl;
}

void averageAge(vector<osoba>&baza)
{
	int c = 0;
	long long total=0;
	for (auto p : baza)
	{
		total += p.wiek;
		c++;
	}
	cout << total / c<<endl;
}

/*
int cityStats(vector<osoba>&baza)
{
 sortByCityAtoZ(baza);
 vector<string>unique;
 vector<pair<string, int>>counter;
 unique_copy(baza.begin(), baza.end(), back_inserter(unique));
 for (string i:unique)
	 counter.push_back(i,count(baza.begin(), baza.end(), i));
}
*/
/*
std::map<int, int> frequency;
for (int i : baza)
++frequency[i];
for (const auto& e : frequency)
std::cout << "Element " << e.first << " encountered " << e.second << " times\n";
*/