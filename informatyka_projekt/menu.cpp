#pragma once
#include "include.h"
#include <Windows.h>

using namespace std;
std::vector<osoba> baza;
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
		cout << "Wczytywanie bazy...";
		pobierz_dane(baza);
		cout << "Wczytano bazê.";

	}
	if (GetKeyState(0x32)<0 || GetKeyState(VK_NUMPAD2)<0){
		cout << "2opcja";
		pokaz_baze(baza);
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
	Sleep(100);
	}
}

