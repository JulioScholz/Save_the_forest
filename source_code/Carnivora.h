#pragma once
#include "Obstaculo.h"
class Carnivora :public Obstaculo
{
private:
	int contador;
public:
	Carnivora();
	Carnivora(int lugar);
	~Carnivora();
	void ativar(float boneco_x, float boneco_y);
	void desenha(Gerenciador_de_Bitmaps *gerenciadorBitmaps);

	const int get_contador() const { return contador; }
	void set_contador(int recebido) { contador = recebido; }
	void aumenta_contador(int recebido) { contador += recebido; }
	void ativar();


	
};

