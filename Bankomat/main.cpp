#pragma once
#include "bankomat.cpp"
#include "transakcja_blik.cpp"
#include "transakcja_karta.cpp"
#include <iostream>
using namespace std;

int main() 
{
	Bankomat bankomat;
	int wybor;
	do 
	{

		cout << "wybierz rodzaj transakcji:" << endl;
		cout << "wybierz 1 - wplata" << endl;
		cout << "wybierz 2 - wyplata" << endl;
		cout << "wybierz 3 - sprawdzenie stanu konta" << endl;
		cout << "wybierz 4 - anuluj" << endl;
		cout << "wybierz 5 - dostep sluzbowy" << endl;


		cin >> wybor;

		switch (wybor)
		{
			case 1://wplata
			{
				ETyp_transakcji typ_transakcji = WPLATA;
				cout << "wybierz typ transakcji:" << endl;
				cout << "wybierz 1 - karta" << endl;
				cout << "wybierz 2 - blik" << endl;
				cout << "wybierz 3 - anuluj" << endl;

				cin >> wybor;

				
				switch (wybor)
				{
					case 1://karta
					{
						//pobrac karte, zczytac z niej nr karty, 
						//wysylamy nr karty do sieci i oczekujemy informacji zwrotnej o nr konta, limicie, pinie, stanie œrodków
						//pobieramy PIN i sprawdzamy
						int wprowadzona_karta = bankomat.wprowadz_karte();
						int wprowadzony_pin = bankomat.wprowadz_pin();
						Transakcja_karta transakcja = Transakcja_karta(typ_transakcji, wprowadzona_karta);

						if (transakcja.sprawdz_pin(wprowadzony_pin))
						{
							bool kontynuacja_transakcji = true;
							do {
								//Pobieramy banknot, skanujemy, otrzymujemy informacjê zwrotna o nominale i potencjalnych uszkodzeniach
								int kwota_banknotu = bankomat.wprowadz_banknot();
								transakcja.zmien_kwote_tranakcji(kwota_banknotu);

								if (kwota_banknotu == 0) {
									cout << "Nieporawny nonimal banknotu" << endl;
								}
								else {
									cout << "Dotychczas wprowadzona kwota wynosi:\t";
									cout << transakcja.pobierz_kwote_tranakcji() << endl;
								}

								cout << "Wybierz co dalej:" << endl;
								cout << "1 - kontynuuj wplacanie banknotow" << endl;
								cout << "2 - zakoncz wplate" << endl;

								cin >> wybor;
								if (wybor == 2)
									kontynuacja_transakcji = false;

							} while (kontynuacja_transakcji);

							//TODO:
							//wysy³amy informacjê do systemu z wp³aconymi piniêdzmi na zadany nr konta
							//zwracamy kartê
							//drukujemy potwierdzenie
						}
						break;
					}
					case 2://BLiK
					{
						//pobrac karte, zczytac z niej nr karty, 
						//wysylamy nr karty do sieci i oczekujemy informacji zwrotnej o nr konta, limicie, pinie, stanie œrodków
						//pobieramy PIN i sprawdzamy
						int wprowadzony_kod_blik = bankomat.wprowadz_blik();
						Transakcja_blik transakcja = Transakcja_blik(typ_transakcji);
						transakcja.ustaw_kod_blik(wprowadzony_kod_blik);
						if (transakcja.sprawdz_kod_blik())
						{
							bool kontynuacja_transakcji = true;
							do {
								//Pobieramy banknot, skanujemy, otrzymujemy informacjê zwrotna o nominale i potencjalnych uszkodzeniach
								int kwota_banknotu = bankomat.wprowadz_banknot();
								transakcja.zmien_kwote_tranakcji(kwota_banknotu);

								cout << "Dotychczas wprowadzona kwota wynosi:\t";
								cout << transakcja.pobierz_kwote_tranakcji() << endl;

								cout << "Wybierz co dalej:" << endl;
								cout << "1 - kontynuuj wplacanie banknotow" << endl;
								cout << "2 - zakoncz wplate" << endl;

								cin >> wybor;
								if (wybor == 2)
									kontynuacja_transakcji = false;
							} while (kontynuacja_transakcji);

							//TODO:
							//wysy³amy informacjê do systemu z wp³aconymi piniêdzmi na zadany nr konta
							//zwracamy kartê
							//drukujemy potwierdzenie
						}
						break;
					}
					case 3://anuluj
					{
						break;
					}
					default: {
						cout << "Nieprawidlowy wybor" << endl;
						break;
					}
				}
				
				break;

			}
			
			case 2://wylata
			{
				ETyp_transakcji typ_transakcji = WYPLATA;
				cout << "wybierz typ transakcji:" << endl;
				cout << "wybierz 1 - karta" << endl;
				cout << "wybierz 2 - blik" << endl;
				cout << "wybierz 3 - anuluj" << endl;

				cin >> wybor;

				switch (wybor)
				{
				case 1://karta
				{
					//pobrac karte, zczytac z niej nr karty, 
					//wysylamy nr karty do sieci i oczekujemy informacji zwrotnej o nr konta, limicie, pinie, stanie œrodków
					//pobieramy PIN i sprawdzamy
					int wprowadzona_karta = bankomat.wprowadz_karte();
					int wprowadzony_pin = bankomat.wprowadz_pin();
					Transakcja_karta transakcja = Transakcja_karta(typ_transakcji, wprowadzona_karta);

					bool prawidlowy_pin = transakcja.sprawdz_pin(wprowadzony_pin);

					if (!prawidlowy_pin) {
						cout << "Nieprawidlowy PIN" << endl;
					}
					else {
						//pobierz kwote transakcji
						int kwota_transakcji = bankomat.pobierz_kwote_wyplaty();

						transakcja.zmien_kwote_tranakcji(kwota_transakcji);
						
						//sprawdz czy kwota moze byc wyplacona przez bankomat oraz stan konta
						bool czy_mozna_wyplacic = true;
						if (!bankomat.czy_mozna_wyplacic(kwota_transakcji)) {
							cout << "Brak wystarczajacych srodkow w bankomacie" << endl;
							czy_mozna_wyplacic = false;
						}
						else if (!transakcja.czy_mozna_wyplacic()) {
							cout << "Brak wystarczajacych srodkow na koncie" << endl;
							czy_mozna_wyplacic = false;
						}

						//przejdz do wyplaty jesli warunki zostaly spelnione
						if (czy_mozna_wyplacic) {
							//TODO: wyplac srodki z bankomatu
							//wysy³amy informacjê do systemu z wp³aconymi piniêdzmi na zadany nr konta
							//zwracamy kartê
							//drukujemy potwierdzenie
						}
					}
					break;
				}
				case 2://BLiK
				{
					//pobrac karte, zczytac z niej nr karty, 
					//wysylamy nr karty do sieci i oczekujemy informacji zwrotnej o nr konta, limicie, pinie, stanie œrodków
					//pobieramy PIN i sprawdzamy
					int wprowadzony_kod_blik = bankomat.wprowadz_blik();
					Transakcja_blik transakcja = Transakcja_blik(typ_transakcji);
					transakcja.ustaw_kod_blik(wprowadzony_kod_blik);
					if (!transakcja.sprawdz_kod_blik()) {
						cout << "Nieprawidlowy kod BLIK" << endl;
					}
					else {
						//pobierz kwote transakcji
						int kwota_transakcji = bankomat.pobierz_kwote_wyplaty();

						transakcja.zmien_kwote_tranakcji(kwota_transakcji);

						//sprawdz czy kwota moze byc wyplacona przez bankomat oraz stan konta
						bool czy_mozna_wyplacic = true;
						if (!bankomat.czy_mozna_wyplacic(kwota_transakcji)) {
							cout << "Brak wystarczajacych srodkow w bankomacie" << endl;
							czy_mozna_wyplacic = false;
						}
						else if (!transakcja.czy_mozna_wyplacic()) {
							cout << "Brak wystarczajacych srodkow na koncie" << endl;
							czy_mozna_wyplacic = false;
						}

						//przejdz do wyplaty jesli warunki zostaly spelnione
						if (czy_mozna_wyplacic) {
							//TODO: wyplac srodki z bankomatu
							//wysy³amy informacjê do systemu z wp³aconymi piniêdzmi na zadany nr konta
							//zwracamy kartê
							//drukujemy potwierdzenie
						}
					}
					break;
				}
				case 3://anuluj
				{
					break;
				}
				default: {
					cout << "Nieprawidlowy wybor" << endl;
					break;
				}
				}

				break;
			}
			
			case 3://wyœwietl stan konta
			{
				ETyp_transakcji typ_transakcji = STAN_KONTA;
				cout << "wybierz typ transakcji:" << endl;
				cout << "wybierz 1 - karta" << endl;
				cout << "wybierz 2 - blik" << endl;
				cout << "wybierz 3 - anuluj" << endl;

				cin >> wybor;


				switch (wybor)
				{
					case 1://karta
					{
						int wprowadzona_karta = bankomat.wprowadz_karte();
						int wprowadzony_pin = bankomat.wprowadz_pin();
						Transakcja_karta transakcja = Transakcja_karta(typ_transakcji, wprowadzona_karta);

						bool prawidlowy_pin = transakcja.sprawdz_pin(wprowadzony_pin);

						if (!prawidlowy_pin) {
							cout << "Nieprawidlowy PIN" << endl;
						}
						else {
							double stan_konta = transakcja.pobierz_stan_konta();
							cout << "Stan konta wynosi: " << endl;
							cout << stan_konta << endl;
						}
						break;
					}
					case 2://BLiK
					{
						//pobrac karte, zczytac z niej nr karty, 
						//wysylamy nr karty do sieci i oczekujemy informacji zwrotnej o nr konta, limicie, pinie, stanie œrodków
						//pobieramy PIN i sprawdzamy
						int wprowadzony_kod_blik = bankomat.wprowadz_blik();
						Transakcja_blik transakcja = Transakcja_blik(typ_transakcji);
						transakcja.ustaw_kod_blik(wprowadzony_kod_blik);
						if (!transakcja.sprawdz_kod_blik()) {
							cout << "Nieprawidlowy kod BLIK" << endl;
						}
						else {
							double stan_konta = transakcja.pobierz_stan_konta();
							cout << "Stan konta wynosi: " << endl;
							cout << stan_konta << endl;
						}
						break;
					}
					case 3://anuluj
					{
						break;
					}
					default: {
						cout << "Nieprawidlowy wybor" << endl;
						break;
					}
				}

				break;
			}
			
			case 4://anuluj
			{
				break;
			}

			case 5://dostêp s³u¿bowy
			{
				cout << "wybierz typ dostepu:" << endl;
				cout << "wybierz 1 - serwisant" << endl;
				cout << "wybierz 2 - konwojent" << endl;
				cout << "wybierz 3 - anuluj" << endl;
				cin >> wybor;

				switch (wybor)
				{
					case 1: //serwisant 
					{

						int id_pracownika = bankomat.wprowadz_id_pracownika();
						int kod_dostepu = bankomat.wprowadz_kod_dostepu();
						Dostep_sluzbowy dostep = Dostep_sluzbowy(SERWIS, id_pracownika);
						if (!dostep.weryfikacja_pracownika(kod_dostepu)) {
							cout << "Nieprawidlowy kod dostepu lub id pracownika" << endl;
						}
						else {
							cout << "Mozesz teraz przeprowadzic czynnosci serwisowe" << endl;
							system("pause");
							cout << "Zakonczono przeprowadzenie czynnosci serwisowych" << endl;
						}
						break;
					}
					case 2: //konwojent
					{
						int id_pracownika = bankomat.wprowadz_id_pracownika();
						int kod_dostepu = bankomat.wprowadz_kod_dostepu();
						Dostep_sluzbowy dostep = Dostep_sluzbowy(KONWOJENT, id_pracownika);
						if (!dostep.weryfikacja_pracownika(kod_dostepu)) {
							cout << "Nieprawidlowy kod dostepu lub id pracownika" << endl;
						}
						else {
							cout << "Umozliwono dostep do systemu pienieznego bankomatu. Przeproadz czynnosci konwojenckie." << endl;
							system("pause");
							cout << "Zablokowano dostep do systemu pienieznego bankomatu. Zakocznono przeproawdzenie czynnosci serwisowych" << endl;
						}
						break;
					}
					case 3: //anuluj
					{
						break;
					}
					default: 
					{
						cout << "Nieprawidlowy wybor" << endl;
						break;
					}
				}

				break;
			}
			
			default: 
			{
				cout << "Nieprawidlowy wybor" << endl;
				break;
			}
		}

		system("pause");

	} while (true);

	return 0;
}