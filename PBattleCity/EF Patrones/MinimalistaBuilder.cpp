#include "MinimalistaBuilder.h"
Piedra* getPiedra()
{
	Piedra* piedra = new Piedra();
	piedra->setAvatar(avatarPiedra);
	return piedra;
}

Madera* getMadera()
{
	Madera* madera = new Madera();
	madera->setAvatar(avatarMadera);
	return madera;
}

BonusEnergia* getBonus()
{
	BonusEnergia* bonus = new BonusEnergia();
	bonus->setAvatar(avatarBonus);
	return bonus;
}