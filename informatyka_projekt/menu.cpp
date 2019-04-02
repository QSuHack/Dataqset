#pragma once
#include "include.h"
#include <Windows.h>

using namespace std;
std::vector<osoba> baza;


void wstep(){
	cout << "Witaj w programie kontroli populacji.\nInformacje dostarcza Minsterstwo Prawdy.\n";
	// ci�g dalszy fabu�y
}
void ranga(){
	cout << "Zaloguj si�: \n" << "Wybierz rang�: \n1.W I E L K I  B R A T\n2.Winston\n3.Prol\n";
	_getch();
		if (GetKeyState(0x31) < 0 || GetKeyState(VK_NUMPAD1) < 0)
		{
			if (zaloguj_jako_wielki_brat())
			{
				pokaz_menu();
				
			}
			else
			{
				cout << "Pr�bowa�e� podszy� si� pod Wielkiego Brata, lepiej sam si� zg�o� do Ministerstwa Mi�o�ci!\n";
			}
		}
		if (GetKeyState(0x32) < 0 || GetKeyState(VK_NUMPAD2) < 0){
			pokaz_menu();
		}

		if (GetKeyState(0x33) < 0 || GetKeyState(VK_NUMPAD3) < 0){
			cout << "Brak dost�pu. We�, id� si� zajmij czym� innym, ok? \n";
		}
		if (GetKeyState(VK_ESCAPE)<0){
			cout << "koniec";
		}
		else{
			cout << "b��d";
			
			ranga();
		}
}
bool zaloguj_jako_wielki_brat(){
	system("cls");
	string haslo;
	string poprawne = "BB";
	cout << "Podaj has�o dost�pu: ";
	cin >> haslo;
	if (haslo==poprawne){
	// tu da� komunikat powitalny i ascii oko saurona or other else
		return true;
	}
	return false;
}
void pokaz_menu(){
	
	cout << " Tu b�dzie menu";
	cout << "\nDost�pne opcje: \n1.Wczytaj dane z pliku.\n2.Poka� baz� danych.\n3.Edytuj baz� danych"
		<< "\n4. \n5.\n6.\n7.\n8.\n9.";
	int position = 0;
	while (true){
	Sleep(100);  // blokowanie multi-wywo�a� funkcji przy jednym wci�ni�ciu klawisza
		if (GetKeyState(VK_UP)<0)
	{
		cout<< "up";

	}
	if (GetKeyState(VK_ESCAPE) < 0)
	{
		cout << "koniec";
		break;
	}
	if (GetKeyState(0x31)<0|| GetKeyState(VK_NUMPAD1)<0){
		cout << "1opcja";
		
		pobierz_dane(baza);
		cout << "Wczytano baz�.\n";

	}
	if (GetKeyState(0x32)<0 || GetKeyState(VK_NUMPAD2)<0){
		cout << "2opcja\n";
		pokaz_baze(baza);
		
		system("pause");/// getch() wywala si� na ryj
		system("cls");
		pokaz_menu();
	}
	if (GetKeyState(0x33)<0 || GetKeyState(VK_NUMPAD3)<0){
		cout << "3opcja";
		edytuj_baze(baza);
	}
	if (GetKeyState(0x34)<0 || GetKeyState(VK_NUMPAD4)<0){
		menu_wyswietl_osoby_w_wieku();
	}
	if (GetKeyState(0x35)<0 || GetKeyState(VK_NUMPAD5)<0){
		//sort_menu(baza);
	}
	if (GetKeyState(0x36)<0 || GetKeyState(VK_NUMPAD6)<0){
		cout << "6opcja";
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
			
		}
		if (GetKeyState(0x32) < 0 || GetKeyState(VK_NUMPAD2) < 0)
		{
			cout << "Znajd� osob� do usuni�cia.\nPodaj imi� LUB nazwisko LUB PESEL:";
			string osoba_do_usuniecia;
			getline(cin, osoba_do_usuniecia);
			try
			{
			vector <osoba> zestaw = znajdz_zestaw_osob(baza, osoba_do_usuniecia);
			pokaz_vector(zestaw);
			cout << "Podaj numer osoby: ";
			usun_osobe(baza,(zestaw.at((_getch() -49))));
			}
			catch (out_of_range){
				cout << " Niepowiod�o si�. Z�y zakres. \n";
			}
			catch (ExBrakOsoby& e){
				cout << e.what();
			}
			cout << "Usuni�to.";
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
	cout << "Podaj wiek:";
	cin >> wiek_;
	cout << "0.M�odsze\n1.Dok�adnie w tym wieku\n2.Starsze";
	while (true)
	{
		if (GetKeyState(0x31)<0 || GetKeyState(VK_NUMPAD1)<0){
			wyswietl_osoby_w_wieku(0, baza, wiek_);
		}
		if (GetKeyState(0x31)<0||GetKeyState(VK_NUMPAD1)<0){
			wyswietl_osoby_w_wieku(1, baza, wiek_);
			break;
		}
		if (GetKeyState(0x32)<0 || GetKeyState(VK_NUMPAD2)<0){
			wyswietl_osoby_w_wieku(2, baza, wiek_);
		}
	}

}
