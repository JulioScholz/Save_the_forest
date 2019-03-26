#include "Espinho.h"



Espinho::Espinho()
{
}

Espinho::Espinho(int lugar)
{
	altura = 50;
	largura = 173;
	x = (float) lugar;
	y = CHAO - altura;
	ativo = true;
	flipa = false;
}


Espinho::~Espinho()
{
}

void Espinho::desenha(Gerenciador_de_Bitmaps * gerenciadorBitmaps)
{
	al_draw_bitmap(gerenciadorBitmaps->get_imagem(19, 0), get_x(), get_y(), 0);
}

void Espinho::ativar()
{
	ativo = true;
}

