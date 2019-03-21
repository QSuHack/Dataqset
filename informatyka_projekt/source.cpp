#pragma once
#include "include.h"

bool check_pesel(std::string pesel){
if ((1* (int)pesel[0] + 3* (int)pesel[1] + 7* (int)pesel[2] + 9* (int)pesel[3]
	+ 1* (int)pesel[4] + 3* (int)pesel[5]+ 7 * (int)pesel[6] + 9 * (int)pesel[7]
	+ 1 * (int)pesel[8] + 3 * (int)pesel[9] + 1 * (int)pesel[10]) %10 == 0)
{
	return true;
}
else{
	return false;
}
}
std::ostream& operator<< (std::ostream& out, osoba p) // TU MO¯NA POPRAWIÆ WYŒWIETLANIE OSOBY
{
	out << p.imie << " " << p.nazwisko<<" " << p.PESEL<<" "<< p.miasto;
	return out;
}
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

tm get_current_time()
{
	time_t     now = time(0);
	struct tm  tstruct;
	localtime_s(&tstruct, &now);
	return tstruct;
}
