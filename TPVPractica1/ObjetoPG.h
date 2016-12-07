#pragma once
#ifndef _H_ObjetoPG_H_
#define _H_ObjetoPG_H_
#include "ObjetoJuego.h"
#include "SDL.h"
#include "JuegoPG.h"


class ObjetoPG :	public ObjetoJuego
{
public:
	ObjetoPG();
	virtual bool dentro(int x, int y) const;
		
	virtual void draw();
	
    ~ObjetoPG();
private: 
	
	
	

protected:
	int pmx;
	int pmy;
	int alto;
	int ancho;
	SDL_Rect rect;
	JuegoPG* pJuego;
	Textura_t texturas;
};
#endif

