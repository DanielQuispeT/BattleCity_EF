#include "ProteccionDecorador.h"
#include "Base.h"


void ProteccionDecorador::renderizar(SistemaRenderizacion* _sistemaRenderizacion)
{
    {
		Actor* iBase = new ProteccionDecorador(Base());
        iBase->renderizar(_sistemaRenderizacion);
		iBase->setEnergia(energiaBase+3);

		int fila = int(getY());
		int columna = int(getX());
		

		for (int f = 0; f < filasBase+1; f++) {
			for (int c = 0; c < columnasBase+2; c++) {
				DatosSimboloConsola dsc;
				switch (getEnergia()) {
				case 6: dsc = imagenBaseNormalPro[f][c]; break;
				case 4: dsc = imagenBaseDanadaPro[f][c]; break;
				default: dsc = imagenBaseDestruidaPro[f][c]; break;
				}
				_sistemaRenderizacion->dibujarCaracter(fila + f, columna + c, dsc.simbolo, dsc.colorSimbolo, dsc.colorFondo);
			}
		}
    }
}
