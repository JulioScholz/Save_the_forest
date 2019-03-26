#include "Abelhudo.h"



Abelhudo::Abelhudo()
{
}

Abelhudo::Abelhudo(int lugar)
{

	vida = 10;
	x = lugar;
	y = rand() % 300;
	velocidade = rand() % 2 + 2;
	flipa = false;
	cont = 0;
}


Abelhudo::~Abelhudo()
{
}

void Abelhudo::mover(float boneco_x, float boneco_y)
{
	if ((boneco_x - x < -400 || boneco_x - x > 400)) {

	}
	else {
		if (boneco_x > x) {
			x += velocidade;

			flipa = true;
		}
		else if (boneco_x <= x - 20) {
			x -= velocidade;

			flipa = false;
		}
		if (y >= boneco_y) {
			y -= rand() % 4;
		}
		else if (y < boneco_y) {
			y += rand() % 4;
		}
		
	}
}

void Abelhudo::desenha(Gerenciador_de_Bitmaps * gerenciadorBitmaps)
{
	cont++;
	if (cont > 1) {
		cont = 0;
	}
	al_draw_bitmap(gerenciadorBitmaps->get_imagem(4, cont), get_x(), get_y(), get_flipa());
}
