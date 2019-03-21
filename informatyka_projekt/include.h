#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <string>

bool check_pesel(std::string pesel);
struct osoba
{
	std::string PESEL;
	std::string imie;
	std::string nazwisko;
	std::string miasto;
};
std::ostream& operator<< (std::ostream& out, osoba p);
osoba znajdz_poj_osobe(std::vector <osoba> &baza, std::string szukana_wartosc);
std::vector<osoba> znajdz_zestaw_osob(std::vector <osoba> &baza, std::string szukana_wartosc);