#pragma once
#include"include.h"



using namespace std;


bool nameAtoZSortCondition(osoba& s1, osoba& s2)
{
	if (s1.imie != s2.imie)
		return s1.imie < s2.imie;
	else
		return s1.nazwisko < s2.nazwisko;
}

void sortByNameAtoZ(vector<osoba> & baza)
{
	sort(baza.begin(), baza.end(), nameAtoZSortCondition);
}

bool nameZtoASortCondition(osoba & s1, osoba & s2)
{
	if (s1.imie != s2.imie)
		return s1.imie > s2.imie;
	else
		return s1.nazwisko > s2.nazwisko;
}

void sortByNameZtoA(vector<osoba> & baza)
{
	sort(baza.begin(), baza.end(), nameZtoASortCondition);
}

bool surnameAtoZSortCondition(osoba & s1, osoba & s2)
{
	if (s1.nazwisko != s2.nazwisko)
		return s1.nazwisko < s2.nazwisko;
	else
		return s1.imie < s2.imie;
}

void sortBySurnameAtoZ(vector<osoba> & baza)
{
	sort(baza.begin(), baza.end(), surnameAtoZSortCondition);
}

bool surnameZtoASortCondition(osoba & s1, osoba & s2)
{
	if (s1.nazwisko != s2.nazwisko)
		return s1.nazwisko > s2.nazwisko;
	else
		return s1.imie > s2.imie;
}

void sortBySurnameZtoA(vector<osoba> & baza)
{
	sort(baza.begin(), baza.end(), surnameZtoASortCondition);
}

bool cityAtoZSortCondition(osoba & s1, osoba & s2)
{
	return s1.miasto < s2.miasto;
}

void sortByCityAtoZ(vector<osoba> & baza)
{
	sort(baza.begin(), baza.end(), cityAtoZSortCondition);
}

bool cityZtoASortCondition(osoba & s1, osoba & s2)
{
	return s1.miasto > s2.miasto;
}

void sortByCityZtoA(vector<osoba> & baza)
{
	sort(baza.begin(), baza.end(), cityZtoASortCondition);
}

bool ageYtoOSortCondition(osoba & s1, osoba & s2)
{
	if (s1.data_urodzenia.tm_year != s2.data_urodzenia.tm_year)
		return s1.data_urodzenia.tm_year > s2.data_urodzenia.tm_year;
	else if (s1.data_urodzenia.tm_mon != s2.data_urodzenia.tm_mon)
		return s1.data_urodzenia.tm_mon > s2.data_urodzenia.tm_mon;
	else if (s1.data_urodzenia.tm_mday != s2.data_urodzenia.tm_mday)
		return s1.data_urodzenia.tm_mday > s2.data_urodzenia.tm_mday;
}

void sortByAgeYtoO(vector<osoba> & baza)
{
	sort(baza.begin(), baza.end(), ageYtoOSortCondition);
}

bool ageOtoYSortCondition(osoba & s1, osoba & s2)
{
	if (s1.data_urodzenia.tm_year != s2.data_urodzenia.tm_year)
		return s1.data_urodzenia.tm_year < s2.data_urodzenia.tm_year;
	else if (s1.data_urodzenia.tm_mon != s2.data_urodzenia.tm_mon)
		return s1.data_urodzenia.tm_mon < s2.data_urodzenia.tm_mon;
	else if (s1.data_urodzenia.tm_mday != s2.data_urodzenia.tm_mday)
		return s1.data_urodzenia.tm_mday < s2.data_urodzenia.tm_mday;
}

void sortByAgeOtoY(vector<osoba> & baza)
{
	sort(baza.begin(), baza.end(), ageOtoYSortCondition);
}




void sort_menu(vector<osoba> & baza)
{
	system("pause");
	system("cls");
	cout << "1. Sortowanie po imieniu od A do Z\n2. Sortowanie po imieniu od Z do A\n3. Sortowanie po nazwisku od A do Z\n4. Sortowanie po nazwisku od Z do A\n5. Sortowanie po mieœcie od A do Z\n6. Sortowanie po mieœcie od Z do A\n7.Sortowanie po wieku, od najm³odzszego do najstarszego\n8.Sortowanie wieku, od najstarszego do najm³odzszego\n";

	switch (_getch())
	{
	case 49:sortByNameAtoZ(baza);
		pokaz_baze(baza);
		break;
	case 50:sortByNameZtoA(baza);
		pokaz_baze(baza);
		break;
	case 51:sortBySurnameAtoZ(baza);
		pokaz_baze(baza);
		break;
	case 52:sortBySurnameZtoA(baza);
		pokaz_baze(baza);
		break;
	case 53:sortByCityAtoZ(baza);
		pokaz_baze(baza);
		break;
	case 54:sortByCityZtoA(baza);
		pokaz_baze(baza);
		break;
	case 55:sortByAgeYtoO(baza);
		pokaz_baze(baza);
		break;
	case 56:sortByAgeOtoY(baza);
		pokaz_baze(baza);
		break;
	}
}
/*
void sort_by_x(vector<osoba>&baza, bool(*x)(osoba, osoba))
{
	sort(baza.begin(), baza.end(), (&x)(&s1, &s2));
	pokaz_baze(baza);
}
*/
