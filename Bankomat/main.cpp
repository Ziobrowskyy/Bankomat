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
		cout << "wybierz 5 - dost�p s�u�bowy" << endl;


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
						//wysylamy nr karty do sieci i oczekujemy informacji zwrotnej o nr konta, limicie, pinie, stanie �rodk�w
						//pobieramy PIN i sprawdzamy
						bankomat.wprowadz_karte();
						bankomat.wprowadz_pin();

						if(bankomat.sprawdz_pin())
						{
							int stan_piniendzy_tansakcji = 0;
							bool kontynuacja_transakcji = true;
							do {
								//Pobieramy banknot, skanujemy, otrzymujemy informacj� zwrotna o nominale i potencjalnych uszkodzeniach
								int kwota_banknotu = bankomat.wprowadz_banknot();
								stan_piniendzy_tansakcji += kwota_banknotu;

								cout << "Dotychczas wprowadzona kwota wynosi:\t";
								cout << stan_piniendzy_tansakcji;

								cout << "Wybierz co dalej:" << endl;
								cout << "1 - kontynuuj wp�acanie banknot�w" << endl;
								cout << "2 - zako�cz wp�at�" << endl;

								int wybor;
								if (wybor == 2)
									kontynuacja_transakcji = false;
							} while (kontynuacja_transakcji);
							
							//wysy�amy informacj� do systemu z wp�aconymi pini�dzmi na zadany nr konta
							//zwracamy kart�
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
								cout << "Wprowad� banknot" << endl;
								//Pobieramy banknot, skanujemy, otrzymujemy informacj� zwrotna o nominale i potencjalnych uszkodzeniach
								stan_piniendzy = stan_piniendzy + Banknot.nominal;

								cout << stan_piniendzy;

								cout << "wybierz co dalej:" << endl;
								cout << "wybierz 1 - kontynuuj wp�acanie banknot�w" << endl;
								cout << "wybierz 2 - zako�cz wp�at�" << endl;

								int parametr;
								cin >> parametr;
								if (parametr == 2) {
									break;
								}
							}
							bilans = bilans + stan_piniendzy;
							//wysy�amy informacj� do systemu z wp�aconymi pini�dzmi na zadany nr konta
							//zwracamy kart�
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
						//wysylamy nr karty do sieci i oczekujemy informacji zwrotnej o nr konta, limicie, pinie, stanie �rodk�w
						//pobieramy PIN i sprawdzamy

						int PIN;
						cin >> PIN;

						if (PIN == Karta.pin)
						{
							int kwota = 0;

							cout << "podaj kwot� wyp�aty, podzieln� przez 10" << endl;
							cin >> kwota;

							if (kwota % 10 == 0)
							{	
								if (kwota <= osoba.stan_konta && kwota <= osoba.limit && bilans > kwota)
								{
									//wyp�a� kwota
									bilans = bilans - kwota;

									//wysy�amy informacj� do systemu z wyp�aconymi pini�dzmi z zadanego nr konta
									//zwracamy kart�
									//drukujemy potwierdzenie
								}
								else cout << "operacja nie mo�e zosta� wykoana" << endl;
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

							cout << "podaj kwot� wyp�aty, podzieln� przez 10" << endl;
							cin >> kwota;

							if (kwota % 10 == 0)
							{
								if (BL.wyplata(BLIk, kwota) == true && bilans > kwota)
								{
									//wyp�a� kwota
									bilans = bilans - kwota;

									//wysy�amy informacj� do systemu z wyp�aconymi pini�dzmi z zadanego nr konta
									//zwracamy kart�
									//drukujemy potwierdzenie
								}
								else cout << "operacja nie mo�e zosta� wykoana" << endl;
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

			case 3://wy�wietl stan konta
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
			case 5://dost�p s�u�bowy
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