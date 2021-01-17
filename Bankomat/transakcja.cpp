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
	kwota_tansakcji += d_kwota;
}

double Transakcja::pobierz_kwote_tranakcji()
{
	return kwota_tansakcji;
}

