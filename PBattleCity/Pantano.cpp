#include "Pantano.h"

Pantano::Pantano()
{
	setTipoActor(TipoActor_Obstaculo);
	tipoObstaculo = TipoObstaculo_Pantano;
	setDireccion(Direccion_Ninguna);
	setAvatar(avatarPantanoN1);
	setFisico(false);
}


void Pantano::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Obstaculo::renderizar(_sistemaRenderizacion);
}
