#include<iostream>
#include "osoba.cpp"
#include "karta.cpp"

using namespace std;

class Klient : public Osoba
{
public:
	Klient (){

	}
	void wyswietl_stan_konta(double stan_konta);
	bool weryfikacja(int karta,int insert_pin);
	bool weryfikacja(int insert_pin);
	Karta getKarta();

private:

	long int nr_konta;
	double stan_konta;
	int limit;

	Karta karta;

};

void wyswietl_stan_konta(double stan_konta)
{
	cout << " stan konta wynosi:" << endl;
	cout << stan_konta;
}

bool Klient::weryfikacja(int karta, int insert_pin)
{
	
	if (this->karta.nr_karty == karta && this->karta.pin == insert_pin)
	{
		return true;
	}
	return false;

}
bool Klient::weryfikacja(int insert_pin)
{
	
	if (this->karta.pin == insert_pin)
	{
		return true;
	}
	return false;

}

Karta Klient::getKarta() {
	return this->karta;
}