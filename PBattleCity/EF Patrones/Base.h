#pragma once
#include "IBase.h"
class Base :
    public IBase
{
public:
    Base();
    void renderizar(SistemaRenderizacion* _sistemaRenderizacion);
};

