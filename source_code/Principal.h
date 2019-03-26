#pragma once
#include "Cabeçalho.h"
#include"Fase1.h"
#include"Fase2.h"
class Principal
{
private:
private:
	int indMenuPrincipal;
	int indMenuEscNumJogador;
	int indMenuEscFase;
	int ind;
	int cont;
	int indPause;
	int pontF1;
	int indMenuEsc;
	bool menuPrinc;
	bool menuEscNumJ;
	bool menuEscF;
	bool pause;
	bool indicador;
	bool menuEscCarreg;

	Fase1 *primFase;
	Fase2 *segFase;

	ALLEGRO_DISPLAY *tela;
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_EVENT_QUEUE *Fila_eventos = NULL;
	ALLEGRO_FONT *fonte = NULL;


	Gerenciador_de_Bitmaps *GerenciadorBitmaps;
public:
	Principal();
	~Principal();
	void executa();
	void menuEscCarregar();
	void menuPrincipal(float xDaCam);
	void menuEscNumJog(float xDaCam);
	void menuEscFase(float xDaCam);
	void placar();
	void cadastrar(float pontuacao);

};

