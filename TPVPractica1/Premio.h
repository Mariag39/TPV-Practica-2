#pragma once
#ifndef _H_Premio_H_
#define _H_Premio_H_
#include "ObjetoPG.h"
#include "SDL.h"
#include "TexturaSDL.h" // pregunta pero yo creo que si hace falta, el draw lo necesiará,no?


class Premio : public ObjetoPG
{
public:
	Premio();
	~Premio();
	//Métodos que hereda ???
	void draw() const;
	bool onClick();
	void update();
	int pp;
	bool visible;
	//void reinicio;    //método específico para reiniciar un premio

private:

};
#endif
