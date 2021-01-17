#pragma once
using namespace std;

class Karta {
public:
	Karta();
	Karta(int nr_karty, int pin);
	int skan();
protected:

	int nr_karty;
	int pin;

	friend class Transakcja_karta;
};

Karta::Karta() :nr_karty(-1), pin(0000)
{
}

Karta::Karta(int nr_karty, int pin) : nr_karty(nr_karty), pin(pin)
{
}

int Karta::skan()
{
	return 0;
}
