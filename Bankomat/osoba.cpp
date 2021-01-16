#include<iostream>
using namespace std;

class klient
{
public:

	void wyswietl_stan_konta(double stan_konta);
	bool weryfikacja(int karta,int insert_pin);

private:

	long int nr_konta;
	double stan_konta;
	int limit;


	int nr_karty;
	int pin;

};

void wyswietl_stan_konta(double stan_konta)
{
	cout << " stan konta wynosi:" << endl;
	cout << stan_konta;
}

bool klient:: weryfikacja(int karta,int insert_pin)
{
	if (nr_karty == karta)
	{
		if (pin == insert_pin)
		{
			return true;
		}
		else return false;
	}
	else return false;

}