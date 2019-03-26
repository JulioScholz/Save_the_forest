#include "ListaEntidades.h"



ListaEntidades::ListaEntidades()
{
	colidiu = false;
	ptr_abelhudo = NULL;
	ptr_bocudo = NULL;
}


ListaEntidades::~ListaEntidades()
{
	limpar();
}

void ListaEntidades::inicializar1()
{

	int i;
	int num;

	ptr_bocudo = NULL;
	ptr_abelhudo = NULL;
	Cobreta *ptr_cobreta = NULL;
	Espinho *ptr_espinho = NULL;
	Carnivora *ptr_carnivora = NULL;


	for (i = 500; i < 2380; i = i + num)
	{
		ptr_bocudo = new Bocudo(i);
		ListaBocudos.push_back(*ptr_bocudo);
		num = rand() % 500 + 600;
	}

	for (i = num; i < 2390; i = i + num)
	{
		ptr_espinho = new Espinho(i);
		ListaEspinhos.push_back(*ptr_espinho);
		num = rand() % 500 + 600;
	}

	num = rand() % 40 + 50;;
	for (i = 2500; i < 4000; i = i + num)
	{
		ptr_carnivora = new Carnivora(i);
		ListaCarnivoras.push_back(*ptr_carnivora);
	}

	ptr_abelhudo = new Abelhudo(2800);
	ListaAbelhudos.push_back(*ptr_abelhudo);

	ptr_abelhudo = new Abelhudo(3600);
	ListaAbelhudos.push_back(*ptr_abelhudo);


	for (i = 4000; i < 6400; i = i + num)
	{
		ptr_abelhudo = new Abelhudo(i);
		ListaAbelhudos.push_back(*ptr_abelhudo);
		num = rand() % 500 + 500;
	}
	for (i = 4000; i < 6400; i = i + num)
	{
		ptr_bocudo = new Bocudo(i);
		ListaBocudos.push_back(*ptr_bocudo);
		num = rand() % 500 + 600;
	}
	for (i = 4800; i < 6000; i = i + num)
	{
		ptr_espinho = new Espinho(i);
		ListaEspinhos.push_back(*ptr_espinho);
		num = rand() % 500 + 550;
	}


}

void ListaEntidades::inicializar2()
{
	int i;
	int num;

	Bocudo *ptr_bocudo = NULL;
	Abelhudo *ptr_abelhudo = NULL;
	Cobreta *ptr_cobreta = NULL;
	Espinho *ptr_espinho = NULL;
	Carnivora *ptr_carnivora = NULL;


	for (i = 400; i < 2390; i = i + num)
	{
		ptr_cobreta = new Cobreta(i);
		ListaCobretas.push_back(*ptr_cobreta);
		num = rand() % 500 + 600;
	}
	num = rand() % 600 + 700;
	for (i = 400; i < 2400; i = i + num)
	{
		ptr_abelhudo = new Abelhudo(i);
		ListaAbelhudos.push_back(*ptr_abelhudo);
	}

	for (i = 500; i < 2380; i = i + num)
	{
		ptr_bocudo = new Bocudo(i);
		ListaBocudos.push_back(*ptr_bocudo);
		num = rand() % 500 + 400;
	}

	num = rand() % 40 + 50;;
	for (i = 2500; i < 4500; i = i + num)
	{
		ptr_carnivora = new Carnivora(i);
		ListaCarnivoras.push_back(*ptr_carnivora);
	}

	num = rand() % 600 + 500;
	for (i = 2400; i < 5000; i = i + num)
	{
		ptr_abelhudo = new Abelhudo(i);
		ListaAbelhudos.push_back(*ptr_abelhudo);
	}

	for (i = 5000; i < 7000; i = i + num)
	{
		ptr_bocudo = new Bocudo(i);
		ListaBocudos.push_back(*ptr_bocudo);
		num = rand() % 500 + 500;
	}
	for (i = 4500; i < 7000; i = i + num)
	{
		ptr_cobreta = new Cobreta(i);
		ListaCobretas.push_back(*ptr_cobreta);
		num = rand() % 500 + 700;
	}
}

