#pragma once
#include "Obstaculo.h"
class Pantano :
    public Obstaculo
{
public:
    Pantano();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
    void setImagen(unsigned char _simbolo, ColorConsola _colorSimbolo, ColorConsola _colorFondo);
};

