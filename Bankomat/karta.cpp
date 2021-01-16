#include<iostream>
using namespace std;

class karta
{
public:
	int skan(); //zczytujemy z karty nr karty
	osoba informacje(int nr_karty_bankomatowej);


private:

	int nr_karty_bankomatowej;
	int pin;


};

