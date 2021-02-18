#include "BonusEnergia.h"

BonusEnergia::BonusEnergia()
{
	setTipoActor(TipoActor_Obstaculo);
	tipoObstaculo = TipoObstaculo_BonusEnergia;
	setDireccion(Direccion_Ninguna);
	setAvatar(avatarBonus);
	//setFisico(false);
}


void BonusEnergia::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Obstaculo::renderizar(_sistemaRenderizacion);
}