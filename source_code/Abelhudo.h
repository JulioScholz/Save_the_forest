#pragma once
#include "Inimigo.h"
class Abelhudo :
	public Inimigo
{
public:
	Abelhudo();
	Abelhudo(int lugar);
	~Abelhudo();
	void mover(float boneco_x, float boneco_y);
	void desenha(Gerenciador_de_Bitmaps *gerenciadorBitmaps);
	
};

