#pragma once
#include"include.h"
#include<iostream>
#include<iterator>

using namespace std;

void output(const vector<osoba>& dat)
{
	for (vector<osoba>::const_iterator iter = dat.begin(); iter != dat.end(); iter++)
		cout << (*iter).imie << "\t\t" << (*iter).nazwisko << "\t" << (*iter).miasto << (*iter).PESEL << "\t" << endl;
	cout << endl;
}

bool nameAtoZSortCondition(osoba &s1, osoba &s2)
{
	if (s1.imie != s2.imie)
		return s1.imie < s2.imie;
	else
		return s1.nazwisko < s2.nazwisko;
}

void sortByNameAtoZ(vector<osoba>&baza)
{
	sort(baza.begin(), baza.end(), nameAtoZSortCondition);
	output(baza);
}

bool nameZtoASortCondition(osoba &s1, osoba &s2)
{
	if (s1.imie != s2.imie)
		return s1.imie > s2.imie;
	else
		return s1.nazwisko > s2.nazwisko;
}

void sortByNameZtoA(vector<osoba>&baza)
{
	sort(baza.begin(), baza.end(), nameZtoASortCondition);
	output(baza);
}

bool surnameAtoZSortCondition(osoba &s1, osoba &s2)
{
	if (s1.nazwisko != s2.nazwisko)
		return s1.nazwisko < s2.nazwisko;
	else
		return s1.imie < s2.imie;
}

void sortBySurnameAtoZ(vector<osoba>&baza)
{
	sort(baza.begin(), baza.end(), surnameAtoZSortCondition);
	output(baza);
}

bool surnameZtoASortCondition(osoba &s1, osoba &s2)
{
	if (s1.nazwisko != s2.nazwisko)
		return s1.nazwisko > s2.nazwisko;
	else
		return s1.imie > s2.imie;
}

void sortBySurnameZtoA(vector<osoba>&baza)
{
	sort(baza.begin(), baza.end(), surnameZtoASortCondition);
	output(baza);
}

bool cityAtoZSortCondition(osoba &s1, osoba &s2)
{
	return s1.miasto > s2.miasto;
}

void sortByCityAtoZ(vector<osoba>&baza)
{
	sort(baza.begin(), baza.end(), cityAtoZSortCondition);
	output(baza);
}

bool cityZtoASortCondition(osoba &s1, osoba &s2)
{
	return s1.miasto > s2.miasto;
}

void sortByCityZtoA(vector<osoba>&baza)
{
	sort(baza.begin(), baza.end(), cityZtoASortCondition);
	output(baza);
}



void sort_menu(vector<osoba>&baza)
{
	cout << "1. Sortowanie po imieniu od A do Z\n2.Sortowanie po imieniu od Z do A\n3. Sortowanie po nazwisku od A do Z\n4.Sortowanie po nazwisku od Z do A\n5. Sortowanie po mieœcie od A do Z\n6.Sortowanie po mieœcie od Z do A\n";
	switch (_getch())
	{
	case 49:sortByNameAtoZ(baza);
		break;
	case 50:sortByNameZtoA(baza);
		break;
	case 51:sortBySurnameAtoZ(baza);
		break;
	case 52:sortBySurnameZtoA(baza);
		break;
	case 53:sortByCityAtoZ(baza);
		break;
	case 54:sortByCityZtoA(baza);
		break;
	}
}