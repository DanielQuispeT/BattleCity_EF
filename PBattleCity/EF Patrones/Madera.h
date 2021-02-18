#pragma once
#include "..\Obstaculo.h"
class Madera :
    public Obstaculo
{
public:
    Madera();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
};

