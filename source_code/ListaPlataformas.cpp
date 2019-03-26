#include "ListaPlataformas.h"



ListaPlataformas::ListaPlataformas()
{
}


ListaPlataformas::~ListaPlataformas()
{
	limpar();
}

void ListaPlataformas::inicializar1()
{
	
		int x, y;
		//int num;

		Plataforma *ptr_plataforma = NULL;

		for (x = 2300; x < 4300; x = x + 400)
		{
			if (x < 2400)
				y = 450;
			else if (x < 4000)
				y = 400;
			else if (x < 4200)
				y = 450;
			ptr_plataforma = new Plataforma(x, y);
			ListaPlat.push_back(*ptr_plataforma);
		}

	
}

void ListaPlataformas::inicializar2()
{

	int x, y;
	//        int num;

	Plataforma *ptr_plataforma = NULL;

	for (x = 2300; x < 5000; x = x + 300)
	{
		if (x < 2400)
			y = 450;
		else if (x < 4600)
			y = 400;
		else
			y = 450;
		ptr_plataforma = new Plataforma(x, y);
		ListaPlat.push_back(*ptr_plataforma);
	}
	for (x = 2450; x < 4000; x = x + 500)
	{
		if (x < 2400)
			y = 300;
		else if (x < 4000)
			y = 300;
		else if (x < 4500)
			y = 350;
		else
			y = 300;
		ptr_plataforma = new Plataforma(x, y);
		ListaPlat.push_back(*ptr_plataforma);
	}
	for (x = 2700; x < 3800; x = x + 600)
	{
		if (x < 3800)
			y = 230;

		ptr_plataforma = new Plataforma(x, y);
		ListaPlat.push_back(*ptr_plataforma);
	}



}

bool ListaPlataformas::Gerencia_Colisao(float x1, float y1, float x2, float y2, float larg1, float alt1, float larg2, float alt2)
{
	if (x1 + larg1 >= x2 && x1 <= x2 + larg2 && y1 + alt1 >= y2 && y1 <= y2 + alt2) {
		// houve colisão
		return true;
	}
	return false;
}

void ListaPlataformas::atualizar(Boneco * Jogador, ALLEGRO_KEYBOARD_STATE keyState, int numJogador)
{

	for (it_plat = ListaPlat.begin(); it_plat != ListaPlat.end(); ++it_plat)
	{
		if (Gerencia_Colisao(Jogador->get_x(), Jogador->get_y(), it_plat->get_x(), it_plat->get_y(), 80, 113, 111, 33))
		{
			Jogador->set_pulo(false);
			if (Jogador->get_y() + 90 < it_plat->get_y())
			{
				Jogador->set_velocidade_y(0);
				Jogador->set_y(it_plat->get_y() - 114);
				Jogador->set_pulo(true);
			}
			else if (Jogador->get_y() > it_plat->get_y() - 1)
			{
				Jogador->set_velocidade_y(+10);

			}
			else if (Jogador->get_x() < it_plat->get_x() && Jogador->get_y() < it_plat->get_y())
			{
				Jogador->set_vel_x(-Jogador->get_vel_x());

			}
			else if (Jogador->get_x() < it_plat->get_x() + 112 && Jogador->get_y() < it_plat->get_y())
			{
				Jogador->set_vel_x(-Jogador->get_vel_x());
			}

			if (numJogador == 1) {
				if (al_key_down(&keyState, ALLEGRO_KEY_UP) && Jogador->get_pulo())
				{
					Jogador->set_vel_y(-Jogador->get_vel_pulo());
					//Jogador->set_direcao(CIMA);
				}
			}
			else   if (numJogador == 2) {
				if (al_key_down(&keyState, ALLEGRO_KEY_W) && Jogador->get_pulo())
				{
					Jogador->set_vel_y(-Jogador->get_vel_pulo());
					//Jogador->set_direcao(CIMA);
				}
			}

		}
	}

}

void ListaPlataformas::desenhar(Gerenciador_de_Bitmaps * GerenciadorBitmaps)
{
		for (it_plat = ListaPlat.begin(); it_plat != ListaPlat.end(); ++it_plat) {
			al_draw_bitmap(GerenciadorBitmaps->get_imagem(22, 0), it_plat->get_x(), it_plat->get_y(), 0);
		}


}

void ListaPlataformas::limpar()
{
	ListaPlat.erase(ListaPlat.begin(), ListaPlat.end());
}
