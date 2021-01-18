#pragma once
#include "system_bankowy.cpp"

enum ETyp_dostepu {
	SERWIS,
	KONWOJENT
};

class Dostep_sluzbowy {
public:
	Dostep_sluzbowy(ETyp_dostepu typ, int id_pracownika);
	bool weryfikacja_pracownika(int kod_dostepu);
private:
	ETyp_dostepu typ_dostepu;
	int id_pracownika;
};

Dostep_sluzbowy::Dostep_sluzbowy(ETyp_dostepu typ_dostepu, int id_pracownika) : typ_dostepu(typ_dostepu), id_pracownika(id_pracownika)
{
}

bool Dostep_sluzbowy::weryfikacja_pracownika(int kod_dostepu)
{
	return System_Bankowy::weryfikacja_pracownika(this->id_pracownika, kod_dostepu);
}
