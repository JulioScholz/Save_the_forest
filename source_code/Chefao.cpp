#include "Chefao.h"



Chefao::Chefao()
{
	ativo = false;
	altura = 0;
	largura = 0;
	x = 7200;
	y = CHAO - 350;
	contMov = 0;
	contAtaque = 0;
	contParado = 0;
	ataque = 0;
	velocidade = 3;
	refresh = 0;
	vida = 500;
}


Chefao::~Chefao()
{

}

void Chefao::mover(float boneco_x, float boneco_y)
{
	if (boneco_x - x > 355 && boneco_x - x < 510) {
		ataque = 1;
		flipa = false;
	}
	else if (boneco_x - x > 75 && boneco_x - x < 300) {
		ataque = 1;
		flipa = true;
	}
	else if (boneco_x > x + 400) {
		x += velocidade;
		flipa = false;
		if (get_refresh() >= 5) {
			aumenta_contMov(1);
			set_refresh(0);
		}
		if (get_contMov() > 6) {
			set_contMov(0);
		}
	}
	else if (boneco_x < x + 400) {
		x -= velocidade;
		flipa = true;
		if (get_refresh() >= 5) {
			aumenta_contMov(1);
			set_refresh(0);
		}
		if (get_contMov() > 6) {
			set_contMov(0);
		}
	}
}

void Chefao::atacar()
{
	if (ataque == 1) {
		if (get_refresh() >= 4) {
			aumenta_contAtaque(1);
			set_refresh(0);
			if (get_contAtaque() > 7) {
				set_contAtaque(0);
				set_ataque(0);
			}
		}
		aumenta_refresh(+1);
	}
}

void Chefao::desenha(Gerenciador_de_Bitmaps * gerenciadorBitmaps)
{
	if (get_vida() > 0) {
		if (!get_ativo()) {
			aumenta_contParado(1);
			if (get_contParado() > 6) {
				set_contParado(0);
			}
			al_draw_bitmap(gerenciadorBitmaps->get_imagem(14, get_contParado()), get_x(), get_y(), 0);
		}


		else {

			if (get_ataque() == 0) { // ELE SOMENTE SE MOVIMENTA SE O ATAQUE DOR IGUAL A ZERO
				al_draw_bitmap(gerenciadorBitmaps->get_imagem(15, get_contMov()), get_x(), get_y(), get_flipa());
				aumenta_refresh(+1);
			}
			else if (get_ataque() == 1)
			{
				atacar();
				al_draw_bitmap(gerenciadorBitmaps->get_imagem(16, get_contAtaque()), get_x(), get_y() - 200, get_flipa());

			}
		}
	}
}

