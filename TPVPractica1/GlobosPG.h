#pragma once
#include "SDL.h"
#include "TexturaSDL.h"
#include <vector>
#include "ObjetoPG.h"


using namespace std;
class GlobosPG : public ObjetoPG
{


public:
	GlobosPG(TexturaSDL* img, int px, int py, JuegoPG* juego);
	~GlobosPG();
	void draw() const;
	bool onClick();
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
	SDL_Renderer* pRenderer;
};

