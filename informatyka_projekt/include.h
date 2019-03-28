#pragma once
#include <iostream>
#include <conio.h>
#include <ctime>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <fstream>
#include <string>
#include<iterator>

void wstep();
void ranga();
bool zaloguj_jako_wielki_brat();
void pokaz_menu();


tm get_current_time();
bool check_pesel(std::string pesel);
struct osoba
{
	std::string PESEL;
	std::string imie;
	std::string nazwisko;
	std::string miasto;
	int wiek; 
	tm data_urodzenia;
	bool operator== (osoba os){
		return (this->PESEL == os.PESEL);
	
	}
	int wylicz_wiek(){
		return get_current_time().tm_year+1900 - (this->data_urodzenia.tm_year);
	
	}
	tm wyluskaj_date_urodzenia(std::string pesel){
		tm data;
		int a = std::stoi(pesel.substr(0,2));
			if (std::stoi(pesel.substr(2, 2)) <= 12)
			{
				
				data.tm_year = std::stoi(pesel.substr(0,2))+1900;
				data.tm_mon = std::stoi(pesel.substr(2, 2));
				data.tm_mday = std::stoi(pesel.substr(4, 2));
			}
			else
			{	
				data.tm_year = std::stoi(pesel.substr(0, 2)) + 2000;
				data.tm_mon = std::stoi(pesel.substr(2, 2)) - 21;
				data.tm_mday = std::stoi(pesel.substr(4, 2));
			}
			return data;
		}
	
	
	
};

std::ostream& operator<< (std::ostream& out, osoba p);
osoba znajdz_poj_osobe(std::vector <osoba> &baza, std::string szukana_wartosc);
std::vector<osoba> znajdz_zestaw_osob(std::vector <osoba> &baza, std::string szukana_wartosc);
bool ustaw_pola(std::vector <osoba> &baza);
void dodaj_osobe(std::vector<osoba>& baza);
void archiwizuj(std::vector<osoba> baza, std::string nazwa_pliku, bool kasuj);
void pokaz_baze(std::vector<osoba> baza);
bool pobierz_dane(std::vector <osoba> &baza);
void usun_osobe(std::vector <osoba> &baza, osoba os);

std::vector<osoba> kopia_bazy(std::vector<osoba> baza);
void output(const std::vector<osoba>&dat);
bool nameAtoZSortCondition(osoba &s1, osoba &s2);
void sortByNameAtoZ(std::vector<osoba>&baza);
bool nameZtoASortCondition(osoba &s1, osoba &s2);
void sortByNameZtoA(std::vector<osoba>&baza);
bool surnnameAtoZSortCondition(osoba &s1, osoba &s2);
void sortBySurnameAtoZ(std::vector<osoba>&baza);
bool surnnameZtoASortCondition(osoba &s1, osoba &s2);
void sortBySurnameZtoA(std::vector<osoba>&baza);
bool cityAtoZSortCondition(osoba &s1, osoba &s2);
void sortByCityAtoZ(std::vector<osoba>&baza);
bool cityZtoASortCondition(osoba &s1, osoba &s2);
void sortByCityZtoA(std::vector<osoba>&baza);
void sort_menu(std::vector<osoba>&baza);


 