bool ListaEntidades::Gerencia_Coslisao(float x1, float y1, float x2, float y2, float larg1, float alt1, float larg2, float alt2)
{
	if (x1 + larg1 >= x2 && x1 <= x2 + larg2 && y1 + alt1 >= y2 && y1 <= y2 + alt2) {
		// houve colisão
		return true;
	}
	return false;
}

void ListaEntidades::atualizar(Boneco * Jogador[])
{

	//ALLEGRO_KEYBOARD_STATE keyState;
	colidiu = false;
	int i = 0;
	while (i < 2) {
		if (Jogador[0]->get_vida() < 1) {
			i = 1;
		}
		if (Jogador[i]->get_vida() < 1) {
			break;
		}
		for (it_boc = ListaBocudos.begin(); it_boc != ListaBocudos.end(); ++it_boc)
		{
			if (Gerencia_Coslisao(Jogador[i]->get_x(), Jogador[i]->get_y(), it_boc->get_x(), it_boc->get_y(), 80, 113, 50, 17))
			{
				Jogador[i]->set_vida(-1);
				colidiu = true;
				if (Jogador[i]->get_y() > it_boc->get_y()) {
					Jogador[i]->set_vel_y(10);
				}
				else if (Jogador[i]->get_y() < it_boc->get_y()) {
					Jogador[i]->set_y(Jogador[i]->get_y() - 2);
				}
				if (Jogador[i]->get_x() < it_boc->get_x())
				{
					Jogador[i]->set_vel_x(-Jogador[i]->get_velocidade());
				}
				if (Jogador[i]->get_x() > it_boc->get_x())
				{
					Jogador[i]->set_vel_x(Jogador[i]->get_velocidade());
				}
			}
		}

		for (it_ab = ListaAbelhudos.begin(); it_ab != ListaAbelhudos.end(); ++it_ab) {
			if (Gerencia_Coslisao(Jogador[i]->get_x(), Jogador[i]->get_y(), it_ab->get_x(), it_ab->get_y(), 80, 113, 50, 17)) {
				Jogador[i]->set_vida(-1);
				colidiu = true;
				if (Jogador[i]->get_y() > it_ab->get_y()) {
					Jogador[i]->set_vel_y(10);
				}
				else if (Jogador[i]->get_y() < it_ab->get_y()) {
					Jogador[i]->set_vel_y(0);
				}
				if (Jogador[i]->get_x() < it_ab->get_x()) {
					Jogador[i]->set_vel_x(-Jogador[i]->get_velocidade());
				}
				if (Jogador[i]->get_x() > it_ab->get_x()) {
					Jogador[i]->set_vel_x(Jogador[i]->get_velocidade());
				}
			}
		}

		for (it_cob = ListaCobretas.begin(); it_cob != ListaCobretas.end(); ++it_cob) {
			if (it_cob->get_ativo() == true) {
				if (Gerencia_Coslisao(Jogador[i]->get_x(), Jogador[i]->get_y(), it_cob->get_x() + 10, it_cob->get_y(), 80, 113, it_cob->get_largura() - 50, it_cob->get_altura())) {
					Jogador[i]->set_vida(-1);
					colidiu = true;
					if (Jogador[i]->get_y() > it_cob->get_y()) {
						Jogador[i]->set_vel_y(-1);
					}
					else if (Jogador[i]->get_y() < it_cob->get_y()) {
						Jogador[i]->set_vel_y(0);
					}
					if (Jogador[i]->get_x() < it_cob->get_x()) {
						Jogador[i]->set_vel_x(-Jogador[i]->get_velocidade());
					}
					else if (Jogador[i]->get_x() > it_cob->get_x())
					{
						Jogador[i]->set_vel_x(Jogador[i]->get_velocidade());
					}
				}
			}
		}

		for (it_esp = ListaEspinhos.begin(); it_esp != ListaEspinhos.end(); ++it_esp)
		{
			if (Gerencia_Coslisao(Jogador[i]->get_x(), Jogador[i]->get_y(), it_esp->get_x(), it_esp->get_y(), 80, 113, 173, 50))
			{
				Jogador[i]->set_vida(-1);
				colidiu = true;
				if (Jogador[i]->get_y() > it_esp->get_y()) {
					Jogador[i]->set_vel_y(-1);
				}
				else if (Jogador[i]->get_y() < it_esp->get_y()) {
					Jogador[i]->set_vel_y(0);
				}
				if (Jogador[i]->get_x() < it_esp->get_x() + 50) {
					Jogador[i]->set_vel_x(-Jogador[i]->get_velocidade());
				}
				else if (Jogador[i]->get_x() > it_esp->get_x()) {
					Jogador[i]->set_vel_x(Jogador[i]->get_velocidade());
				}
			}
		}
		for (it_car = ListaCarnivoras.begin(); it_car != ListaCarnivoras.end(); ++it_car) {
			if (it_car->get_ativo() == true) {
				if (Gerencia_Coslisao(Jogador[i]->get_x(), Jogador[i]->get_y(), it_car->get_x() + 10, it_car->get_y(), 80, 113, it_car->get_largura() - 50, it_car->get_altura())) {
					Jogador[i]->set_vida(-1);
					colidiu = true;
					if (Jogador[i]->get_y() > it_car->get_y()) {
						Jogador[i]->set_vel_y(-1);
					}
					else if (Jogador[i]->get_y() < it_car->get_y()) {
						Jogador[i]->set_vel_y(0);
					}
					if (Jogador[i]->get_x() < it_car->get_x()) {
						Jogador[i]->set_vel_x(-Jogador[i]->get_velocidade());
					}
					else if (Jogador[i]->get_x() > it_car->get_x())
					{
						Jogador[i]->set_vel_x(Jogador[i]->get_velocidade());
					}
				}
			}
		}

		//============================COLISAO ENTRE OS BOCUDOS =====================================
		for (auto  it : ListaBocudos)
		{
			
			for (auto  it2: ListaBocudos)
			{
				if (Gerencia_Coslisao(it.get_x(), it.get_y(), it2.get_x(), it2.get_y(), 60, 17, 60, 17))
				{
					if (it.get_x() < it2.get_x())
					{
						it2.set_x(it.get_x() + 70);
					}
					if (it.get_x() > it2.get_x())
					{
						it2.set_x(it.get_x() - 20);
					}
				}
			}
		}
		//============================COLISAO ENTRE OS ABELHUDOS =====================================
		for (auto ab : ListaAbelhudos) {
			for (auto ab2 : ListaAbelhudos) {
				if (Gerencia_Coslisao(ab.get_x(), ab.get_y(), ab2.get_x(), ab2.get_y(), 50, 17, 50, 17)) {
					if (ab.get_x() < ab2.get_x()) {
						ab2.set_x(ab.get_x() + 60);
					}
					if (ab.get_x() > ab2.get_x()) {
						ab2.set_x(ab.get_x() - 30);
					}
				}
			}
		}

		//===========================MOVIMENTAÇÂO E ATAQUE===================================


		for (it_boc = ListaBocudos.begin(); it_boc != ListaBocudos.end(); ++it_boc)
		{
			if (Jogador[i]->get_contAtaque() > 1 && (Jogador[i]->get_y() - 40 < it_boc->get_y() && (Jogador[i]->get_y() + Jogador[i]->get_altura()) > it_boc->get_y())) {
				if (Jogador[i]->get_x() - it_boc->get_x() >= -150 && Jogador[i]->get_x() - it_boc->get_x() <= 0 && !Jogador[i]->get_flipa())
				{
					it_boc->set_vida(-1);
					it_boc->set_x(it_boc->get_x() + 30);
				}

				else if (Jogador[i]->get_x() - it_boc->get_x() <= 130 && Jogador[i]->get_x() - it_boc->get_x() >= 0 && Jogador[i]->get_flipa())
				{
					it_boc->set_vida(-1);
					it_boc->set_x(it_boc->get_x() - 40);

				}
			}
		}
		for (it_ab = ListaAbelhudos.begin(); it_ab != ListaAbelhudos.end(); ++it_ab) {
			if (Jogador[i]->get_contAtaque() > 1 && (Jogador[i]->get_y() - 40 < it_ab->get_y() && (Jogador[i]->get_y() + Jogador[i]->get_altura()) > it_ab->get_y())) {
				if (Jogador[i]->get_x() - it_ab->get_x() >= -150 && Jogador[i]->get_x() - it_ab->get_x() <= 0 && !Jogador[i]->get_flipa())
				{
					it_ab->set_vida(-1);
					it_ab->set_x(it_ab->get_x() + 30);
				}

				else if (Jogador[i]->get_x() - it_ab->get_x() <= 130 && Jogador[i]->get_x() - it_ab->get_x() >= 0 && Jogador[i]->get_flipa())
				{
					it_ab->set_vida(-1);
					it_ab->set_x(it_ab->get_x() - 40);

				}
			}
		}

		for (list<Bocudo>::iterator it = ListaBocudos.begin(); it != ListaBocudos.end(); ++it)
		{
			if (Jogador[1] == NULL) {
				it->mover(Jogador[i]->get_x(), Jogador[i]->get_y());
			}
			else if (Jogador[0]->get_vida() > 0 && Jogador[1]->get_vida() > 0) {
				it->mover((Jogador[0]->get_x() + Jogador[1]->get_x()) / 2, (Jogador[0]->get_y() + Jogador[1]->get_y()) / 2);
			}
			else if (Jogador[0]->get_vida() > 0) {
				it->mover(Jogador[0]->get_x(), Jogador[0]->get_y());
			}
			else if (Jogador[1]->get_vida() > 0) {
				it->mover(Jogador[1]->get_x(), Jogador[1]->get_y());
			}
		}

		for (list<Abelhudo>::iterator it_ab = ListaAbelhudos.begin(); it_ab != ListaAbelhudos.end(); ++it_ab) {
			if (Jogador[1] == NULL) {
				it_ab->mover(Jogador[i]->get_x(), Jogador[i]->get_y());
			}
			else if (Jogador[0]->get_vida() > 0 && Jogador[1]->get_vida() > 0) {
				it_ab->mover((Jogador[0]->get_x() + Jogador[1]->get_x()) / 2, (Jogador[0]->get_y() + Jogador[1]->get_y()) / 2);
			}
			else if (Jogador[0]->get_vida() > 0) {
				it_ab->mover(Jogador[0]->get_x(), Jogador[0]->get_y());
			}
			else if (Jogador[1]->get_vida() > 0) {
				it_ab->mover(Jogador[1]->get_x(), Jogador[1]->get_y());
			}
		}

		for (list<Cobreta>::iterator it_cob = ListaCobretas.begin(); it_cob != ListaCobretas.end(); ++it_cob) {
			it_cob->ativar(Jogador[i]->get_x(), Jogador[i]->get_y());
			if (it_cob->get_ativo() == true) {
				it_cob->aumenta_contador(1);
				if (it_cob->get_contador() > 4)
					it_cob->set_contador(4);
			}
			else {
				it_cob->aumenta_contador(-1);
				if (it_cob->get_contador() < 0)
					it_cob->set_contador(0);
			}

		}
		for (it_car = ListaCarnivoras.begin(); it_car != ListaCarnivoras.end(); ++it_car) {
			it_car->ativar(Jogador[i]->get_x(), Jogador[i]->get_y());
			if (it_car->get_ativo() == true) {
				it_car->aumenta_contador(1);
				if (it_car->get_contador() > 5)
					it_car->set_contador(0);
			}
			else {
				it_car->set_contador(0);
			}

		}

		if (Jogador[1] == NULL) {
			i++;
			break;
		}
		else {
			i++;
		}
	}


}

