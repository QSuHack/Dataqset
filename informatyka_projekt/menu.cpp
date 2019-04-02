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
	// tu daæ komunikat powitalny i ascii oko saurona or other else
		return true;
	}
	return false;
}
void pokaz_menu(){
	
	cout << " Tu bêdzie menu";
	cout << "\nDostêpne opcje: \n1.Wczytaj dane z pliku.\n2.Poka¿ bazê danych.\n3.Edytuj bazê danych"
		<< "\n4. \n5.\n6.\n7.\n8.\n9.";
	int position = 0;
	while (true){
	Sleep(100);  // blokowanie multi-wywo³añ funkcji przy jednym wciœniêciu klawisza
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
		cout << "Wczytano bazê.\n";

	}
	if (GetKeyState(0x32)<0 || GetKeyState(VK_NUMPAD2)<0){
		cout << "2opcja\n";
		pokaz_baze(baza);
		
		system("pause");/// getch() wywala siê na ryj
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
	cout << "Wybierz co chcesz zedytowaæ: \n1.Dodaj osobê.\n2.Usuñ osobê\n3.Edytuj rekord\n";
	while(true){
		if (GetKeyState(0x31) < 0 || GetKeyState(VK_NUMPAD1) < 0)
		{
			Sleep(200);
			std::fflush(stdin);
			dodaj_osobe(baza);
			
		}
		if (GetKeyState(0x32) < 0 || GetKeyState(VK_NUMPAD2) < 0)
		{
			cout << "ZnajdŸ osobê do usuniêcia.\nPodaj imiê LUB nazwisko LUB PESEL:";
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
				cout << " Niepowiod³o siê. Z³y zakres. \n";
			}
			catch (ExBrakOsoby& e){
				cout << e.what();
			}
			cout << "Usuniêto.";
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
	cout << "0.M³odsze\n1.Dok³adnie w tym wieku\n2.Starsze";
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
