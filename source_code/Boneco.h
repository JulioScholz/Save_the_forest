#pragma once
#include "Gerenciador_de_Bitmaps.h"
#include "Entidade.h"
class Boneco : public Entidade
{

public:
	Boneco();
	~Boneco();
private:
	float vel_x;
	float vel_y;
	float vel_pulo;

	bool pulo;
	bool ataque;
	int direcao;
	int contAtaque;
	int cont;
	int playerrefresh;
public:
	void movimenta();
	void desenha(Gerenciador_de_Bitmaps *gerenciadorBitmaps, bool doisJogadores);


	const float get_vel_x()const { return vel_x; }
	const float get_vel_y()const { return vel_y; }
	void set_vel_x(float recebido) { vel_x = recebido; }
	void set_vel_y(float recebido) { vel_y += recebido; }
	const float get_vel_pulo()const { return vel_pulo; }
	const bool get_pulo() const { return pulo; }
	void set_pulo(bool recebido) { pulo = recebido; }
	void set_pulo() { pulo = (y >= 560 - 112); }

	void set_direcao(int recebido) { direcao = recebido; }
	const int get_direcao()const { return direcao; }

	void set_ataque(bool recebido) { ataque = recebido; }
	const bool get_ataque()const { return ataque; }
	void set_x(float recebido) { x = recebido; }
	void set_y(float recebido) { y = recebido; }
	void set_velocidade_y(float recebido) { vel_y = recebido; }

	const int get_contAtaque() const { return contAtaque; }
	void set_contAtaque(int recebido) { contAtaque = recebido; }
	void aumenta_contAtaque(int recebido) { contAtaque += recebido; }

	const int get_cont() const { return cont; }
	void set_cont(int recebido) { cont = recebido; }
	void aumenta_cont(int recebido) { cont += recebido; }
};

