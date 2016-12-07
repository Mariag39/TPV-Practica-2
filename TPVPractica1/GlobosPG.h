#pragma once
#ifndef _H_GlobosPG_H_
#define _H_GlobosPG_H_
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
	void update();
	int puntos;
	bool visible;


private:
	SDL_Rect rect;
	TexturaSDL* pTextura;
	float desinflado;
	JuegoPG* pJuego;
	bool explotado;
	const int PVIS = 20;
	const int PDES = 50;
	SDL_Renderer* pRenderer;

protected:
	
};
#endif

