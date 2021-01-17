#include<iostream>
#define DEBUG true
using namespace std;
enum EBanknot {
	DOBRY,
	USZKODZONY,
	KRADZIONY,
	NIEPOPRAWNY
};
enum ENominal {
	BLEDNY = 0,
	N10 = 10,
	N20 = 20,
	N50 = 50,
	N100 = 100,
	N200 = 200,
	N500 = 500
};
enum EWaluta {
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
		return nominal;
	}

private:
	//zczytujemy walute, nomian³ oraz stan banknotu
	void skan() {
		//uruchom skaner w tym miejscu itd
	}

};

Banknot::Banknot() {
	if (DEBUG) {
		stan = DOBRY;
		waluta = PLN;

		cout << "Podaj nomina³ banknotu" << endl;
		int nominal;
		cin >> nominal;

		switch (nominal)
		{
		case 10: {
			this->nominal = N10;
			break;
		}
		case 20: {
			this->nominal = N20;
			break;
		}
		case 50: {
			this->nominal = N50;
			break;
		}
		case 100: {
			this->nominal = N100;
			break;
		}
		case 200: {
			this->nominal = N200;
			break;
		}
		case 500: {
			this->nominal = N500;
			break;
		}
		default:
			this->nominal = BLEDNY;
			break;
		}
	}
	else {
		skan();
	}
}