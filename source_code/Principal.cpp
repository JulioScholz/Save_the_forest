#include "Principal.h"



Principal::Principal()
{

	al_init();
	al_install_keyboard();

	tela = al_create_display(LARGURA_TELA, ALTURA_TELA);

	al_init_image_addon();
	al_set_window_title(tela, "SAVE THE FOREST");
	al_set_new_display_flags(ALLEGRO_WINDOWED);
	al_set_window_position(tela, 0, 0);
	al_init_image_addon();
	al_init_primitives_addon();
	al_init_ttf_addon();
	Fila_eventos = al_create_event_queue();

	al_register_event_source(Fila_eventos, al_get_keyboard_event_source());

	al_register_event_source(Fila_eventos, al_get_display_event_source(tela));

	al_init_font_addon();

	fonte = al_load_font("Image/ASMAN.TTF", 48, 0);

	indMenuPrincipal = 0;
	indMenuEscNumJogador = 0;
	indMenuEscFase = 0;
	indMenuEsc = 0;
	cont = 0;
	indPause = 0;
	pause = false;
	ind = 0;
	indicador = true;

	GerenciadorBitmaps = new Gerenciador_de_Bitmaps;
}


Principal::~Principal()
{
	al_destroy_display(tela);
	al_destroy_event_queue(Fila_eventos);
	delete GerenciadorBitmaps;
	GerenciadorBitmaps = NULL;

}

void Principal::executa()
{

	primFase = new Fase1;
	segFase = new Fase2;

	srand(time(NULL));

	bool ativo = false, sair = false, sairJogo = false, desenha = false;
	int indPause = 0, i = 0, cont = 0, contbocudo1 = 0, playerrefresh = 0, contAtaque = 0, contAbelhudo = 0, contCobreta = 0;

	while (!sair)
	{


		menuPrincipal(0);
		al_rest(0.1);

		if (indMenuPrincipal == 0) //**JOGAR**//
		{

			menuEscNumJog(0);
			al_rest(0.1);
			menuEscFase(0);
			al_rest(0.1);
			menuEscCarregar();

			if (indMenuEscNumJogador == 0 && indMenuEscFase == 0) //1 JOGADOR NA FASE 1
			{
				pause = false; // AQUI
				pontF1 = primFase->iniciar(indMenuEsc, false, GerenciadorBitmaps);
				ind = 0;
				while (indicador)
				{

					GerenciadorBitmaps->desenha(0, 3, 0, 0, false);

					cont++;
					if (cont > 1)
						cont = 0;
					if (ind == 0)
					{
						GerenciadorBitmaps->desenha(1, cont, 150, 390, true);
						GerenciadorBitmaps->desenha(1, cont, 320, 390, false);

					}
					else if (ind == 1)
					{
						GerenciadorBitmaps->desenha(1, cont, 560, 390, false);
						GerenciadorBitmaps->desenha(1, cont, 740, 390, true);

					}
					al_rest(0.1);
					al_get_keyboard_state(&keyState);
					if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
						ind = 0;
					else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
						ind = 1;

					if (al_key_down(&keyState, ALLEGRO_KEY_SPACE) || al_key_down(&keyState, ALLEGRO_KEY_ENTER))
					{
						al_rest(0.1);
						indicador = false;
					}
					al_flip_display();
					al_clear_to_color(al_map_rgb(0, 0, 0));
				}

				if (ind == 0)
				{
					indMenuEscFase = 1;
					indMenuEsc = 5;
				}
				if (ind == 1)
				{
					indMenuEsc = 5;
					indMenuEscNumJogador = 5;
					indMenuPrincipal = 5;
				}
				indicador = true;
			}


			if (indMenuEscNumJogador == 0 && indMenuEscFase == 1)//1 JOGADOR NA FASE 2
			{
				pause = false;
				pontF1 += segFase->iniciar(indMenuEsc, false, GerenciadorBitmaps);
				indMenuEsc = 5;
				indMenuEscNumJogador = 5;
				indMenuPrincipal = 5;
			}

			if (indMenuEscNumJogador == 1 && indMenuEscFase == 0) //2 JOGADOR NA FASE 1
			{
				pause = false; // AQUI
				pontF1 = primFase->iniciar(indMenuEsc, true, GerenciadorBitmaps);
				ind = 0;
				while (indicador)
				{
					GerenciadorBitmaps->desenha(0, 2, 0, 0, false);

					cont++;
					if (cont > 1)
						cont = 0;
					if (ind == 0)
						if (ind == 0)
						{
							GerenciadorBitmaps->desenha(1, cont, 150, 390, true);
							GerenciadorBitmaps->desenha(1, cont, 320, 390, false);

						}
						else if (ind == 1)
						{
							GerenciadorBitmaps->desenha(1, cont, 560, 390, false);
							GerenciadorBitmaps->desenha(1, cont, 740, 390, true);

						}
					al_rest(0.1);
					al_get_keyboard_state(&keyState);
					if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
						ind = 0;
					else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
						ind = 1;

					if (al_key_down(&keyState, ALLEGRO_KEY_SPACE) || al_key_down(&keyState, ALLEGRO_KEY_ENTER))
					{
						al_rest(0.1);
						indicador = false;
					}
					al_flip_display();
					al_clear_to_color(al_map_rgb(0, 0, 0));
				}

				if (ind == 0)
				{
					indMenuEscFase = 1;
					indMenuEsc = 5;
				}
				if (ind == 1)
				{
					indMenuEsc = 5;
					indMenuEscNumJogador = 5;
					indMenuPrincipal = 5;
				}
				indicador = true;
			}


			if (indMenuEscNumJogador == 1 && indMenuEscFase == 1)//2 JOGADOR NA FASE 2
			{
				pontF1 += segFase->iniciar(indMenuEsc, true, GerenciadorBitmaps);

				while (indicador)
				{
					GerenciadorBitmaps->desenha(0, 4, 0, 0, false);

					al_rest(0.1);
					al_get_keyboard_state(&keyState);
					if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
					{
						al_rest(0.1);
						indicador = false;
					}

					if (al_key_down(&keyState, ALLEGRO_KEY_SPACE) || al_key_down(&keyState, ALLEGRO_KEY_ENTER))
					{
						cadastrar(pontF1);
					}
					al_flip_display();
					al_clear_to_color(al_map_rgb(0, 0, 0));
				}
				indMenuEsc = 5;
				indMenuEscNumJogador = 5;
				indMenuPrincipal = 5;
			}
		
			
		}



		else if (indMenuPrincipal == 1) //**PLACAR**//
		{
			placar();
		}
		else if (indMenuPrincipal == 2) //**SAIR**//
		{
			sairJogo = true;
			sair = true;
		}

		/*if(evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			sair = true;
		}*/
	}
}

