#pragma once
#include "system_bankowy.cpp"
#include "transakcja.cpp"

class Transakcja_karta : public Transakcja {

public:
	Transakcja_karta(ETyp_transakcji typ, int nr_karty);
	bool sprawdz_pin(int wprowadzony_pin) {
		return karta.pin == wprowadzony_pin;
	}
private:
	Karta karta;
};


Transakcja_karta::Transakcja_karta(ETyp_transakcji typ, int nr_karty) : Transakcja(typ) {
	this->karta = System_Bankowy::pobierz_dane_karty(nr_karty);
	this->klient = System_Bankowy::pobierz_klienta(this->karta);
}
