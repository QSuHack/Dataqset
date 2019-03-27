#pragma once
#include "include.h"
#include <Windows.h>

using namespace std;
std::vector<osoba> baza;

void wstep(){
	cout << "Witaj w programie kontroli populacji.\nInformacje dostarcza Minsterstwo Prawdy.\n";
	// ciąg dalszy fabuły
}
void ranga(){
	cout << "Zaloguj się: \n" << "Wybierz rangę: \n1.W I E L K I  B R A T\n2.Winston\n3.Prol\n";
	_getch();
		if (GetKeyState(0x31) < 0 || GetKeyState(VK_NUMPAD1) < 0)
		{
			if (zaloguj_jako_wielki_brat())
			{
				pokaz_menu();
				
			}
			else
			{
				cout << "Próbowałeś podszyć się pod Wielkiego Brata, lepiej sam się zgłoś do Ministerstwa Miłości!\n";
			}
		}
		if (GetKeyState(0x32) < 0 || GetKeyState(VK_NUMPAD2) < 0){
			pokaz_menu();
		}

		if (GetKeyState(0x33) < 0 || GetKeyState(VK_NUMPAD3) < 0){
			cout << "Brak dostępu. Weź, idź się zajmij czymś innym, ok? \n";
		}
		if (GetKeyState(VK_ESCAPE)<0){
			cout << "koniec";
		}
		else{
			cout << "błąd";
			
			ranga();
		}
}
bool zaloguj_jako_wielki_brat(){
	system("cls");
	string haslo;
	string poprawne = "BB";
	cout << "Podaj hasło dostępu: ";
	cin >> haslo;
	if (haslo==poprawne){
	// tu dać komunikat powitalny i ascii oko saurona
		return true;
	}
	return false;
}
void pokaz_menu(){
	cout << " Tu będzie menu";
	cout << "dostepne opcje: 1-in ,2||3-out";
	int position = 0;
	while (true){
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
		cout << "Wczytano bazę.";

	}
	if (GetKeyState(0x32)<0 || GetKeyState(VK_NUMPAD2)<0){
		cout << "2opcja";
		pokaz_baze(baza);
		fflush(stdin);
		system("pause");
		_getch();/// getch()
		system("cls");
	}
	if (GetKeyState(0x33)<0 || GetKeyState(VK_NUMPAD3)<0){
		cout << "3opcja";
		pokaz_baze(baza);
	}
	if (GetKeyState(0x34)<0 || GetKeyState(VK_NUMPAD4)<0){
		cout << "4opcja";
	}
	if (GetKeyState(0x35)<0 || GetKeyState(VK_NUMPAD5)<0){
		cout << "5opcja";
	}
	if (GetKeyState(0x36)<0 || GetKeyState(VK_NUMPAD6)<0){
		cout << "6opcja";
	}
	Sleep(100);  // blokowanie multi-wywołań funkcji przy jednym wciśnięciu klawisza
	}
}

