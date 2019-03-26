#include "Cabeçalho.h"
#pragma once
class Gerenciador_de_Bitmaps
{
public:
	Gerenciador_de_Bitmaps();
	~Gerenciador_de_Bitmaps();
private:
	multimap <pair<int, int>, ALLEGRO_BITMAP* >  MapaBitmaps;
	multimap <pair<int, int>, ALLEGRO_BITMAP* > ::iterator it_img;
	ALLEGRO_BITMAP* Imagem;
	static const char* const arquivos_menu[6];
	static const char* const arquivos_bocMenu[2];
	static const char* const arquivos_pause;

	static const char* const arquivos_inimigo1[2];
	static const char* const arquivos_abelhudo[2];
	static const char* const arquivos_cobreta[5];

	static const char* const arquivos_explosao[3];
	static const char* const arquivo_Jogador_1_Parado[3];
	static const char* const arquivos_Jogador_1_Anda[6];
	static const char* const arquivos_Jogador_1_Ataque[5];

	static const char* const arquivo_Jogador_2_Parado[3];
	static const char* const arquivos_Jogador_2_Anda[6];
	static const char* const arquivos_Jogador_2_Ataque[5];

	static const char* const arquivos_Chefao_parado[7];
	static const char* const arquivos_Chefao_mov[7];
	static const char* const arquivos_Chefao_ataque[8];
	static const char* const arquivos_Chefao_morre[7];
public:
	ALLEGRO_BITMAP* get_imagem(int numImage, int pos);
	
	void desenha(int numImage, int pos, float x, float y, bool flipa);
	

};