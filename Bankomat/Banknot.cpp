#include<iostream>
using namespace std;

class Banknot
{
public:
	int skan(); //zczytujemy nomina�
	bool stan();//true == dobry banknot ; false == uszkodzony, kradziony ect.


private:

	int nomina� = skan();

};

