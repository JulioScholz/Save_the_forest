#include "Fase1.h"



Fase1::Fase1()
{
}


Fase1::~Fase1()
{
}

int Fase1::iniciar(int indCarregar, bool doisJogadores, Gerenciador_de_Bitmaps * GerenciadorBitmaps)
{

	srand(time(NULL));
	bool ativo = false, sair = false, sairJogo = false, desenha = false;
	int indPause = 0, i = 0;
	int n_bocudos = rand() % 5 + 5;
	//        int num;

	Cam = new Camera;
	Jogador[0] = new Boneco;

	if (doisJogadores) {
		Jogador[1] = new Boneco;
	}
	else {
		Jogador[1] = NULL;
	}

	listaEnt = new ListaEntidades;
	listaEnt->inicializar1();
	listaPlat = new ListaPlataformas;
	listaPlat->inicializar1();

	if (indCarregar == 0)
	{
		Jogador[0]->set_x(125);
		Jogador[0]->set_y(420);
		Jogador[0]->set_vida(50);
		Jogador[0]->set_flipa(false);
		Jogador[0]->set_pulo(true);
		Jogador[0]->set_ataque(false);
		//Jogador[0]->set_direcao(DIREITA);
		if (doisJogadores)
		{
			Jogador[1]->set_x(25);
			Jogador[1]->set_y(420);
			Jogador[1]->set_vida(50);
			Jogador[1]->set_flipa(false);
			Jogador[1]->set_pulo(true);
			Jogador[1]->set_ataque(false);
		//	Jogador[1]->set_direcao(DIREITA);
		}
	}
	else if (indCarregar == 1)
	{
		 carregar();
	}

	al_start_timer(frameTimer);

	while (!sairJogo)
	{
		al_wait_for_event(Fila_eventos, &evento);

		if (evento.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
		{
			sairJogo = true;
		}

		if (evento.timer.source == frameTimer)
		{
			al_get_keyboard_state(&keyState);

			
			Jogador[0]->set_ativo(true);

			if (Jogador[0]->get_vida() > 0) {
				if (al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
				{
					Jogador[0]->set_vel_x(Jogador[0]->get_velocidade());
					Jogador[0]->set_flipa(false);
					Jogador[0]->set_direcao(DIREITA);
				}
				else if (al_key_down(&keyState, ALLEGRO_KEY_LEFT))
				{
					Jogador[0]->set_vel_x(-Jogador[0]->get_velocidade());
					Jogador[0]->set_flipa(true);
					Jogador[0]->set_direcao(ESQUERDA);
				}
				else
				{
					Jogador[0]->set_vel_x(0);
					Jogador[0]->set_ativo(false);
				}
				if (al_key_down(&keyState, ALLEGRO_KEY_UP) && Jogador[0]->get_pulo())
				{
					Jogador[0]->set_vel_y(-Jogador[0]->get_vel_pulo());
					Jogador[0]->set_direcao(CIMA);
				}
				if (!Jogador[0]->get_pulo())
				{
					Jogador[0]->set_vel_y(GRAVIDADE);
					Jogador[0]->set_direcao(BAIXO);
				}
				else
				{
					Jogador[0]->set_vel_y(0);
				}
			}
			else {
				Jogador[0]->set_vel_y(-1);
				Jogador[0]->set_vel_x(0);
			}

			if (al_key_down(&keyState, ALLEGRO_KEY_ENTER)) {
				Jogador[0]->set_ataque(true);
				Jogador[0]->set_ativo(true);
			}
			if (doisJogadores) {
				Jogador[1]->set_ativo(true);
				if (Jogador[1]->get_vida() > 0) {
					if (al_key_down(&keyState, ALLEGRO_KEY_D))
					{
						Jogador[1]->set_vel_x(Jogador[1]->get_velocidade());
						Jogador[1]->set_flipa(false);
						Jogador[1]->set_direcao(DIREITA);
					}
					else if (al_key_down(&keyState, ALLEGRO_KEY_A))
					{
						Jogador[1]->set_vel_x(-Jogador[1]->get_velocidade());
						Jogador[1]->set_flipa(true);
						Jogador[1]->set_direcao(ESQUERDA);
					}
					else
					{
						Jogador[1]->set_vel_x(0);
						Jogador[1]->set_ativo(false);
					}
					if (al_key_down(&keyState, ALLEGRO_KEY_W) && Jogador[1]->get_pulo())
					{
						Jogador[1]->set_vel_y(-Jogador[1]->get_vel_pulo());
						Jogador[1]->set_direcao(CIMA);
					}
					if (!Jogador[1]->get_pulo())
					{
						Jogador[1]->set_vel_y(GRAVIDADE);
						Jogador[1]->set_direcao(BAIXO);
					}
					else
					{
						Jogador[1]->set_vel_y(0);
					}
				}
				else {
					Jogador[1]->set_vel_y(-1);
					Jogador[1]->set_vel_x(0);
				}

				if (al_key_down(&keyState, ALLEGRO_KEY_SPACE)) {
					Jogador[1]->set_ataque(true);
					Jogador[1]->set_ativo(true);
				}
			}
			listaEnt->atualizar(Jogador);
			listaPlat->atualizar(Jogador[0], keyState, 1);
			Jogador[0]->movimenta();
			Jogador[0]->set_pulo();

			if (doisJogadores) {
				// listaEnt->atualizar(Jogador,Cam,contAtaque2);
				listaPlat->atualizar(Jogador[1], keyState, 2);
				Jogador[1]->movimenta();
				Jogador[1]->set_pulo();
			}

			desenha = true;

			if (Jogador[0]->get_vida() > 0) {
				Cam->CameraUpdate(Jogador[0]->get_x(), Jogador[0]->get_y(), 32.0, 32.0, 0);
				al_identity_transform(&camera);
				al_translate_transform(&camera, -(Jogador[0]->get_x() + 16), -(Jogador[0]->get_y() + 16));
				al_translate_transform(&camera, -Cam->get_x() + (Jogador[0]->get_x() + 16), -Cam->get_y() + (Jogador[0]->get_y() + 16));
				//Quando o player andar pra direita por exemplo, tudo sera movido para a esquerda por isso o negativo
				al_use_transform(&camera);
			}
			else if (Jogador[0]->get_vida() < 1 && doisJogadores && Jogador[1]->get_vida() > 0) { // SE O JOGADOR 1 MORRER A CAMERA PASSA A CENTRALIZAR NO JOGADOR 2
				Cam->CameraUpdate(Jogador[1]->get_x(), Jogador[1]->get_y(), 32.0, 32.0, 0);
				al_identity_transform(&camera);
				al_translate_transform(&camera, -(Jogador[1]->get_x() + 16), -(Jogador[1]->get_y() + 16));
				al_translate_transform(&camera, -Cam->get_x() + (Jogador[1]->get_x() + 16), -Cam->get_y() + (Jogador[1]->get_y() + 16));
				al_use_transform(&camera);
			}

		}

		if (desenha)
		{
			GerenciadorBitmaps->desenha(23, 0, 6200, 400, false);
			listaEnt->desenhar(GerenciadorBitmaps, Cam);
			listaPlat->desenhar(GerenciadorBitmaps);

			Jogador[0]->desenha(GerenciadorBitmaps, false);
			if (doisJogadores) {
				Jogador[1]->desenha(GerenciadorBitmaps, true);
			}

			al_flip_display();
			al_clear_to_color(al_map_rgb(0, 0, 0));
			for (i = 0; i < 7; i++) {
				GerenciadorBitmaps->desenha(18, 0, LARGURA_TELA*i, 0, 0);
			}
			desenha = false;
		}

		if (al_key_down(&keyState, ALLEGRO_KEY_ESCAPE))
		{
			al_stop_timer(frameTimer);
			Cam->CameraUpdate(0, 0, 32, 32, 0);
			al_identity_transform(&camera);
			al_translate_transform(&camera, 0, 0);
			al_use_transform(&camera);
			indPause = pausar(Cam->get_x(), GerenciadorBitmaps);
			al_rest(0.1);

			if (indPause == 0)
			{
				salvar();
				al_start_timer(frameTimer);
			}
			else if (indPause == 2)
			{
				sairJogo = true;
				pause = false;
			}
			else if (indPause == 1)
			{
				pause = false;
				al_start_timer(frameTimer);
			}

		}
		if (Jogador[0]->get_vida() < 1 || (doisJogadores) && Jogador[0]->get_vida() < 1 && Jogador[1]->get_vida() < 1)
		{
			al_stop_timer(frameTimer);
			morto = true;
			indMorto = 0;
			while (morto)
			{
				al_get_keyboard_state(&keyState);
				for (i = 0; i < 7; i++) {
					GerenciadorBitmaps->desenha(18, 0, LARGURA_TELA*i, 0, 0);
				}
				GerenciadorBitmaps->desenha(24, 0, Cam->get_x(), 0, false);
				if (al_key_down(&keyState, ALLEGRO_KEY_UP) || al_key_down(&keyState, ALLEGRO_KEY_LEFT))
					indMorto = 1;
				if (al_key_down(&keyState, ALLEGRO_KEY_DOWN) || al_key_down(&keyState, ALLEGRO_KEY_RIGHT))
					indMorto = 0;

				indBoc++;
				if (indBoc > 1)
					indBoc = 0;
				if (indMorto == 1)
				{
					GerenciadorBitmaps->desenha(1, indBoc, Cam->get_x() + 330, 300, true);
					GerenciadorBitmaps->desenha(1, indBoc, Cam->get_x() + 565, 300, false);
				}
				else if (indMorto == 0)
				{
					GerenciadorBitmaps->desenha(1, indBoc, Cam->get_x() + 330, 365, true);
					GerenciadorBitmaps->desenha(1, indBoc, Cam->get_x() + 565, 365, false);
				}

				if (al_key_down(&keyState, ALLEGRO_KEY_ENTER) || al_key_down(&keyState, ALLEGRO_KEY_SPACE))
					morto = false;
				al_flip_display();
				al_clear_to_color(al_map_rgb(0, 0, 0));
			}
			if (indMorto == 1)
			{
				Jogador[0]->set_x(125);
				Jogador[0]->set_y(420);
				Jogador[0]->set_vida(50);
				Jogador[0]->set_flipa(false);
				Jogador[0]->set_pulo(true);
				Jogador[0]->set_ataque(false);
				Jogador[0]->set_direcao(DIREITA);
				if (doisJogadores)
				{
					Jogador[1]->set_x(25);
					Jogador[1]->set_y(420);
					Jogador[1]->set_vida(50);
					Jogador[1]->set_flipa(false);
					Jogador[1]->set_pulo(true);
					Jogador[1]->set_ataque(false);
					Jogador[1]->set_direcao(DIREITA);
				}
			}
			else {
				sairJogo = true;
			}
			al_start_timer(frameTimer);
		}

		if (Jogador[0]->get_x() > 923 * 7 || (doisJogadores && Jogador[1]->get_x() > 923 * 7))
		{
			al_stop_timer(frameTimer);
			Cam->CameraUpdate(0, 0, 32, 32, 0);
			al_identity_transform(&camera);
			al_translate_transform(&camera, 0, 0);
			al_use_transform(&camera);
			return al_get_timer_count(frameTimer) / 30;
		}
	}
	sairJogo = false;
	Cam->CameraUpdate(0, 0, 32, 32, 0);
	return 0;
}

void Fase1::salvar()
{
	int ind = 0, num;
	bool aux;

	ofstream arquivoSlv;
	arquivoSlv.open("saveJogo1.txt");

	cout << "salvar fase 1";
	for (ind = 0; ind < 6; ind++)
	{
		if (ind == 0)
			num = Jogador[0]->get_x();

		else if (ind == 1)
			num = Jogador[0]->get_y();

		else if (ind == 2)
			num = Jogador[0]->get_vida();

		else if (ind == 3)
			aux = Jogador[0]->get_flipa();
		else if (ind == 4)
			aux = Jogador[0]->get_pulo();
		else if (ind == 5)
			aux = Jogador[0]->get_ataque();

		if (ind >= 0 && ind < 3)

			arquivoSlv << num << endl;
		if (ind >= 3)
		{
			if (aux == true)
				arquivoSlv << aux << endl;
			else
				arquivoSlv << aux << endl;
		}

	}

	arquivoSlv.close();
}

void Fase1::carregar()
{
	int ind = 0, num;

	ifstream arquivoSlv;
	arquivoSlv.open("saveJogo1.txt");


	cout << "carregar fase1";
	while (arquivoSlv >> linha)
	{
		if (ind >= 0 && ind < 3)
			num = atoi(linha);
		if (ind == 0)
			Jogador[0]->set_x(num);

		else if (ind == 1)
			Jogador[0]->set_y(num);

		else if (ind == 2)
			Jogador[0]->set_vida(num);

		else if (ind == 3)
			Jogador[0]->set_flipa(linha);
		else if (ind == 4)
			Jogador[0]->set_pulo(linha);
		else if (ind == 5)
			Jogador[0]->set_ataque(linha);
		ind++;
	}

	arquivoSlv.close();
	listaEnt->verificaProx(Jogador[0]->get_x());
}

