#pragma once
#ifndef _H_Mariposa_H_
#define _H_Mariposa_H_
#include "ObjetoPG.h"
#include "SDL.h"
#include "TexturaSDL.h" // pregunta pero yo creo que si hace falta, el draw lo necesiar�,no?


class Mariposa : public ObjetoPG
{
public:
	Mariposa();
	~Mariposa();
	//M�todos que hereda ???
	void draw() const;
	bool onClick();
	void update();
	bool visible;
};
#endif