#pragma once
#include <allegro5/allegro.h>
#include <allegro5/allegro_native_dialog.h>

#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>
#include <iostream>
#include <list>
#include <iterator>
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>     
#include <fstream> 

#define LARGURA_TELA 923
#define ALTURA_TELA 616
#define CHAO 560.0
#define FPS 30.0
#define FPSmenu 10.0
#define frameFPS 30.0
#define GRAVIDADE 1.0

using namespace::std;

enum { BAIXO, CIMA, DIREITA, ESQUERDA };