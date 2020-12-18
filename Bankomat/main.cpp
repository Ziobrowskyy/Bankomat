#include<iostream>
#include"osoba.cpp"

using namespace std;

int main() 
{
	int wybor;

	cout << "wybierz rodzaj transakcji:"<<endl;
	cout << "wybierz 1 - wplata" << endl;
	cout << "wybierz 2 - wyplata" << endl;
	cout << "wybierz 3 - sprawdzenie stanu konta" << endl;
	cout << "wybierz 4 - anuluj" << endl;


	cin >> wybor;

	if (wybor > 0 && wybor < 5)
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

		case 3://wyœwietl stan konta
		{
			//insert karta
			//werify karta
			// osoba.wyswietl_stan_konta();

			break;
		}

		case 4://anuluj
		{
			break;
		}
		}

	}
	else cout << "nieprawidlowy wybor" << endl;


	return 0;
}