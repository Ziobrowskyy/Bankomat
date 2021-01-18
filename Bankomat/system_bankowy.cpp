#pragma once
#include "karta.cpp"
#include "klient.cpp"

#define DEBUG_SYSTEM_BANKOWY true
Klient* klient1 = new Klient(1234, 1000);
class System_Bankowy {
public:
	static Karta pobierz_dane_karty(int nr_karty);
	static bool zasil_konto(Klient klient, int kwota);
	static bool obciaz_konto(Klient klient, int kwota);
	static Klient* pobierz_klienta(Karta karta);
	static bool zweryfikuj_kod_blik(int kod_blik);
	static Klient* pobierz_klienta(int kod_blik);
	static bool weryfikacja_pracownika(int nr_pracownika, int kod_dostepu);
private:

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
	if (DEBUG_SYSTEM_BANKOWY) {
		klient.stan_konta += kwota;
		return true;
	}
	return false;
}

bool System_Bankowy::obciaz_konto(Klient klient, int kwota)
{
	if (DEBUG_SYSTEM_BANKOWY) {
		klient.stan_konta -= kwota;
		return true;
	}
	return false;
}
Klient* System_Bankowy::pobierz_klienta(Karta karta)
{
	if (DEBUG_SYSTEM_BANKOWY) {
		return klient1;
	}
	else {
		//TODO:
		//pobierz dane klienta z bazy danych na podstawie karty
		return nullptr; 
	}
}

Klient* System_Bankowy::pobierz_klienta(int kod_blik)
{
	if (DEBUG_SYSTEM_BANKOWY) {
		return klient1;
	}
	else {
		//TODO:
		//pobierz dane klienta z bazy danych na podstawie karty
		return nullptr;
	}
}

bool System_Bankowy::weryfikacja_pracownika(int nr_pracownika, int kod_dostepu)
{
	if (DEBUG_SYSTEM_BANKOWY) {
		//sprawdz haslo
		if (kod_dostepu != nr_pracownika + 1) {
			return false;
		}
		//sprawdz czy typ pracownika jest odpowiedni
		if (nr_pracownika < 1000) { //konwojent
			return true;
		}
		else if(nr_pracownika >= 1000 && nr_pracownika < 2000) { // serwisant
			return true;
		}
		return false;
	}
	else {
		//zweryfikuj dane pracownika w bazie danych
	}
}

bool System_Bankowy::zweryfikuj_kod_blik(int kod_blik)
{
	if (DEBUG_SYSTEM_BANKOWY) {
		return kod_blik % 2 == 0 && kod_blik > 1000;
	}
	else {
		//TODO:
		//Sprawdz w bazie danych czy dany kod blik jest prawidlowy
	}
}


