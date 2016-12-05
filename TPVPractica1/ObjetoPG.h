#pragma once
#include "ObjetoJuego.h"
#include "SDL.h"
#include "JuegoPG.h"

class ObjetoPG :	public ObjetoJuego
{
public:
	ObjetoPG();
	virtual bool dentro() const {
		int pmx;
	    int pmy;
		pJuego->getMousePos(pmx, pmy);
		if (pmx >= rect.x && (rect.x + rect.w) >= pmx && pmy >= rect.y && (rect.y + rect.h) >= pmy) return true;
		else return false;
		
	}
	
    ~ObjetoPG();
private: 
	SDL_Rect rect;
	JuegoPG* pJuego;
};

