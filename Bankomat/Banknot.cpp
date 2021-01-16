#include<iostream>
using namespace std;

class Banknot
{
public:
	int skan(); //zczytujemy nomina³
	bool stan();//true == dobry banknot ; false == uszkodzony, kradziony ect.


private:

	int nomina³ = skan();

};

