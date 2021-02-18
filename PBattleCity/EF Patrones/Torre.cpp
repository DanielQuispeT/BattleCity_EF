#include "Torre.h"

Torre::Torre()
{
	setTipoActor(TipoActor_Torre);
	
	setDestruirDespuesMuerte(false);
}

Actor* Torre::ArmarTorre()
{
	Actor* madera = new Madera();
	madera->setAvatar(avatarMadera);
	Actor* piedra = new Piedra(); 
	piedra->setAvatar(avatarPiedra);
	Actor* bonus = new BonusEnergia(); 
	bonus->setAvatar(avatarBonus);

	return piedra;
}

void Torre::renderizar(SistemaRenderizacion* _sistemaRenderizacion)
{
	Obstaculo::renderizar(_sistemaRenderizacion);
}
