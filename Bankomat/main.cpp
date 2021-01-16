#include<iostream>
#include"osoba.cpp"
#include"karta.cpp"
#include"banknot.cpp"
#include"BLIK.cpp"




using namespace std;

int main() 
{
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

						int PIN;
						cin >> PIN;

						if (PIN == karta.pin) {
							int stan_piniendzy = 0;

							while (true) {
								cout << "Wprowad� banknot" << endl;
								//Pobieramy banknot, skanujemy, otrzymujemy informacj� zwrotna o nominale i potencjalnych uszkodzeniach
								stan_piniendzy = stan_piniendzy + banknot.nominal;

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
							//wysy�amy informacj� do systemu z wp�aconymi pini�dzmi na zadany nr konta
							//zwracamy kart�
							//drukujemy potwierdzenie
						}
						break;
					}
					case 2://BLiK
					{
						int BLIK;
						cin >> BLIK;

						//wysylamy kod BLIK do sieci i oczekujemy na potwierdzenie
						bool weryfikacja = BLIK.weryfikacja(BLIK);
							
						if (weryfikacja == true) {
							int stan_piniendzy = 0;

							while (true) {
								cout << "Wprowad� banknot" << endl;
								//Pobieramy banknot, skanujemy, otrzymujemy informacj� zwrotna o nominale i potencjalnych uszkodzeniach
								stan_piniendzy = stan_piniendzy + banknot.nominal;

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
						break;
					}

					case 2://blik
					{

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

	}while (true);

	return 0;
}