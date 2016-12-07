#pragma once
#ifndef _H_Mariposa_H_
#define _H_Mariposa_H_
#include "ObjetoPG.h"
#include "SDL.h"
#include "TexturaSDL.h" // pregunta pero yo creo que si hace falta, el draw lo necesiará,no?


class Mariposa : public ObjetoPG
{
public:
	Mariposa(Textura_t img, int x, int y, JuegoPG* juego, int numFrames);
	virtual ~Mariposa();
	//Métodos que hereda ???
	virtual void draw() const;
	bool onClick();
	virtual void update();
	bool visible;
private:
	Textura_t pTextura;
	JuegoPG* pJuego;
	int clicks;
	int frames;
	int actframe;
	int velx, vely;
	int puntos;
	void movimiento();
};
#endif