#include "Carnivora.h"



Carnivora::Carnivora()
{
}

Carnivora::Carnivora(int lugar)
{
	altura = 100;
	largura = 65;
	x = (float)lugar;
	y = CHAO - altura;
	ativo = true;
	contador = 0;
	flipa = false;
}


Carnivora::~Carnivora()
{
}

void Carnivora::ativar(float boneco_x, float boneco_y)
{
	// se o jogador estiver vindo da esquerda do obstaculo
	if (x - boneco_x <= 200 && x - boneco_x >= -largura - 40)
	{
		set_ativo(true);// =  true;

	}
	else {
		set_ativo(false);
	}
	if (x > boneco_x) {
		set_flipa(false);
	}
	else {
		set_flipa(true);
	}
}

void Carnivora::desenha(Gerenciador_de_Bitmaps * gerenciadorBitmaps)
{
	aumenta_contador(1);
	if (get_contador() == 5) {
		set_contador(1);
		al_draw_bitmap(gerenciadorBitmaps->get_imagem(20, get_contador()), get_x(), get_y(), get_flipa());
	}
	else {
		al_draw_bitmap(gerenciadorBitmaps->get_imagem(20, 0), get_x(), get_y(), get_flipa());
	}
}

void Carnivora::ativar()
{
	ativo = true;
}
