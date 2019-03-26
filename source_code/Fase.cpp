#include "Fase.h"



Fase::Fase()
{
	cont = 0;
	indPause = 0;
	pause = false;

	frameTimer = al_create_timer(1.0 / frameFPS);
	timerMenu = al_create_timer(1.0 / FPSmenu);
	Fila_eventos = al_create_event_queue();
	al_register_event_source(Fila_eventos, al_get_timer_event_source(frameTimer));
	al_register_event_source(Fila_eventos, al_get_timer_event_source(timerMenu));

	al_start_timer(timerMenu);
}


Fase::~Fase()
{
	al_destroy_timer(frameTimer);
	al_destroy_timer(timerMenu);
	al_destroy_event_queue(Fila_eventos);
}

int Fase::pausar(float xDaCam, Gerenciador_de_Bitmaps * GerenciadorBitmaps)
{
	{
		int i;
		pause = true;
		while (pause)
		{
			al_rest(0.1);
			for (i = 0; i < 7; i++)
				GerenciadorBitmaps->desenha(18, 0, LARGURA_TELA*i, 0, 0);
			GerenciadorBitmaps->desenha(2, 0, xDaCam, 0, 0);

			al_get_keyboard_state(&keyState);
			if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT) || al_key_down(&keyState, ALLEGRO_KEY_DOWN))
				indPause++;
			else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT) || al_key_down(&keyState, ALLEGRO_KEY_UP))
				indPause--;

			if (indPause < 0)
				indPause = 0;
			else if (indPause > 2)
				indPause = 2;

			cont++;
			if (cont > 1)
				cont = 0;

			if (indPause == 0)
			{
				GerenciadorBitmaps->desenha(1, cont, 365 + (xDaCam), 270, true);
				GerenciadorBitmaps->desenha(1, cont, 530 + (xDaCam), 270, true);
			}
			else if (indPause == 1)
			{
				GerenciadorBitmaps->desenha(1, cont, 330 + (xDaCam), 325, true);
				GerenciadorBitmaps->desenha(1, cont, 565 + (xDaCam), 325, true);

			}
			else if (indPause == 2)
			{
				GerenciadorBitmaps->desenha(1, cont, 375 + (xDaCam), 380, true);
				GerenciadorBitmaps->desenha(1, cont, 515 + (xDaCam), 380, true);
			}

			if (al_key_down(&keyState, ALLEGRO_KEY_SPACE) || al_key_down(&keyState, ALLEGRO_KEY_ENTER))
			{
				pause = false;
				return indPause;
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
		}
		return 0;
	}
	return 0;
}


