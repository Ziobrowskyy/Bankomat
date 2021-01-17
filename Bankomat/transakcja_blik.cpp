#pragma once
#include "system_bankowy.cpp"
#include "transakcja.cpp"

enum struct EStatus_blik {
	POPRAWNY,
	NIEPOPRAWNY,
	NIEWPROWADZONY
};

class Transakcja_blik : public Transakcja {
public:
	Transakcja_blik(ETyp_transakcji typ);
	void ustaw_kod_blik(int kod_blik);
	bool sprawdz_kod_blik();
private:
	int kod_blik = 0;
	EStatus_blik status_blik = EStatus_blik::NIEWPROWADZONY;
};

Transakcja_blik::Transakcja_blik(ETyp_transakcji typ): Transakcja(typ)
{
}

void Transakcja_blik::ustaw_kod_blik(int kod_blik)
{
	this->kod_blik = kod_blik;
	if (System_Bankowy::zweryfikuj_kod_blik(this->kod_blik)) {
		klient = System_Bankowy::pobierz_klienta(this->kod_blik);
		status_blik = EStatus_blik::POPRAWNY;
	}
	else {
		status_blik = EStatus_blik::NIEPOPRAWNY;
	}
}

bool Transakcja_blik::sprawdz_kod_blik()
{
	return status_blik == EStatus_blik::POPRAWNY;
}

