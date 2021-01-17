#pragma once
#include "klient.cpp"
#include "banknot.cpp"

using namespace std;
#define DEBUG_BANKOMAT true
class Bankomat {

public:
	Bankomat() {

	}
	int wprowadz_karte();
	int wprowadz_pin();
	int wprowadz_banknot();
	int wprowadz_blik();
	void dodaj_srodki(int srodki);

private:
	int srodki = rand() % 9000 + 1000;
};

int Bankomat::wprowadz_karte() {
	cout << "wprowadz karte" << endl;
	int nr_karty;
	cin >> nr_karty;
	if (DEBUG_BANKOMAT) {
		return 1234;
	}
	else {
		return nr_karty;
	}
}

int Bankomat::wprowadz_pin() {
	cout << "wprowadz kod PIN" << endl;
	int wprowadzony_pin;
	cin >> wprowadzony_pin;
	return wprowadzony_pin;
}

int Bankomat::wprowadz_banknot() {
	cout << "Wprowadz banknot" << endl;
	Banknot banknot;
	return banknot.pobierz_wartosc();
}

int Bankomat::wprowadz_blik()
{
	cout << "Wprowadz kod BLIK" << endl;
	int blik;
	cin >> blik;
	return blik;
}

void Bankomat::dodaj_srodki(int srodki)
{

}
