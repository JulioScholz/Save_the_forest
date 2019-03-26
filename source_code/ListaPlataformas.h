#pragma once
#include "Cabeçalho.h"
#include "Plataforma.h"
#include "Boneco.h"
class ListaPlataformas
{
protected:
	list <Plataforma> ListaPlat;
	list <Plataforma>::iterator it_plat;
public:
	ListaPlataformas();

	~ListaPlataformas();
	void inicializar1();
	void inicializar2();
	bool Gerencia_Colisao(float x1, float y1, float x2, float y2, float larg1, float alt1, float larg2, float alt2);
	void atualizar(Boneco *Jogador, ALLEGRO_KEYBOARD_STATE keyState, int numJogador);
	void desenhar(Gerenciador_de_Bitmaps *GerenciadorBitmaps);
	void limpar();
};

