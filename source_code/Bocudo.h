#pragma once
#include "Inimigo.h"
class Bocudo :
	public Inimigo
{
public:
	Bocudo();
	Bocudo(int lugar);
	~Bocudo();
	void mover(float boneco_x, float boneco_y);
	void desenha(Gerenciador_de_Bitmaps *gerenciadorBitmaps);
};

