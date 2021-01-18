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
	int pobierz_kwote_wyplaty();
	void dodaj_srodki(int srodki);
	void operacja_konwojenta();
	bool czy_mozna_wyplacic(int kwota);
	int wprowadz_id_pracownika();
	int wprowadz_kod_dostepu();

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

int Bankomat::pobierz_kwote_wyplaty()
{
	cout << "Wprowadz kwote do wyplacenia:" << endl;
	int kwota;
	cin >> kwota;
	if (kwota % 10 == 0 && kwota > 0) {
		return kwota;
	}
	else {
		cout << "Niepoprawna kwota transakcji" << endl;
		return 0;
	}
}

void Bankomat::dodaj_srodki(int srodki)
{

}

void Bankomat::operacja_konwojenta()
{
	srodki = 1000;
}

bool Bankomat::czy_mozna_wyplacic(int kwota)
{
	return kwota < this->srodki;
}

int Bankomat::wprowadz_id_pracownika()
{
	cout << "Podaj id pracownika" << endl;
	int id;
	cin >> id;
	return id;
}

int Bankomat::wprowadz_kod_dostepu()
{
	cout << "Podaj kod dostepu" << endl;
	int kod;
	cin >> kod; 
	return kod;
}
