#pragma once
#include "IBase.h"
#include "../GameManager.h"
class BaseDecorador : public IBase
{
private:
	IBase* _iBase;
public:
    BaseDecorador(IBase* iBase)
    {
        _iBase = iBase;
    }

    virtual void renderizar() = 0;
};
