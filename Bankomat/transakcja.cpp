#pragma once
#include"klient.cpp"
#include "system_bankowy.cpp"
enum ETyp_transakcji {
	WPLATA,
	WYPLATA,
	STAN_KONTA
};


class Transakcja {
public:

	Transakcja(ETyp_transakcji typ);
	void zmien_kwote_tranakcji(double d_kwota);
	bool zakoncz_transakcje();
	double pobierz_kwote_tranakcji();
	bool czy_mozna_wyplacic();
	double pobierz_stan_konta();

protected:

	Klient* klient = nullptr;
	ETyp_transakcji typ_transakcji;
	double kwota_tansakcji = 0;
	
};

Transakcja::Transakcja(ETyp_transakcji typ): typ_transakcji(typ)
{

}

void Transakcja::zmien_kwote_tranakcji(double d_kwota)
{
	this->kwota_tansakcji += d_kwota;
}

bool Transakcja::zakoncz_transakcje()
{
	if (typ_transakcji == WPLATA) {
		return System_Bankowy::zasil_konto(*klient, kwota_tansakcji);
	}
	else if (typ_transakcji == WYPLATA) {
		return System_Bankowy::obciaz_konto(*klient, kwota_tansakcji);
	}
	return false;
}

double Transakcja::pobierz_kwote_tranakcji()
{
	return this->kwota_tansakcji;
}

bool Transakcja::czy_mozna_wyplacic()
{
	return this->typ_transakcji == WYPLATA && this->kwota_tansakcji < klient->pobierz_stan_konta();
}

double Transakcja::pobierz_stan_konta()
{
	if (this->typ_transakcji == STAN_KONTA) {
		return klient->pobierz_stan_konta();
	}
	else return -1;
}

