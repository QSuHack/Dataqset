#pragma once
#include <Windows.h>
#include <iomanip>
#include "include.h"
using namespace std;
std::vector<osoba> baza;
bool administrator;

void wstep(){
	cout << "Witaj w programie kontroli populacji.\nInformacje dostarcza Minsterstwo Prawdy.\n";
	//TODO ci�g dalszy fabu�y
}
void ranga(){
	administrator = false;
	cout << "Zaloguj si�: \n" << "Wybierz rang�: \n1.W I E L K I  B R A T\n2.Winston\n3.Prol\n";
	_getch();
		if (GetKeyState(0x31) < 0 || GetKeyState(VK_NUMPAD1) < 0)
		{
			if (zaloguj_jako_wielki_brat())
			{
				administrator = true;
				system("cls");
				pokaz_menu();
				
			}
			else
			{
				cout << "Pr�bowa�e� podszy� si� pod Wielkiego Brata, lepiej sam si� zg�o� do Ministerstwa Mi�o�ci!\n";
			}
		}
		if (GetKeyState(0x32) < 0 || GetKeyState(VK_NUMPAD2) < 0){
			system("cls");
			pokaz_menu();
		}

		if (GetKeyState(0x33) < 0 || GetKeyState(VK_NUMPAD3) < 0){
			cout << "Brak dost�pu. We�, id� si� zajmij czym� innym, ok? \n";
		}
		else{
			cout << "b��d";
			
			ranga();
		}
		if (GetKeyState(VK_ESCAPE)<0){
			cout << "\nKoniec programu\n";
		}
}
bool zaloguj_jako_wielki_brat(){
	system("cls");
	string haslo;
	string poprawne = "BB";
	cout << "Podaj has�o dost�pu: ";
	cin >> haslo;
	if (haslo==poprawne){
	//TODO tu da� komunikat powitalny i ascii oko saurona or other else
		return true;
	}
	return false;
}
void pokaz_menu() {
	cout << "\nDost�pne opcje: \n1.Wczytaj dane z pliku.\n2.Poka� baz� danych.\n3.Edytuj baz� danych"
		<< "\n4.Archiwizuj baz� danych.\n5.Posortuj baz�\n6.Statystyki\n7.Ostateczne rozwi�zanie problemu ludzko�ci(usu� baz� danych)\n8.Zapisz zmiany.\n9.Zaawansowane \nESC Wyj�cie.\n";
	int position = 0;
	while (true) {
		Sleep(200);  // blokowanie multi-wywo�a� funkcji przy jednym wci�ni�ciu klawisza
		if (GetKeyState(VK_UP) < 0)
		{
			cout << "E";

		}
		if (GetKeyState(VK_ESCAPE) < 0)
		{
			cout << "�egnaj!";
			break;
		}
		if (GetKeyState(0x31) < 0 || GetKeyState(VK_NUMPAD1) < 0) {
			string tmp;
			cout << "Podaj nazw� pliku, kt�ry chcesz otworzy� (bez rozszerzenia): ";
			cin >> tmp;
			tmp += ".txt";
			if (pobierz_dane(baza, tmp)) {
				cout << "\nWczytano baz�.\n";
			}
			system("pause");
			system("cls");
			pokaz_menu();
		}
		if (GetKeyState(0x32) < 0 || GetKeyState(VK_NUMPAD2) < 0) {
			pokaz_baze(baza);
			system("pause");
			system("cls");
			pokaz_menu();
		}
		if (GetKeyState(0x33) < 0 || GetKeyState(VK_NUMPAD3) < 0) {
			Sleep(200);
			edytuj_baze(baza);
			system("pause");
			system("cls");
			pokaz_menu();
		}
		if (GetKeyState(0x34) < 0 || GetKeyState(VK_NUMPAD4) < 0) {
			string nazwa_do_archiwizacji, nazwa_docelowa;
			bool kasowanie; string tmp;
			cout << "Podaj nazw� pliku, kt�ry chcesz z archwizowa�: \n";
			cin >> nazwa_do_archiwizacji;
			cout << "Podaj nazw� pliku, do kt�rego chcesz z archwizowa�: \n";
			cin >> nazwa_docelowa;
			cout << "Czy chcesz skasowa� " << nazwa_do_archiwizacji << "?(T/N)";
			cin >> tmp;
			if (tmp.c_str() == "T") {
				kasowanie = true;
			}
			else {
				kasowanie = false;
			}
			archiwizuj(nazwa_do_archiwizacji,nazwa_docelowa,kasowanie);
			system("cls");
			pokaz_menu();

		}
		if (GetKeyState(0x35) < 0 || GetKeyState(VK_NUMPAD5) < 0) {
			sort_menu(baza);
			system("pause");
			system("cls");
			pokaz_menu();
		}
		if (GetKeyState(0x36) < 0 || GetKeyState(VK_NUMPAD6) < 0) {
			menu_statystyki();
			system("pause");
			system("cls");
			pokaz_menu();
			
		}
		if (GetKeyState(0x37) < 0 || GetKeyState(VK_NUMPAD7) < 0) {
			if (administrator == true) {
				string nazwa_do_skasowania;
				cout << "Podaj nazwe pliku: ";
				cin >> nazwa_do_skasowania;
				nazwa_do_skasowania += ".txt";
				if (!remove(nazwa_do_skasowania.c_str()))
				{
					cout << "Powiod�o si�.";
				}
				else {
					cout << "\nZ �alem zawiadamiamy, �e polecenia nie uda�o si� wykona� :(\n";
				}
			}
			else {
				cout << "\nBrak uprawnie�. Zaloguj si� jako WIELKI BRAT. \n";
				}
			system("pause");
			system("cls");
			pokaz_menu();
		}
		if (GetKeyState(0x38) < 0 || GetKeyState(VK_NUMPAD8) < 0) {
			string nazwa_pliku;
			cout << "\nPodaj nazw� pliku, do kt�rego chcesz zapisa�: ";
			cin >> nazwa_pliku;
			zapisz(baza, nazwa_pliku, true);
			system("pause");
			system("cls");
			pokaz_menu();
		}
		if (GetKeyState(0x39) < 0 || GetKeyState(VK_NUMPAD9) < 0) {
			//TODO tu wywo�am Pythona chyba, �e stwierdz� za du�o b�ed�w
			cout << "Dost�pne opcje: \n1. Wygeneruj now� baz� danych. \n2.Zaszyfruj lub deszyfruj szyfrem AES baz� danych\n";
			while (true) {
				Sleep(300);
				if (GetKeyState(0x31) < 0 || GetKeyState(VK_NUMPAD1) < 0) {
					wygeneruj_baze_przez_Python();
					break;
				}
				if (GetKeyState(0x32) < 0 || GetKeyState(VK_NUMPAD9) < 0) {
					menu_szyfrowanie();
					break;
				}
			}
			system("pause");
			system("cls");
			pokaz_menu();
		}
		

	}
}

