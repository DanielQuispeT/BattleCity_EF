#pragma once
#include "Builder.h"
#include "Torre.h"
class Director
{
private:
	Builder* builder;

public:
	void setBuilder(Builder* newBuilder)
	{
		builder = newBuilder;
	};
	Torre* getTorr() 
	{
		Torre* Medieval = new Torre();

		Medieval->_piedra = builder->getPiedra();
		Medieval->_madera = builder->getMadera();
		Medieval->_bonus = builder->getBonus();
		return Medieval;
	};

};

