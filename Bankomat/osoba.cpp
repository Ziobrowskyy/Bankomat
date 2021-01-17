#include<string>
using namespace std;
class Osoba {
	string imie;
	string nazwisko;
	Data data_urodzenia;
	int PESEL;
	Osoba() : data_urodzenia(10,10,10) {
	}
};

class Data {
	int dzien;
	int miesiac;
	int rok;
public: 
	Data(int dzien, int miesiac, int rok) : dzien(dzien), miesiac(miesiac), rok(rok) {
	}
};

