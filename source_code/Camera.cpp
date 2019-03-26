#include "Camera.h"
#include"Cabeçalho.h"


Camera::Camera()
{
	x = 0;
	y = 0;
}


Camera::~Camera()
{
}

void Camera::CameraUpdate(float x_jogador, float y_jogador, float largura, float altura, int ind)
{
	x = -(LARGURA_TELA / 2) + (x_jogador + (largura / 2));
	y = 0;

	if (x < 0)
		x = 0;
	if (ind == 0)
	{
		if (x > 923 * 6)
			x = 923 * 6;
	}
	else {
		if (x > 7845)
			x = 7845;
	}
}
