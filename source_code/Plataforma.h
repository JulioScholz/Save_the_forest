#pragma once
#include "Gerenciador_de_Bitmaps.h"
class Plataforma
{
private:
	float x;
	float y;
	float largura;
	float altura;

	
public:
	Plataforma();
	Plataforma(int numx, int numy);
	~Plataforma();
	void set_x(float recebido) { x = recebido; }
	void set_y(float recebido) { y = recebido; }
	const float get_x()const { return x; }
	const float get_y()const { return y; }
	const float get_largura()const { return largura; }
	const float get_altura()const { return altura; }
};

