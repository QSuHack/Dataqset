#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <string>

tm get_current_time();
bool check_pesel(std::string pesel);
struct osoba
{
	std::string PESEL;
	std::string imie;
	std::string nazwisko;
	std::string miasto;
	int wiek = wylicz_wiek();
	tm data_urodzenia = wyluskaj_date_urodzenia(this->PESEL);
	int wylicz_wiek(){
		return get_current_time().tm_year - (this->data_urodzenia.tm_year);
	
	}
	tm wyluskaj_date_urodzenia(std::string pesel){
		tm data;
		//if (pesel.length() == 11){
			if ((int)(pesel[2] + pesel[3]) <= 12)
			{
				data.tm_year = (int)("19" + pesel[0] + pesel[1]);
				data.tm_mon = ((int)(pesel[2] + pesel[3])) - 1;
				data.tm_mday = (int)(pesel[4] + pesel[5]);
			}
			else
			{
				data.tm_year = (int)("20" + pesel[0] + pesel[1]);
				data.tm_mon = ((int)(pesel[2] + pesel[3])) - 21;
				data.tm_mday = (int)(pesel[4] + pesel[5]);
			}
			return data;
	//	}
	
	}
	
};
std::ostream& operator<< (std::ostream& out, osoba p);
osoba znajdz_poj_osobe(std::vector <osoba> &baza, std::string szukana_wartosc);
std::vector<osoba> znajdz_zestaw_osob(std::vector <osoba> &baza, std::string szukana_wartosc);
