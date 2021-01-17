#include<iostream>
#include"klient.cpp"
#include"bankomat.cpp"
#include"karta.cpp"
#include"Banknot.cpp"
#include"Blik.cpp"

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

		if (wybor > 0 && wybor < 6)
		{

			switch (wybor)
			{
			case 1://wplata
			{

				cout << "wybierz typ transakcji:" << endl;
				cout << "wybierz 1 - karta" << endl;
				cout << "wybierz 2 - blik" << endl;
				cout << "wybierz 3 - anuluj" << endl;

				cin >> wybor;

				if (wybor > 0 && wybor < 4)
				{
					switch (wybor)
					{
						case 1://karta
						{
						//pobrac karte, zczytac z niej nr karty, 
						//wysylamy nr karty do sieci i oczekujemy informacji zwrotnej o nr konta, limicie, pinie, stanie œrodków
						//pobieramy PIN i sprawdzamy
						bankomat.wprowadz_karte();
						bankomat.wprowadz_pin();

						if(bankomat.sprawdz_pin())
						{
							int stan_piniendzy_tansakcji = 0;
							bool kontynuacja_transakcji = true;
							do {
								//Pobieramy banknot, skanujemy, otrzymujemy informacjê zwrotna o nominale i potencjalnych uszkodzeniach
								int kwota_banknotu = bankomat.wprowadz_banknot();
								stan_piniendzy_tansakcji += kwota_banknotu;

								cout << "Dotychczas wprowadzona kwota wynosi:\t";
								cout << stan_piniendzy_tansakcji;

								cout << "Wybierz co dalej:" << endl;
								cout << "1 - kontynuuj wp³acanie banknotów" << endl;
								cout << "2 - zakoñcz wp³atê" << endl;

								int wybor;
								if (wybor == 2)
									kontynuacja_transakcji = false;
							} while (kontynuacja_transakcji);
							
							//wysy³amy informacjê do systemu z wp³aconymi piniêdzmi na zadany nr konta
							//zwracamy kartê
							//drukujemy potwierdzenie
						}
						break;
					}
						case 2://BLiK
						{
						int BLIk;
						cin >> BLIk;

						//wysylamy kod BLIK do sieci i oczekujemy na potwierdzenie
						bool weryfikacja = BLIK.weryfikacja(BLIk);

						if (weryfikacja == true) {
							int stan_piniendzy = 0;

							while (true) {
								cout << "WprowadŸ banknot" << endl;
								//Pobieramy banknot, skanujemy, otrzymujemy informacjê zwrotna o nominale i potencjalnych uszkodzeniach
								stan_piniendzy = stan_piniendzy + Banknot.nominal;

								cout << stan_piniendzy;

								cout << "wybierz co dalej:" << endl;
								cout << "wybierz 1 - kontynuuj wp³acanie banknotów" << endl;
								cout << "wybierz 2 - zakoñcz wp³atê" << endl;

								int parametr;
								cin >> parametr;
								if (parametr == 2) {
									break;
								}
							}
							bilans = bilans + stan_piniendzy;
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

					}
				}
				else cout << "nieprawidlowy wybor" << endl;

				break;
			}

			case 2://wyplata
			{

				cout << "wybierz typ transakcji:" << endl;
				cout << "wybierz 1 - karta" << endl;
				cout << "wybierz 2 - blik" << endl;
				cout << "wybierz 3 - anuluj" << endl;

				cin >> wybor;

				if (wybor > 0 && wybor < 4)
				{
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
						BLIK BL= new BLIK ;
						 
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

					}
				}
				else cout << "nieprawidlowy wybor" << endl;

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
			}

		}
		else cout << "nieprawidlowy wybor" << endl;


		system("pause");

	} while (true);

	return 0;
}