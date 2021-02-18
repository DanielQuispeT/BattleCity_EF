#pragma once
#include "Torre.cpp"
class Builder
{
public:
	virtual Piedra* getPiedra() = 0;
	virtual Madera* getMadera() = 0;
	virtual BonusEnergia* getBonus() = 0;
};

