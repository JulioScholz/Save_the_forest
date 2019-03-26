#pragma once
#include "Cabeçalho.h"
#include"Gerenciador_de_Bitmaps.h"
class Entidade
{
public:
	Entidade();
	~Entidade();
protected:
	int vida;
	float x;
	float y;
	float velocidade;
	float largura;
	float altura;
	bool ativo;
	bool flipa;
public:
	const int get_vida()const { return vida; }
	void set_vida(int recebido) { vida += recebido; }
	const float get_x()const { return x; }
	const float get_y()const { return y; }
	const bool get_flipa()const { return flipa; }
	void set_flipa(bool recebido) { flipa = recebido; }
	const bool get_ativo()const { return ativo; }
	void set_ativo(bool recebido) { ativo = recebido; }
	const float get_largura()const { return largura; }
	const float get_altura()const { return altura; }
	const float get_velocidade()const { return velocidade; }
	virtual void desenha() {}
};

