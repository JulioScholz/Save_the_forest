#include "Cobreta.h"



Cobreta::Cobreta()
{
}

Cobreta::Cobreta(int lugar) {
	x = (float)lugar;
	altura = 86;
	largura = 100;
	y = CHAO - altura + 10;
	ativo = false;
	flipa = false;
	contador = 0;
}



Cobreta::~Cobreta()
{
}

void Cobreta::ativar(float boneco_x, float boneco_y)
{
	if (x - boneco_x <= 200 && x - boneco_x >= -largura - 40)
	{
		set_ativo(true);// =  true;
	}
	else {
		set_ativo(false);
	}
}

void Cobreta::ativar()
{
	ativo = true;
}

void Cobreta::desenha(Gerenciador_de_Bitmaps * gerenciadorBitmaps)
{
	al_draw_bitmap(gerenciadorBitmaps->get_imagem(5, get_contador()), get_x(), get_y(), get_flipa());
}
