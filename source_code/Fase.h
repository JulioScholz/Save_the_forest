#pragma once
#include "Cabeçalho.h"
#include "Boneco.h"
#include "Chefao.h"
#include "ListaEntidades.h"
#include "ListaPlataformas.h"
class Fase
{
protected:
	ALLEGRO_TRANSFORM camera;
	ALLEGRO_TIMER *frameTimer = NULL;
	ALLEGRO_TIMER *timerMenu = NULL;
	ALLEGRO_KEYBOARD_STATE keyState;

	ALLEGRO_EVENT evento;


	int cont, indPause;
	Boneco *Jogador[2];

	Bocudo *bocudo = NULL;
	Abelhudo *abelhudo = NULL;
	Cobreta *cobreta = NULL;
	Espinho *espinho = NULL;
	Camera *Cam = NULL;
	ALLEGRO_EVENT_QUEUE *Fila_eventos = NULL;

	ListaEntidades *listaEnt;
	ListaPlataformas *listaPlat;

	bool pause;
	bool morto;
	int indMorto;
	int indBoc;
	FILE *save;
	char linha[15];
	int playerrefresh, playerrefresh2;
public:
	Fase();
	~Fase();
	int pausar(float xDaCam, Gerenciador_de_Bitmaps *GerenciadorBitmaps);

	void salvar();

	void carregar();

};

