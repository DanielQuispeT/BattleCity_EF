#pragma once
#include "..\Obstaculo.h"
class BonusEnergia :
    public Obstaculo
{
public:
    BonusEnergia();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
};

