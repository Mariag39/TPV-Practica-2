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
	GlobosPG(Textura_t img, int px, int py, JuegoPG* juego);
	~GlobosPG();
	virtual void draw() const;
	bool onClick();
	virtual void update();
	int puntos;
	bool visible;


private:
	SDL_Rect rect;
	Textura_t pTextura;
	float desinflado;
	JuegoPG* pJuego;
	bool explotado;
	const int PVIS = 20;
	const int PDES = 50;
	SDL_Renderer* pRenderer;

protected:
	
};
#endif

