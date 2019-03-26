#pragma once
#include "Fase.h"
class Fase1 :
	public Fase
{
public:
	Fase1();
	~Fase1();
	int iniciar(int indCarregar, bool doisJogadores, Gerenciador_de_Bitmaps *GerenciadorBitmaps);

	void salvar();
	void carregar();
};

