#pragma once
#ifndef _H_Premio_H_
#define _H_Premio_H_
#include "ObjetoPG.h"
#include "SDL.h"
#include "TexturaSDL.h" // pregunta pero yo creo que si hace falta, el draw lo necesiar�,no?


class Premio : public ObjetoPG
{
public:
	Premio();
	~Premio();
	//M�todos que hereda ???
	void draw() const;
	bool onClick();
	void update();
	int pp;
	bool visible;
	//void reinicio;    //m�todo espec�fico para reiniciar un premio

private:

};
#endif
