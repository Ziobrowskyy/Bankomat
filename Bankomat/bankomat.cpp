#include <iostream>
#include "klient.cpp"
using namespace std;

class Bankomat {
	Klient klient;
	int wprowadzony_pin;

public:
	Bankomat() {

	}
	void wprowadz_karte() {
		cout << "wprowadz karte" << endl;
		int dupa;
		cin >> dupa;
	}

	void wprowadz_pin() {
		cout << "wprowadz kod PIN" << endl;
		cin >> wprowadzony_pin;
	}
	bool sprawdz_pin() {
		return klient.weryfikacja(wprowadzony_pin);
	}
	void wprowadz_banknot() {
		cout << "Wprowadz banknot" << endl;

	}
};