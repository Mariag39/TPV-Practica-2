#pragma once
#ifndef _H_Premio_H_
#define _H_Premio_H_
#include "ObjetoPG.h"
#include "SDL.h"



class Premio : public ObjetoPG
{
public:
	Premio(Textura_t img, int x, int y, JuegoPG* pJuego);
	virtual ~Premio();
	//Métodos que hereda ???
	virtual void draw() const;
	bool onClick();
	virtual void update();
	int pp;
	bool visible;
	//void reinicio;    //método específico para reiniciar un premio

private:
	JuegoPG* pJuego;
	Textura_t pTextura;
	int ini = 15;
	void reinicio();
	int oport;
};
#endif
