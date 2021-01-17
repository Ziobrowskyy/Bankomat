#include<iostream>

using namespace std;

class Karta
{
public:
	int skan(); //zczytujemy z karty nr karty

protected:

	int nr_karty;
	int pin;

	friend class Klient;
};

