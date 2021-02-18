#include "Madera.h"

Madera::Madera()
{
	setTipoActor(TipoActor_Obstaculo);
	tipoObstaculo = TipoObstaculo_Madera;
	setDireccion(Direccion_Ninguna);
	setAvatar(avatarMadera);
	setDestruirDespuesMuerte(false);
}


void Madera::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Obstaculo::renderizar(_sistemaRenderizacion);
}