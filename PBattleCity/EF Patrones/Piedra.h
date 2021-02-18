#pragma once
#include "..\Obstaculo.h"
class Piedra :
    public Obstaculo
{
public:
    Piedra();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
};

