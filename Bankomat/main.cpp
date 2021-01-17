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
		cout << "wybierz 5 - dostêp s³u¿bowy" << endl;


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

								cout << "Dotychczas wprowadzona kwota wynosi:\t";
								cout << transakcja.pobierz_kwote_tranakcji();

								cout << "Wybierz co dalej:" << endl;
								cout << "1 - kontynuuj wp³acanie banknotów" << endl;
								cout << "2 - zakoñcz wp³atê" << endl;

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
								cout << "1 - kontynuuj wp³acanie banknotów" << endl;
								cout << "2 - zakoñcz wp³atê" << endl;

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
			/*
			case 2://wyplata
			{

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

						int PIN;
						cin >> PIN;

						if (PIN == Karta.pin)
						{
							int kwota = 0;

							cout << "podaj kwotê wyp³aty, podzieln¹ przez 10" << endl;
							cin >> kwota;

							if (kwota % 10 == 0)
							{
								if (kwota <= osoba.stan_konta && kwota <= osoba.limit && bilans > kwota)
								{
									//wyp³aæ kwota
									bilans = bilans - kwota;

									//wysy³amy informacjê do systemu z wyp³aconymi piniêdzmi z zadanego nr konta
									//zwracamy kartê
									//drukujemy potwierdzenie
								}
								else cout << "operacja nie mo¿e zostaæ wykoana" << endl;
								//potwierdzenie


							}

						}
						break;
					}
					case 2://blik
					{
						int BLIk;
						cin >> BLIk;
						BLIK BL = new BLIK;

						//wysylamy kod BLIK do sieci i oczekujemy na potwierdzenie
						bool weryfikacja = BLIK.weryfikacja(BLIk);

						if (weryfikacja == true)
						{
							int kwota = 0;

							cout << "podaj kwotê wyp³aty, podzieln¹ przez 10" << endl;
							cin >> kwota;

							if (kwota % 10 == 0)
							{
								if (BL.wyplata(BLIk, kwota) == true && bilans > kwota)
								{
									//wyp³aæ kwota
									bilans = bilans - kwota;

									//wysy³amy informacjê do systemu z wyp³aconymi piniêdzmi z zadanego nr konta
									//zwracamy kartê
									//drukujemy potwierdzenie
								}
								else cout << "operacja nie mo¿e zostaæ wykoana" << endl;
								//potwierdzenie


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
				//insert karta
				//werify karta
				//osoba.wyswietl_stan_konta();

				break;
			}

			case 4://anuluj
			{
				break;
			}

			case 5://dostêp s³u¿bowy
			{
				break;
			}
			*/
			default: {
				cout << "Nieprawidlowy wybor" << endl;
				break;
			}
		}

		system("pause");

	} while (true);

	return 0;
}