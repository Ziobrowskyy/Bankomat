#pragma once
#include <iostream>
using namespace std;

class Klient
{
public:
	Klient(int nr_konta, double stan_konta);
	void wyswietl_stan_konta();

private:

	long int nr_konta;
	double stan_konta;
};

Klient::Klient(int nr_konta, double stan_konta): nr_konta(nr_konta), stan_konta(stan_konta)
{
}

void Klient::wyswietl_stan_konta()
{
	cout << " stan konta wynosi:" << endl;
	cout << stan_konta;
}
