#pragma once
#include "include.h"
using namespace std;

// tu funkcje nie zwi¹zane ani bezpoœrednio z baz¹ ani z menu
bool check_pesel(std::string pesel){
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
std::ostream& operator<< (std::ostream& out, osoba p) // TU MO¯NA POPRAWIÆ WYŒWIETLANIE OSOBY
{
	out << p.imie << " " << p.nazwisko<<" " << p.PESEL<<" "<< p.miasto;
	return out;
}



tm get_current_time()
{
	time_t     now = time(0);
	struct tm  tstruct;
	localtime_s(&tstruct, &now);
	return tstruct;
}

