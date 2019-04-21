#include <Python.h>
#include <string>
#include <iostream>

using namespace std;

int wygeneruj_baze_przez_Python()
{
	string nazwa;
	Py_Initialize(); //wywo�ujemy interpreter
	PyObject* pName, * pModule, * pFunc, * pArgs, * pValue;
	pName = PyUnicode_FromString("generowanie_bazy"); // konwertujemy c++ string na string py
	pModule = PyImport_Import(pName); // importujemy modu� o nazwie pName
	Py_DECREF(pName);  // zmniejszamy liczb� referencji do pName
	if (pModule != NULL) { // je�li importowanie powiod�o si�
		pFunc = PyObject_GetAttrString(pModule, "generuj");
		if (pFunc && PyCallable_Check(pFunc))
		{
			cout << "(C++)Podaj nazw�: ";
			cin >> nazwa;

			pArgs = PyTuple_New(1); // tworzymy nowy obiekt typu krotka
			pValue = PyUnicode_FromString(nazwa.c_str()); // konwertujemy c string na string py
			if (!pValue)
			{
				Py_DECREF(pArgs);
				Py_DECREF(pModule);
			}
			PyTuple_SetItem(pArgs, 0, pValue);
			pValue = PyObject_CallObject(pFunc, pArgs);// wywo�ujemy funkcj� i przekazujemy do niej argumenty w postaci tuple 
														//(zwraca NULL w przypadku niepowodzenia)
			Py_DECREF(pArgs);
			if (pValue != NULL)
			{
				cout << "Powiod�o si�\n(c++)Baz� wygenerowano.";
				Py_DECREF(pValue);
			}
			else
			{
				Py_DECREF(pFunc);
				Py_DECREF(pModule);
				PyErr_Print();
				fprintf(stderr, "Wywo�anie nie powiod�o si�\n");
				system("pause");
				return -1;
			}
		}
		else
		{
			if (PyErr_Occurred())
				PyErr_Print();// wy�wietla b��dy
		}
		Py_XDECREF(pFunc); // zmniejsza liczb� referencji nawet je�li pFunc = NULL
		Py_DECREF(pModule);
	}
	else
	{
		PyErr_Print();
		cout << "Sprawd� czy wymagane pliki s� na w�a�ciwej �cie�ce! \n";
		system("pause");
		return -1;
	}
	if (Py_FinalizeEx() < 0) // zamyka interpreter
	{
		system("pause");
		return 120;
	}
	system("pause");
	return 0;
}


int szyfrowanie_i_deszyfrowanie(string nazwa_pliku, string klucz, int mode) {
	//mode 0 -> szyfrowanie
	//mode 1 -> deszyfrowanie
	Py_Initialize(); //wywo�ujemy interpreter
	PyObject* pName, * pModule, * pFunc, * pArgs, * pValue;
	pName = PyUnicode_FromString("aes"); // konwertujemy c++ string na string py
	pModule = PyImport_Import(pName); // importujemy modu� o nazwie pName
	Py_DECREF(pName);  // zmniejszamy liczb� referencji do pName
	if (pModule != NULL) { // je�li importowanie powiod�o si�
		if (!mode) {
			pFunc = PyObject_GetAttrString(pModule, "szyfruj");
		}
		else {
			pFunc = PyObject_GetAttrString(pModule, "deszyfruj");
		}

		if (pFunc && PyCallable_Check(pFunc))
		{
			pArgs = PyTuple_New(2); // tworzymy nowy obiekt typu krotka
			pValue = PyUnicode_FromString(nazwa_pliku.c_str()); // konwertujemy c string na string py
			if (!pValue)
			{
				Py_DECREF(pArgs);
				Py_DECREF(pModule);
			}
			PyTuple_SetItem(pArgs, 0, pValue);
			pValue = PyBytes_FromString(klucz.c_str());// konwertujemy c string na typ bajtowy python'a
			if (!pValue) {
				Py_DECREF(pArgs);
				Py_DECREF(pModule);
			}
			PyTuple_SetItem(pArgs, 1, pValue); // wstawiamy na indeks 1 przekonwertowan� warto�� klucza
			pValue = PyObject_CallObject(pFunc, pArgs);// wywo�ujemy funkcj� i przekazujemy do niej argumenty w postaci tuple 
														//(zwraca NULL w przypadku niepowodzenia)
			Py_DECREF(pArgs);
			if (pValue != NULL)
			{
				cout << "Zaszyfrowano";
				Py_DECREF(pValue);
			}
			else
			{
				Py_DECREF(pFunc);
				Py_DECREF(pModule);
				PyErr_Print();
				fprintf(stderr, "Wywo�anie nie powiod�o si�\n");
				system("pause");
				return -1;
			}
		}
		else
		{
			if (PyErr_Occurred())
				PyErr_Print();// wy�wietla b��dy
		}
		Py_XDECREF(pFunc); // zmniejsza liczb� referencji nawet je�li pFunc = NULL
		Py_DECREF(pModule);
	}
	else
	{
		PyErr_Print();
		system("pause");
		return -1;
	}
	if (Py_FinalizeEx() < 0) // zamyka interpreter
	{
		system("pause");
		return 120;
	}
	system("pause");
	return 0;

}
void menu_szyfrowanie() {
	string nazwa, klucz;
	int mode = 0;
	cout << "\nChcesz zaszyfrowa� (0) czy zdeszyfrowa� plik(1) ?";
	cin >> mode;
	cout << "\nPodaj nazw� pliku: ";
	cin >> nazwa;
	cout << "\nPodaj klucz: ";
	cin >> klucz;
	szyfrowanie_i_deszyfrowanie(nazwa, klucz, mode);

}
