#pragma once
#include "BaseDecorador.h"
class ProteccionDecorador : public BaseDecorador
{
public:
    ProteccionDecorador(IBase* iBase) : BaseDecorador(iBase) {
		setTipoActor(TipoActor_Base);

		setAncho(columnasBase+2);
		setAlto(filasBase+1);

		setEnergia(energiaBase+3);
		setDestruirDespuesMuerte(false);
	};

    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
};

