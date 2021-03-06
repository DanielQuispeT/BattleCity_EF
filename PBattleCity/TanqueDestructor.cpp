#include "TanqueDestructor.h"
#include "TanqueJugador.h"
#include "Utilitarios.h"
#include "Bala.h"
#include "TanqueJugador.h"

TanqueDestructor::TanqueDestructor()
{
	setTipoActor(TipoActor_TanqueDestructor);
	analizarTiempo = tiempoAnalisisIAEnemiga;
	analizarTemporizador = getRandomFloat(0.0, analizarTiempo);
	ultimoAnalisisX = 0.0;
	ultimoAnalisisY = 0.0;

	setEnergia(energiaEnemigo);
	velocidad = velocidadEnemigo;

	//tanqueJugador = _tanqueJugador;

}

TanqueDestructor::~TanqueDestructor()
{

}

void TanqueDestructor::analizar(Actor* _tanqueJugador)
{
	float x = 0.0;
	float y = 0.0;
	calcularPosicionCeldaFrontal(&x, &y);

	float xDelta = 0.0;
	float yDelta = 0.0;

	switch (getDireccion()) {
	case Direccion_Izquierda: xDelta = -1.0; break;
	case Direccion_Derecha: xDelta = 1.0; break;
	case Direccion_Arriba: yDelta = -1.0; break;
	case Direccion_Abajo: yDelta = 1.0; break;
	}

	//Encontrar actores cercanos y distancia
	Actor* actor = 0;
	int distancia = 0;

	do {
		actor = getGameManager()->detectarColisiones(x, y, 1, 1, NULL);

		x += xDelta;
		y += yDelta;
		++distancia;
	} while (actor == 0);

	//Codigo para defenderse disparando
	if (actor->getTipoActor() == TipoActor_Bala) {
		if (((Bala*)actor)->getTipoActorPropietario() == TipoActor_TanqueJugador) {
			disparar();
		}
		return;
	}

	//Atacar disparando
	if (actor->getTipoActor() == TipoActor_TanqueJugador || actor->getTipoActor() == TipoActor_Base) {
		disparar();
		return;
	}

	//Cambio de direccion aleatorio
	if (0 == rand() % 5) {
		//Cambia la direccion aleatoriamente
		moverDireccionRandom();
		return;
	}

	switch (actor->getTipoActor()) {
	case TipoActor_Obstaculo:
		if (actor->getInvulnerable() == false)
		{
			disparar();
			return;
		}
		break;
	}

	//Cambio de direccion
	if (distancia == 1 || ((int)ultimoAnalisisX == (int)getX() && (int)ultimoAnalisisY == (int)getY())) {
		//Se mueve en una direccion aleatoria
		//moverDireccionRandom();
		moverDireccionIA(_tanqueJugador);
		return;
	}

	ultimoAnalisisX = getX();
	ultimoAnalisisY = getY();

}


void TanqueDestructor::moverDireccionRandom()
{
	Direccion direccionAnterior = getDireccion();
	Direccion direccionNueva;

	do {
		direccionNueva = (Direccion)(rand() % ((int)Direccion_MAX));

	} while (direccionAnterior == direccionNueva);

	mover(direccionNueva);
}


void TanqueDestructor::moverDireccionIA(Actor* _tanqueJugador) {
	Direccion direccionAnterior = getDireccion();
	Direccion direccionNueva;

	do {
		if (rand() % 2 == 0) {

			if (getX() - _tanqueJugador->getX() < 0) {
				direccionNueva = Direccion_Derecha;
			}
			else {
				direccionNueva = Direccion_Izquierda;
			}
		}
		else {

			if (getY() - _tanqueJugador->getY() < 0) {
				direccionNueva = Direccion_Abajo;
			}
			else {
				direccionNueva = Direccion_Arriba;
			}
		}
	} while (direccionAnterior == direccionNueva);

	mover(direccionNueva);
}

void TanqueDestructor::actualizar(float _dt)
{
	Tanque::actualizar(_dt);

	analizarTemporizador += _dt;
	if (analizarTemporizador >= analizarTiempo) {
		analizarTemporizador = 0;
		analizar(getGameManager()->getJugador1());
	}
}
