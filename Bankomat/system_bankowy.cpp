#pragma once
#include "klient.cpp"
#include "karta.cpp"
#define DEBUG_SYSTEM_BANKOWY true
class System_Bankowy {
public:
	static Karta pobierz_dane_karty(int nr_karty);
	static bool zasil_konto(Klient klient, int kwota);
	static Klient* pobierz_klienta(Karta karta);
	static bool zweryfikuj_kod_blik(int kod_blik);
	static Klient* pobierz_klienta(int kod_blik);
};

Karta System_Bankowy::pobierz_dane_karty(int nr_karty) {
	//dostep do bazy danych
	Karta pobrana_karta;
	if (DEBUG_SYSTEM_BANKOWY) {
		pobrana_karta = Karta(1234, 1234);
	}
	else {
		//TODO:
		//dostep do bazy danych
	}
	return pobrana_karta;
}

bool System_Bankowy::zasil_konto(Klient klient, int kwota) {

	return true;
}

Klient* System_Bankowy::pobierz_klienta(Karta karta)
{
	if (DEBUG_SYSTEM_BANKOWY) {
		return new Klient(789456123, 1500);
	}
	else {
		//TODO:
		//pobierz dane klienta z bazy danych na podstawie karty
	}
}
Klient* System_Bankowy::pobierz_klienta(int kod_blik)
{
	if (DEBUG_SYSTEM_BANKOWY) {
		return new Klient(789456123, 1500);
	}
	else {
		//TODO:
		//pobierz dane klienta z bazy danych na podstawie karty
	}
}

bool System_Bankowy::zweryfikuj_kod_blik(int kod_blik)
{
	if (DEBUG_SYSTEM_BANKOWY) {
		return true;
	}
	else {
		//TODO:
		//Sprawdz w bazie danych czy dany kod blik jest prawidlowy
	}
}


