#pragma once
#include "..\Actor.h"
class IBase : public Actor
{
	virtual void renderizar(SistemaRenderizacion* _sistemaRenderizacion)=0;
};

