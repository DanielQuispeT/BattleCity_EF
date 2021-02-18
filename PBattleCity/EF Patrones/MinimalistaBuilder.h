#pragma once
#include "Builder.h"
class MinimalistaBuilder :
    public Builder
{
public:
	Piedra* getPiedra();
	Madera* getMadera();
	BonusEnergia* getBonus();
};