void ListaEntidades::desenhar(Gerenciador_de_Bitmaps * gerenciadorBitmaps, Camera * Cam)
{
	int indMortoBoc=0;
	int indMortoAb = 0;

	if (colidiu == true) {
		al_draw_bitmap(gerenciadorBitmaps->get_imagem(21, 0), Cam->get_x(), 0, 0);
	}

/*
	for (it_boc = ListaBocudos.begin(); it_boc != ListaBocudos.end(); ++it_boc)
	{
		if (it_boc->get_vida() > 0)
		{
			it_boc->desenha(gerenciadorBitmaps);
		}
		else
		{
			it_boc = ListaBocudos.erase(it_boc);
		}
	}
	for (it_ab = ListaAbelhudos.begin(); it_ab != ListaAbelhudos.end(); ++it_ab) {
		if (it_ab->get_vida() > 0) {
			it_ab->desenha(gerenciadorBitmaps);
		}
		else {
			it_ab = ListaAbelhudos.erase(it_ab);
		}
	}
*/


	for (it_boc = ListaBocudos.begin(); it_boc != ListaBocudos.end(); ++it_boc)
	{
		if (it_boc->get_vida() > 0)
		{
			it_boc->desenha(gerenciadorBitmaps);
		}
		else
		{
			it_boc = ListaBocudos.erase(it_boc);
			break;
		}

	}
	for (it_ab = ListaAbelhudos.begin(); it_ab != ListaAbelhudos.end(); ++it_ab) {
		if (it_ab->get_vida() > 0) {
			it_ab->desenha(gerenciadorBitmaps);
		}
		else 
		{
			it_ab = ListaAbelhudos.erase(it_ab);
			break;
		}
	}



	for (list<Cobreta>::iterator it_cob = ListaCobretas.begin(); it_cob != ListaCobretas.end(); ++it_cob) {
		it_cob->desenha(gerenciadorBitmaps);


	}
	for (list<Espinho>::iterator it_esp = ListaEspinhos.begin(); it_esp != ListaEspinhos.end(); ++it_esp) {
		it_esp->desenha(gerenciadorBitmaps);
	}

	for (it_car = ListaCarnivoras.begin(); it_car != ListaCarnivoras.end(); ++it_car) {

		it_car->desenha(gerenciadorBitmaps);
	}



}

