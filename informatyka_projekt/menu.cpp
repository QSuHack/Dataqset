#pragma once
#include "include.h"
#include <Windows.h>

using namespace std;
std::vector<osoba> baza;

void wstep(){
	cout << "Witaj w programie kontroli populacji.\nInformacje dostarcza Minsterstwo Prawdy.\n";
	// ci¹g dalszy fabu³y
}
void ranga(){
	cout << "Zaloguj siê: \n" << "Wybierz rangê: \n1.W I E L K I  B R A T\n2.Winston\n3.Prol\n";
	_getch();
		if (GetKeyState(0x31) < 0 || GetKeyState(VK_NUMPAD1) < 0)
		{
			if (zaloguj_jako_wielki_brat())
			{
				pokaz_menu();
				
			}
			else
			{
				cout << "Próbowa³eœ podszyæ siê pod Wielkiego Brata, lepiej sam siê zg³oœ do Ministerstwa Mi³oœci!\n";
			}
		}
		if (GetKeyState(0x32) < 0 || GetKeyState(VK_NUMPAD2) < 0){
			pokaz_menu();
		}

		if (GetKeyState(0x33) < 0 || GetKeyState(VK_NUMPAD3) < 0){
			cout << "Brak dostêpu. WeŸ, idŸ siê zajmij czymœ innym, ok? \n";
		}
		if (GetKeyState(VK_ESCAPE)<0){
			cout << "koniec";
		}
		else{
			cout << "b³¹d";
			
			ranga();
		}
}
bool zaloguj_jako_wielki_brat(){
	system("cls");
	string haslo;
	string poprawne = "BB";
	cout << "Podaj has³o dostêpu: ";
	cin >> haslo;
	if (haslo==poprawne){
	// tu daæ komunikat powitalny i ascii oko saurona
		return true;
	}
	return false;
}
void pokaz_menu(){
	cout << " Tu bêdzie menu";
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
		cout << "Wczytano bazê.";

	}
	if (GetKeyState(0x32)<0 || GetKeyState(VK_NUMPAD2)<0){
		cout << "2opcja";
		pokaz_baze(baza);
		fflush(stdin);
		system("pause");
		_getch();/// getch() wywala siê na ryj
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
	Sleep(100);  // blokowanie multi-wywo³añ funkcji przy jednym wciœniêciu klawisza
	}
}

