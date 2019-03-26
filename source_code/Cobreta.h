#pragma once
#include "Obstaculo.h"
class Cobreta :
	public Obstaculo
{
private:
	int contador;
public:
	Cobreta();
	Cobreta(int lugar);
	~Cobreta();
	void ativar(float boneco_x, float boneco_y);
	void ativar();
	void desenha(Gerenciador_de_Bitmaps *gerenciadorBitmaps);
	const int get_contador() const { return contador; }
	void set_contador(int recebido) { contador = recebido; }
	void aumenta_contador(int recebido) { contador += recebido; }

};

