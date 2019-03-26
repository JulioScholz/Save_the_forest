#pragma once
#include "Cabeçalho.h"
#include "Gerenciador_de_Bitmaps.h"
#include "Entidade.h"
#include "Boneco.h"
#include "Abelhudo.h"
#include "Bocudo.h"
#include "Cobreta.h"
#include "Espinho.h"
#include "Carnivora.h"
#include "Camera.h"
class ListaEntidades
{

public:
	ListaEntidades();
	~ListaEntidades();
protected:
	Boneco *Jogador;
	Boneco *Jogador2;
	list <Bocudo> ListaBocudos;
	list <Abelhudo> ListaAbelhudos;
	list <Cobreta> ListaCobretas;
	list <Espinho> ListaEspinhos;
	list <Carnivora> ListaCarnivoras;

	list <Bocudo>::iterator it_boc;
	list <Bocudo>::iterator it_boc2;
	list <Abelhudo>::iterator it_ab;
	list <Abelhudo>::iterator it_ab2;
	list <Cobreta>::iterator it_cob;
	list <Espinho>::iterator it_esp;
	list <Carnivora>::iterator it_car;
	bool colidiu;
	Bocudo *ptr_bocudo;
	Abelhudo *ptr_abelhudo;
public:
	void inicializar1();
	void inicializar2();
	bool Gerencia_Coslisao(float x1, float y1, float x2, float y2, float larg1, float alt1, float larg2, float alt2);
	void atualizar(Boneco *Jogador[]);
	void desenhar(Gerenciador_de_Bitmaps* gerenciadorBitmaps, Camera *Cam);
	void limpar();
	void verificaProx(int x);
};

