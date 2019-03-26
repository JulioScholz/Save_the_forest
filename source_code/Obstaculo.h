#pragma once
#include "Entidade.h"
class Obstaculo :
	public Entidade
{
public:
	Obstaculo();
	~Obstaculo();
	virtual void ativar() = 0;
};

