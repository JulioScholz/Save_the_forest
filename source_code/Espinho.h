#pragma once
#include "Obstaculo.h"
class Espinho : public Obstaculo
{

public:
	Espinho();
	Espinho(int lugar);
	~Espinho();
	void desenha(Gerenciador_de_Bitmaps *gerenciadorBitmaps);
	void ativar();
};

