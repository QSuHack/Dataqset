

#include "include.h"
#include <chrono>
#include <locale.h>

using namespace std;
int main()
{

	setlocale(LC_ALL, "polish");
	pobierz_dane(baza);	
	
	wstep();
	ranga();

	system("pause");

	return 0;
}


