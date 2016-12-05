#pragma once
#include "ObjetoJuego.h"

class ObjetoPG :	public ObjetoJuego
{
public:
	ObjetoPG();
	virtual bool dentro(){
		int pmx;
	    int pmy;
		if (pmx >= rect.x && (rect.x + rect.w) >= pmx && pmy >= rect.y && (rect.y + rect.h) >= pmy) return true;
		else return false;
	}
    ~ObjetoPG();
private: 
	SDL_Rect rect;
};

