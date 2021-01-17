#pragma once
#include<iostream>
#define DEBUG_BANKNOT true
using namespace std;
enum struct EBanknot {
	DOBRY,
	USZKODZONY,
	KRADZIONY,
	NIEPOPRAWNY
};
enum struct ENominal {
	BLEDNY = 0,
	N10 = 10,
	N20 = 20,
	N50 = 50,
	N100 = 100,
	N200 = 200,
	N500 = 500
};
enum struct EWaluta {
	PLN, 
	USD, 
	EUR,
	CHF,
	GBP,
	BTC
};
class Banknot
{
public:
	ENominal nominal;
	EBanknot stan;
	EWaluta waluta;

	Banknot();

	int pobierz_wartosc() {
		return (int)nominal;
	}

private:
	//zczytujemy walute, nomian³ oraz stan banknotu
	void skan() {
		//uruchom skaner w tym miejscu itd
	}

};

Banknot::Banknot() {
	if (DEBUG_BANKNOT) {
		stan = EBanknot::DOBRY;
		waluta = EWaluta::PLN;

		cout << "Podaj nomina³ banknotu" << endl;
		int nominal;
		cin >> nominal;

		switch (nominal)
		{
		case 10: {
			this->nominal = ENominal::N10;
			break;
		}
		case 20: {
			this->nominal = ENominal::N20;
			break;
		}
		case 50: {
			this->nominal = ENominal::N50;
			break;
		}
		case 100: {
			this->nominal = ENominal::N100;
			break;
		}
		case 200: {
			this->nominal = ENominal::N200;
			break;
		}
		case 500: {
			this->nominal = ENominal::N500;
			break;
		}
		default:
			this->nominal = ENominal::BLEDNY;
			break;
		}
	}
	else {
		skan();
	}
}