void edytuj_baze(vector <osoba> &baza){
	cout << "Wybierz co chcesz zedytowa�: \n1.Dodaj osob�.\n2.Usu� osob�\n3.Edytuj rekord\n";
	while(true){
		if (GetKeyState(0x31) < 0 || GetKeyState(VK_NUMPAD1) < 0)
		{
			Sleep(200);
			std::fflush(stdin);
			dodaj_osobe(baza);
			break;
		}
		if (GetKeyState(0x32) < 0 || GetKeyState(VK_NUMPAD2) < 0)
		{
			cout << "========EWAPORACJA========\n";
			cout << "Znajd� osob� do usuni�cia.\nPodaj imi� LUB nazwisko LUB PESEL:";
			string osoba_do_usuniecia;
			getline(cin, osoba_do_usuniecia);
			try
			{
			vector <osoba> zestaw = znajdz_zestaw_osob(baza, osoba_do_usuniecia);
			pokaz_vector(zestaw);
			cout << "Podaj numer osoby: ";
			usun_osobe(baza,(zestaw.at((_getch() -  (long long) 49))));
			}
			catch (out_of_range){
				cout << " Nie powiod�o si�. Z�y zakres. \n";
			}
			catch (ExBrakOsoby& e){
				cout << e.what();
			}
			break;
		}
		if (GetKeyState(0x33)<0 || GetKeyState(VK_NUMPAD3)<0){


			cout << "Znajd� osob� do zmiany.\nPodaj imi� LUB nazwisko LUB PESEL:";
			string osoba_do_usuniecia;
			getline(cin, osoba_do_usuniecia);
			try
			{
				vector <osoba> zestaw = znajdz_zestaw_osob(baza, osoba_do_usuniecia);
				pokaz_vector(zestaw);
				cout << "Podaj numer osoby: ";
				osoba tmp = zestaw.at((_getch() - (long long)49));
				auto it = baza.begin();
				for (it ; it < baza.end(); it++) {
					if (tmp == *it) {
						break;
					}
				}
				edytuj_rekord(*it); //TODO tu zmienia zestaw a nie baze DO Zmiany 
				//Dobra chyba ju� dzia�a
				
			}
			catch (out_of_range)
			{
				cout << " Nie powiod�o si�. Z�y zakres. \n";
			}
			catch (ExBrakOsoby& e)
			{
				cout << e.what();
			}
			break;
		}
		if (GetKeyState(VK_ESCAPE)<0){
			Sleep(100);
			break;

		}
	}
	pokaz_menu();


}

void menu_wyswietl_osoby_w_wieku(){
	int wiek_;
	cout << "Tu mo�esz wy�wietli� osoby m�odsze/starsze lub dok�adnie w tym wybranym przez ciebie wieku\n";
	cin >> wiek_;
	cout << "0.M�odsze\n1.Dok�adnie w tym wieku\n2.Starsze";
	while (true)
	{
		if (GetKeyState(0x30)<0 || GetKeyState(VK_NUMPAD0)<0){
		pokaz_vector(wyswietl_osoby_w_wieku(0, baza, wiek_));
		}
		if (GetKeyState(0x31)<0||GetKeyState(VK_NUMPAD1)<0){
		pokaz_vector(wyswietl_osoby_w_wieku(1, baza, wiek_));
			break;
		}
		if (GetKeyState(0x32)<0 || GetKeyState(VK_NUMPAD2)<0){
		pokaz_vector(wyswietl_osoby_w_wieku(2, baza, wiek_));
			break;
		}
	}

}


void menu_statystyki() {
	if (baza.size() == 0) {
		cout << "Baza jest pusta";
	}
	else {
		countUnderage(baza);
		cityStats(baza);
		countByGender(baza);
		oldestAndYoungest(baza);
		averageAge(baza);
		menu_wyswietl_osoby_w_wieku();
	}
}