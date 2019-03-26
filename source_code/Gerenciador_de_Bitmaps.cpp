#include "Gerenciador_de_Bitmaps.h"



Gerenciador_de_Bitmaps::Gerenciador_de_Bitmaps()
{
	/*01*/ 	const char* const arquivos_menu[6] = { "Image/menu(1).jpg","Image/telaEscolha.png","Image/telaFaseEsc.png","Image/TelaFimFase1.png","Image/Cadastro.png","Image/telaSalve.png" };
	/*02*/  const char* const arquivos_bocMenu[2] = { "Image/bocudomenu(1).png","Image/bocudomenu(2).png" };
	/*03*/  const char* const arquivos_pause = { "Image/pause.png" };

	/*04*/  const char* const arquivos_inimigo1[2] = { "Image/inimigo1_2.png","Image/inimigo1_1.png" };
	/*05*/  const char* const arquivos_abelhudo[2] = { "Image/fly1.png","Image/fly2.png" };
	/*06*/  const char* const arquivos_cobreta[5] = { "Image/cobreta (1).png","Image/cobreta (2).png","Image/cobreta (3).png","Image/cobreta (4).png", "Image/cobreta (5).png" };

	/*07*/  const char* const arquivos_explosao[3] = { "Image/explosion0.png","explosion1.png","explosion2.png" };
	/*08*/  const char* const arquivo_Jogador_1_Parado[3] = { "Image/parado0.png","Image/parado1.png","Image/parado2.png" };
	/*09*/  const char* const arquivos_Jogador_1_Anda[6] = { "Image/Run (1).png","Image/Run (2).png","Image/Run (3).png","Image/Run (4).png","Image/Run (5).png","Image/Run (6).png" };
	/*10*/  const char* const arquivos_Jogador_1_Ataque[5] = { "Image/aataque.png","Image/aataque1.png","Image/aataque2.png","Image/aataque3.png","Image/aataque4.png" };

	/*11*/  const char* const arquivo_Jogador_2_Parado[3] = { "Image/2parado0.png","Image/2parado1.png","Image/2parado2.png" };
	/*12*/  const char* const arquivos_Jogador_2_Anda[6] = { "Image/2Run (1).png","Image/2Run (2).png","Image/2Run (3).png","Image/2Run (4).png","Image/2Run (5).png","Image/2Run (6).png" };
	/*13*/  const char* const arquivos_Jogador_2_Ataque[5] = { "Image/2aataque.png","Image/2aataque1.png","Image/2aataque2.png","Image/2aataque3.png","Image/2aataque4.png" };

	/*14*/  const char* const arquivos_Chefao_parado[7] = { "Image/IDLE_000.png","Image/IDLE_001.png","Image/IDLE_002.png","Image/IDLE_003.png","Image/IDLE_004.png","Image/IDLE_005.png" ,"Image/IDLE_006.png" };
	/*15*/  const char* const arquivos_Chefao_mov[7] = { "Image/RUN_000.png","Image/RUN_001.png","Image/RUN_002.png","Image/RUN_003.png","Image/RUN_004.png","Image/RUN_005.png" ,"Image/RUN_006.png" };
	/*16*/  const char* const arquivos_Chefao_ataque[8] = { "Image/ATTAK_000.png","Image/ATTAK_001.png","Image/ATTAK_002.png","Image/ATTAK_003.png","Image/ATTAK_004.png","Image/ATTAK_005.png" ,"Image/ATTAK_005_1.png","Image/ATTAK_006.png" };
	/*17*/  const char* const arquivos_Chefao_morre[7] = { "Image/DIE_000.png","Image/DIE_001.png","Image/DIE_002.png","Image/DIE_003.png","Image/DIE_004.png","Image/DIE_005.png" ,"Image/DIE_006.png" };


	for (int i = 0; i < 3; i++)
		MapaBitmaps.insert(make_pair(make_pair(0, i), al_load_bitmap(arquivos_menu[i])));

	MapaBitmaps.insert(make_pair(make_pair(0, 3), al_load_bitmap("Image/TelaFimFase1.png")));
	MapaBitmaps.insert(make_pair(make_pair(0, 4), al_load_bitmap("Image/Cadastro.png")));
	MapaBitmaps.insert(make_pair(make_pair(0, 5), al_load_bitmap("Image/telaSalve.png")));
	for (int i = 0; i < 2; i++)
		MapaBitmaps.insert(make_pair(make_pair(1, i), al_load_bitmap(arquivos_bocMenu[i])));

	MapaBitmaps.insert(make_pair(make_pair(2, 0), al_load_bitmap(arquivos_pause)));
	for (int i = 0; i < 2; i++) {
		MapaBitmaps.insert(make_pair(make_pair(3, i), al_load_bitmap(arquivos_inimigo1[i])));
		MapaBitmaps.insert(make_pair(make_pair(4, i), al_load_bitmap(arquivos_abelhudo[i])));
	}
	for (int i = 0; i < 5; i++)
		MapaBitmaps.insert(make_pair(make_pair(5, i), al_load_bitmap(arquivos_cobreta[i])));

	for (int i = 0; i < 3; i++) {
		MapaBitmaps.insert(make_pair(make_pair(7, i), al_load_bitmap(arquivos_explosao[i])));
		MapaBitmaps.insert(make_pair(make_pair(8, i), al_load_bitmap(arquivo_Jogador_1_Parado[i])));
		MapaBitmaps.insert(make_pair(make_pair(11, i), al_load_bitmap(arquivo_Jogador_2_Parado[i])));
	}
	for (int i = 0; i < 6; i++) {
		MapaBitmaps.insert(make_pair(make_pair(9, i), al_load_bitmap(arquivos_Jogador_1_Anda[i])));
		MapaBitmaps.insert(make_pair(make_pair(12, i), al_load_bitmap(arquivos_Jogador_2_Anda[i])));
	}
	for (int i = 0; i < 5; i++) {
		MapaBitmaps.insert(make_pair(make_pair(10, i), al_load_bitmap(arquivos_Jogador_1_Ataque[i])));
		MapaBitmaps.insert(make_pair(make_pair(13, i), al_load_bitmap(arquivos_Jogador_2_Ataque[i])));
	}
	for (int i = 0; i < 7; i++) {
		MapaBitmaps.insert(make_pair(make_pair(14, i), al_load_bitmap(arquivos_Chefao_parado[i])));
		MapaBitmaps.insert(make_pair(make_pair(15, i), al_load_bitmap(arquivos_Chefao_mov[i])));
		MapaBitmaps.insert(make_pair(make_pair(16, i), al_load_bitmap(arquivos_Chefao_ataque[i])));
		MapaBitmaps.insert(make_pair(make_pair(17, i), al_load_bitmap(arquivos_Chefao_morre[i])));
	}
	MapaBitmaps.insert(make_pair(make_pair(16, 7), al_load_bitmap(arquivos_Chefao_ataque[7])));
	MapaBitmaps.insert(make_pair(make_pair(18, 0), al_load_bitmap("Image/Background2.png")));

	MapaBitmaps.insert(make_pair(make_pair(19, 0), al_load_bitmap("Image/espinhos.png")));
	MapaBitmaps.insert(make_pair(make_pair(20, 0), al_load_bitmap("Image/carnivora1.png")));
	MapaBitmaps.insert(make_pair(make_pair(20, 1), al_load_bitmap("Image/carnivora2.png")));
	MapaBitmaps.insert(make_pair(make_pair(21, 0), al_load_bitmap("Image/sangue.png")));
	MapaBitmaps.insert(make_pair(make_pair(22, 0), al_load_bitmap("Image/plataforma.png")));

	MapaBitmaps.insert(make_pair(make_pair(23, 0), al_load_bitmap("Image/placaFim.png")));
	MapaBitmaps.insert(make_pair(make_pair(24, 0), al_load_bitmap("Image/telaMorto.png")));
	MapaBitmaps.insert(make_pair(make_pair(25, 0), al_load_bitmap("Image/placar.png")));

}


Gerenciador_de_Bitmaps::~Gerenciador_de_Bitmaps()
{
	MapaBitmaps.clear();
}

ALLEGRO_BITMAP * Gerenciador_de_Bitmaps::get_imagem(int numImage, int pos) {
	it_img = MapaBitmaps.find(make_pair(numImage, pos));
	Imagem = it_img->second;
	return  Imagem;
}
void Gerenciador_de_Bitmaps:: desenha(int numImage, int pos, float x, float y, bool flipa) {
	it_img = MapaBitmaps.find(make_pair(numImage, pos));
	Imagem = it_img->second;
	al_draw_bitmap(Imagem, x, y, flipa);
}
