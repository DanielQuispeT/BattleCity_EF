#pragma once
#include "..\Obstaculo.h"
#include "BonusEnergia.h"
#include "Madera.h"
#include "Piedra.h"
class Torre :
    public Obstaculo
{public:
    Torre();
    BonusEnergia* _bonus;
    Madera* _madera;
    Piedra* _piedra;

    Actor* ArmarTorre();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
};

