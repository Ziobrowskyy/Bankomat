#pragma once
#include"klient.cpp"

enum ETyp_transakcji {
	WPLATA,
	WYPLATA,
	STAN_KONTA
};

class Transakcja {
public:

	Transakcja(ETyp_transakcji typ);
	void zmien_kwote_tranakcji(double d_kwota);
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

