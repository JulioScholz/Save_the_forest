#pragma once
#include "Fase.h"
class Fase2 :
	public Fase
{
private:
private:
	Chefao *Chefe;
public:
	Fase2();
	~Fase2();
	int iniciar(int indCarregar, bool doisJogadores, Gerenciador_de_Bitmaps *GerenciadorBitmaps);
	void Gerencia_chefao(Boneco* Jogador[], Camera *Cam, int doisJogadores, Gerenciador_de_Bitmaps *GerenciadorBitmaps);

	void salvar();
	void carregar();
};

