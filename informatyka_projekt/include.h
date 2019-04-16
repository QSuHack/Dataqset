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
#include <cstdio>
using namespace std;
void wstep();
void ranga();
bool zaloguj_jako_wielki_brat();
void pokaz_menu();
extern bool administrator;


tm get_current_time();

bool check_pesel(std::string pesel);
struct osoba
{
	std::string PESEL;
	std::string imie;
	std::string nazwisko;
	std::string miasto;
	
	tm data_urodzenia;
	bool operator== (osoba os){
		return (this->PESEL == os.PESEL);
	
	}
	void wylicz_wiek(){
		this->wiek =((get_current_time().tm_year+1900) - (this->data_urodzenia.tm_year));
	
	}
	void wyluskaj_date_urodzenia(std::string pesel){
		tm data;
		int a = std::stoi(pesel.substr(0,2));
			if (std::stoi(pesel.substr(2, 2)) <= 12)
			{
				
				data.tm_year = std::stoi(pesel.substr(0,2))+1900;
				data.tm_mon = std::stoi(pesel.substr(2, 2));
				data.tm_mday = std::stoi(pesel.substr(4, 2));
				data.tm_hour = 0;
				data.tm_min = 0;
				data.tm_sec = 0;

			}
			else
			{	
				data.tm_year = std::stoi(pesel.substr(0, 2)) + 2000;
				data.tm_mon = std::stoi(pesel.substr(2, 2)) - 21;
				data.tm_mday = std::stoi(pesel.substr(4, 2));
				data.tm_hour = 0;
				data.tm_min = 0;
				data.tm_sec = 0;
			}
			this->data_urodzenia = data;
		}
	int zwroc_wiek() {
		return this->wiek;
	}
private:
	int wiek;
};

std::ostream& operator<< (std::ostream& out, osoba p);
osoba znajdz_poj_osobe(std::vector <osoba> &baza, std::string szukana_wartosc);
std::vector<osoba> znajdz_zestaw_osob(std::vector <osoba> &baza, std::string szukana_wartosc);
bool ustaw_pola(std::vector <osoba> &baza);
void dodaj_osobe(std::vector<osoba>& baza);
void zapisz(std::vector<osoba> baza, std::string nazwa_pliku, bool kasuj);
extern vector<osoba> baza;

void pokaz_baze(std::vector<osoba> baza);
bool pobierz_dane(std::vector <osoba> &baza, string nazwa_pliku = "dane.txt");
void usun_osobe(std::vector <osoba> &baza, osoba os);
void edytuj_baze(std::vector<osoba>& baza);
void menu_wyswietl_osoby_w_wieku();
std::vector<osoba> kopia_bazy(std::vector<osoba> baza);
std::vector<osoba> wyswietl_osoby_w_wieku(int mode, std::vector<osoba> baza, int wiek);
void edytuj_rekord(osoba & os);
template <typename T, typename A>
void pokaz_vector(vector <T, A> vector_)
{
	int i = 1;
	for (auto it = vector_.begin(); it < vector_.end(); it++)
	{
		cout << i << "." << *it << "\n";
		i++;

	}
}
struct ExBrakOsoby : public exception{
	const char * what() const throw ()
	{
		return "Nie znaleziono osoby.";
	}
};
void archiwizuj(string nazwa_in, string nazwa_out);