void ListaEntidades::limpar()
{
	ListaBocudos.erase(ListaBocudos.begin(), ListaBocudos.end());
	ListaAbelhudos.erase(ListaAbelhudos.begin(), ListaAbelhudos.end());
	ListaCobretas.erase(ListaCobretas.begin(), ListaCobretas.end());
	ListaEspinhos.erase(ListaEspinhos.begin(), ListaEspinhos.end());
	ListaCarnivoras.erase(ListaCarnivoras.begin(), ListaCarnivoras.end());
}

void ListaEntidades::verificaProx(int x)
{
	for (it_boc = ListaBocudos.begin(); it_boc != ListaBocudos.end(); ++it_boc)
	{
		if (it_boc->get_x() > x - 300 && it_boc->get_x() <= x)
		{
			it_boc->set_x(x-300);
		}
		if (it_boc->get_x() < x + 300 && it_boc->get_x() > x)
		{
			it_boc->set_x(x + 300);
		}
	}
	for (it_ab = ListaAbelhudos.begin(); it_ab != ListaAbelhudos.end(); ++it_ab)
	{
		if (it_ab->get_x() > x - 300 && it_ab->get_x() <= x)
		{
			it_ab->set_x(x - 300);
		}
		if (it_ab->get_x() < x + 300 && it_ab->get_x() > x)
		{
			it_ab->set_x(x + 300);
		}
	}
}
