#pragma once
#include "Entidade.h"
class Inimigo :
	public Entidade
{
public:
	Inimigo();
	~Inimigo();
protected:
	int cont;
public:

	virtual void mover(float boneco_x, float boneco_y) = 0;
	void set_x(float recebido) { x = recebido; }
	void set_y(float recebido) { y = recebido; }
	const int get_cont() const { return cont; }
	void set_cont(int recebido) { cont = recebido; }
	void aumenta_cont(int recebido) { cont += recebido; }
};


