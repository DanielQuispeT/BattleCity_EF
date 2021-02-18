#include "Piedra.h"

Piedra::Piedra()
{
	setTipoActor(TipoActor_Obstaculo);
	tipoObstaculo = TipoObstaculo_Piedra;
	setDireccion(Direccion_Ninguna);
	setAvatar(avatarPiedra);
	setDestruirDespuesMuerte(false);
}


void Piedra::renderizar(SistemaRenderizacion* _sistemaRenderizacion) {
	Obstaculo::renderizar(_sistemaRenderizacion);
}