void Principal::menuEscCarregar()
{

	menuEscCarreg = false;
	while (!menuEscCarreg)
	{
		al_rest(0.1);
		al_get_keyboard_state(&keyState);
		GerenciadorBitmaps->desenha(0, 5, 0, 0, 0);
		cont++;
		if (cont > 1)
			cont = 0;
		if (indMenuEsc == 0)
		{

			GerenciadorBitmaps->desenha(1, cont, 130, 390, true);
			GerenciadorBitmaps->desenha(1, cont, 340, 390, false);
		}
		else if (indMenuEsc == 1)
		{
			GerenciadorBitmaps->desenha(1, cont, 560, 390, true);
			GerenciadorBitmaps->desenha(1, cont, 730, 390, false);

		}

		if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
			indMenuEsc = 1;

		else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
			indMenuEsc = 0;

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));

		if (al_key_down(&keyState, ALLEGRO_KEY_SPACE) || al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			menuEscCarreg = true;
	}
}

void Principal::menuPrincipal(float xDaCam)
{

	menuPrinc = false;

	while (!menuPrinc)
	{
		al_rest(0.1);
		al_get_keyboard_state(&keyState);

		if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
			indMenuPrincipal++;

		else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
			indMenuPrincipal--;

		if (indMenuPrincipal < 0)
			indMenuPrincipal = 0;
		else if (indMenuPrincipal > 2)
			indMenuPrincipal = 2;

		GerenciadorBitmaps->desenha(0, 0, xDaCam, 0, 0);
		cont++;
		if (cont > 1)
			cont = 0;
		if (indMenuPrincipal == 0)
		{

			GerenciadorBitmaps->desenha(1, cont, 85 + (xDaCam), 340, true);
			GerenciadorBitmaps->desenha(1, cont, 225 + (xDaCam), 340, false);

		}
		else if (indMenuPrincipal == 1)
		{
			GerenciadorBitmaps->desenha(1, cont, 375 + (xDaCam), 340, true);
			GerenciadorBitmaps->desenha(1, cont, 520 + (xDaCam), 340, false);

		}
		else if (indMenuPrincipal == 2)
		{
			GerenciadorBitmaps->desenha(1, cont, 665 + (xDaCam), 340, true);
			GerenciadorBitmaps->desenha(1, cont, 810 + (xDaCam), 340, false);
		}

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));

		if (al_key_down(&keyState, ALLEGRO_KEY_SPACE) || al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			menuPrinc = true;
	}
}

