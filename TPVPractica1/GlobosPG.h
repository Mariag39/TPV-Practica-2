#pragma once
#include "SDL.h"
#include "TexturaSDL.h"
#include <vector>
using namespace std;
class GlobosPG
{



public:
	GlobosPG(TexturaSDL* img, int px, int py);
	~GlobosPG();
	void draw(SDL_Renderer* pRenderer) const;
	bool onClick(int pmx, int pmy);
	bool update();
	int puntos;
	


private:
	SDL_Rect rect;
	TexturaSDL* pTextura;
	float desinflado;
	bool visible;
	bool explotado;
	const int PVIS = 20;
	const int PDES = 50;
};

