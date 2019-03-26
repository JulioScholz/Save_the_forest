#include "Bocudo.h"



Bocudo::Bocudo()
{
}

Bocudo::Bocudo(int lugar)
{
	vida = 10;
	x = (float)lugar;
	y = CHAO - 80;
	velocidade = rand() % 2 + 2;
	flipa = false;
	cont = 0;
}


Bocudo::~Bocudo()
{
}

void Bocudo::mover(float boneco_x, float boneco_y)
{
	if (boneco_y < y - 200 || (boneco_x - x < -800 || boneco_x - x > 800)) {
		//fica parado
	}
	else {
		if (boneco_x > x) {
			x += velocidade;
			flipa = true;
		}
		else if (boneco_x <= x - 20) { // O MENOS 20 É PARA ELE FICAR PARADO
			x -= velocidade;
			flipa = false;
		}
	}
}

void Bocudo::desenha(Gerenciador_de_Bitmaps * gerenciadorBitmaps)
{
	if (get_cont() > 1)
		set_cont(0);
	al_draw_bitmap(gerenciadorBitmaps->get_imagem(3, get_cont()), get_x(), get_y(), get_flipa());
	aumenta_cont(1);
}
