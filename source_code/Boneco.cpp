#include "Boneco.h"



Boneco::Boneco()
{
	vida = 50;
	x = 100;
	y = 420;
	velocidade = 10;
	flipa = false;
	vel_x = 0;
	vel_y = 0;
	vel_pulo = 17;
	altura = 123;
	largura = 98;
	pulo = true;
	ataque = false;
	//direcao = DIREITA;
	contAtaque = 0;
	cont = 0;
	playerrefresh = 0;
}


Boneco::~Boneco()
{
}


void Boneco::movimenta()
{
	x += vel_x;
	y += vel_y;
	if (y > 560 - 111) {
		y = 560 - 111;
		vel_y = 0;
	}
	if (x < -40)
		x = -40;
	else if (x > 923 * 10 + 200)
		x = 923 * 10 + 200;
}
void Boneco::desenha(Gerenciador_de_Bitmaps *gerenciadorBitmaps, bool doisJogadores) {

	int i = 0;
	if (doisJogadores) {
		i = 3;
	}
	if (get_vida() > 0)
	{
		if (get_ativo())
		{
			if (!get_ataque())// se nao estiver atacando mas estiver ativo(se movimentando)
			{
				al_draw_bitmap(gerenciadorBitmaps->get_imagem(9 + i, get_cont()), get_x(), get_y(), get_flipa());
				if (playerrefresh >= 3)
				{
					playerrefresh = 0;
					aumenta_cont(1);
				}
				playerrefresh++;
				if (get_cont() > 5)
					set_cont(0);
			}
			else // se estiver atacando
			{
				if (get_contAtaque() > 4)
				{
					set_contAtaque(0);
					set_ataque(false);
				}
				if (!get_flipa()) {
					al_draw_bitmap(gerenciadorBitmaps->get_imagem(10 + i, get_contAtaque()), get_x() - 20, get_y() - 25, get_flipa());
				}
				else {
					al_draw_bitmap(gerenciadorBitmaps->get_imagem(10 + i, get_contAtaque()), get_x() - 60, get_y() - 25, get_flipa());
				}
				if (playerrefresh > 2)
				{
					playerrefresh = 0;
					aumenta_contAtaque(1);
				}
				playerrefresh++;
			}
		}
		else // se nao se movimentou nem atacou
		{
			if (get_cont() > 2)
				set_cont(0);
			set_ataque(false);
			set_contAtaque(0);
			al_draw_bitmap(gerenciadorBitmaps->get_imagem(8 + i, get_cont()), get_x(), get_y(), get_flipa());
			if (playerrefresh >= 3)
			{
				playerrefresh = 0;
				aumenta_cont(1);
			}
			playerrefresh++;

		}
	}
	else
	{//SE ESTIVER MORTO
		if (get_cont() > 1)
			set_cont(0);
		gerenciadorBitmaps->desenha(7, get_cont(), get_x(), get_y(), 0);

	}

}