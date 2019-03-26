#pragma once
#include "Inimigo.h"
class Chefao :
	public Inimigo
{
private:
	int ataque;
	int contMov;
	int contAtaque;
	int contParado;
	int refresh;
public:
	Chefao();
	~Chefao();

	void mover(float boneco_x, float boneco_y);

	void atacar();

	void desenha(Gerenciador_de_Bitmaps *gerenciadorBitmaps);

	const int get_ataque() const { return ataque; }
	void set_ataque(int recebido) { ataque = recebido; }

	const int get_contMov() const { return contMov; }
	void set_contMov(int recebido) { contMov = recebido; }
	void aumenta_contMov(int recebido) { contMov += recebido; }

	const int get_contParado() const { return contParado; }
	void set_contParado(int recebido) { contParado = recebido; }
	void aumenta_contParado(int recebido) { contParado += recebido; }

	const int get_contAtaque() const { return contAtaque; }
	void set_contAtaque(int recebido) { contAtaque = recebido; }
	void aumenta_contAtaque(int recebido) { contAtaque += recebido; }

	const int get_refresh() const { return refresh; }
	void set_refresh(int recebido) { refresh = recebido; }
	void aumenta_refresh(int recebido) { refresh += recebido; }
};

