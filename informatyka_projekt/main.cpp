#include "include.h"

using namespace std;
struct osoba
{
	string PESEL;
	string imie;
	string nazwisko;
	string miasto;
};
void pobierz_dane(vector <osoba> &baza)
{

	ifstream plik("dane.txt");
	osoba c;
	while (!plik.eof())
	{
		plik >> c.imie >> c.nazwisko >> c.PESEL >> c.miasto;
		baza.push_back(c);
	}

}
void dodaj_osobe(vector <osoba> &baza){
	osoba os;
	string os_tmp;
	cout << "\nPodaj imi�: ";
	cin >> os.imie;
	cout << "\nPodaj nazwisko: ";
	cin >> os.nazwisko; // TODO sprawdzi� czy nie puste etc.
	bool flag = false;
	while (!flag)
	{
		cout << "\nPodaj PESEL: ";
		cin >> os_tmp;
		flag = check_pesel(os_tmp);
		if (!flag){
			cout << "Niepoprawny format, spr�buj jeszcze raz!";
		}
	}
	cout << "Podaj miasto: ";
	cin >> os.miasto;
	baza.push_back(os);

}
int main()
{

	vector <osoba> baza;
	pobierz_dane(baza);
	for (auto x : baza)
	{
		cout << x.PESEL << "\n";
	}


	getch();
	return 0;
}