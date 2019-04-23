#pragma once
#include "include.h"
using namespace std;

// tu funkcje nie zwiï¿½zane ani bezpoï¿½rednio z bazï¿½ ani z menu
bool check_pesel(std::string pesel){
if (pesel.length() != 11){
	return false;
}
if ((1* (int)pesel[0] + 3* (int)pesel[1] + 7* (int)pesel[2] + 9* (int)pesel[3]
	+ 1* (int)pesel[4] + 3* (int)pesel[5]+ 7 * (int)pesel[6] + 9 * (int)pesel[7]
	+ 1 * (int)pesel[8] + 3 * (int)pesel[9] + 1 * (int)pesel[10]) %10 == 0)
{
	return true;
}
else{
	return false;
}
}

std::ostream& operator<< (std::ostream& out, osoba p) // TODO TU MO¯NA POPRAWIÆ WYŒWIETLANIE OSOBY

{
	out << setw(15) << p.imie << " " << setw(20) << p.nazwisko << " " << setw(20) << p.miasto << " " << 
		setw(10)
		<<p.data_urodzenia.tm_mday << "." << setw(2)<< p.data_urodzenia.tm_mon <<"." << setw(4)<< p.data_urodzenia.tm_year
		<<" " << setw(15) << p.PESEL <<  setw(15) <<" wiek: " << p.zwroc_wiek();
	return out;
}



tm get_current_time()
{
	time_t now = time(0);
	struct tm tstruct;
	localtime_s(&tstruct, &now);
	return tstruct;
}

