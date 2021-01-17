#pragma once
#include <iostream>
using namespace std;

class Klient
{
public:
	Klient(int nr_konta, double stan_konta);
	double pobierz_stan_konta();

private:

	long int nr_konta;
	double stan_konta;
};

Klient::Klient(int nr_konta, double stan_konta): nr_konta(nr_konta), stan_konta(stan_konta)
{
}

double Klient::pobierz_stan_konta()
{
	return stan_konta;
}
