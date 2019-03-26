#pragma once
class Camera
{
private:
	float x;
	float y;
public:
	Camera();
	~Camera();
	void CameraUpdate(float x_jogador, float y_jogador, float largura, float altura, int ind);
	const float get_x()const { return x; }
	const float get_y()const { return y; }
};