void Principal::menuEscNumJog(float xDaCam)
{

	menuEscNumJ = false;
	while (!menuEscNumJ)
	{
		al_rest(0.1);
		al_get_keyboard_state(&keyState);
		if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
			indMenuEscNumJogador--;
		else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
			indMenuEscNumJogador++;

		if (indMenuEscNumJogador < 0)
			indMenuEscNumJogador = 0;
		else if (indMenuEscNumJogador > 1)
			indMenuEscNumJogador = 1;
		cont++;
		if (cont > 1)
			cont = 0;


		GerenciadorBitmaps->desenha(0, 1, xDaCam, 0, 0);
		if (indMenuEscNumJogador == 0)
		{
			GerenciadorBitmaps->desenha(1, cont, 150 + (xDaCam), 390, true);
			GerenciadorBitmaps->desenha(1, cont, 320 + (xDaCam), 390, false);
		}
		else if (indMenuEscNumJogador == 1)
		{

			GerenciadorBitmaps->desenha(1, cont, 560 + (xDaCam), 390, true);
			GerenciadorBitmaps->desenha(1, cont, 740 + (xDaCam), 390, false);
		}

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));

		if (al_key_down(&keyState, ALLEGRO_KEY_SPACE) || al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			menuEscNumJ = true;
	}

}

void Principal::menuEscFase(float xDaCam)
{

	menuEscF = false;
	while (!menuEscF)
	{
		al_rest(0.05);
		al_get_keyboard_state(&keyState);
		if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
			indMenuEscFase--;
		else if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
			indMenuEscFase++;

		if (indMenuEscFase < 0)
			indMenuEscFase = 0;
		else if (indMenuEscFase > 1)
			indMenuEscFase = 1;

		cont++;
		if (cont > 1)
			cont = 0;

		GerenciadorBitmaps->desenha(0, 2, xDaCam, 0, 0);
		if (indMenuEscFase == 0)
		{
			//falta ajustes
			GerenciadorBitmaps->desenha(1, cont, 150 + (xDaCam), 390, true);
			GerenciadorBitmaps->desenha(1, cont, 325 + (xDaCam), 390, false);
		}
		else if (indMenuEscFase == 1)
		{
			GerenciadorBitmaps->desenha(1, cont, 565 + (xDaCam), 390, true);
			GerenciadorBitmaps->desenha(1, cont, 740 + (xDaCam), 390, false);
		}
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));

		if (al_key_down(&keyState, ALLEGRO_KEY_SPACE) || al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			menuEscF = true;
	}
}

void Principal::placar()
{
	string linha;
	string arq[20];
	string aux;
	bool indicadorPlacar = true;
	int x = 0, i, k = 0, j=0;
	ifstream arqPlacar;
	arqPlacar.open("placar.txt");


	if (arqPlacar.is_open())
	{
		while (arqPlacar >> linha)
		{
			arq[x] = linha;
			x++;
		}
	}
	arqPlacar.close();
	for (i = 0; i < x; i++)
	{
		for (k = i; k < x; k++)
		{
			if (arq[i] > arq[k])
			{
				aux = arq[i];
				arq[i] = arq[k];
				arq[k] = aux;
			}

		}
	}

	while (indicadorPlacar)
	{
		//nao esta imprimindo na tela por algum motivo =/
		al_rest(0.1);
		GerenciadorBitmaps->desenha(25,0,0,0, false);
		
		for (i = 0; i < x; i++)
		{
			//al_draw_textf(fonte, al_map_rgb(0, 0, 0), 300 + (50*i), ALTURA_TELA / 2, ALLEGRO_ALIGN_CENTRE, arq[i]);
		}
		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}
	
}

void  Principal::cadastrar(float pontuacao)
{
	char linha[20];
	//char letra;
	int x = 0;
	indicador = true;


	while (indicador)
	{
		ALLEGRO_EVENT evento;
		GerenciadorBitmaps->desenha(0, 4, 0, 0,false);
		al_rest(0.1);
		al_get_keyboard_state(&keyState);

		al_wait_for_event(Fila_eventos, &evento);

		if(ALLEGRO_EVENT_KEY_CHAR)
		{ 
			linha[x] = evento.keyboard.unichar;
			x++;
		}

		if (x > 0)
			cout << linha << endl;

		//nao esta funcionando

		if (al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			indicador = false;

		al_flip_display();
		al_clear_to_color(al_map_rgb(0, 0, 0));
	}

	ofstream myfile;
	myfile.open("placar.txt.", ios::ate);
	myfile << "%s,%f/n", linha, pontuacao;
	//fprintf(placar, "%s,%f\n", linha, pontuacao);
	myfile.close();
}






