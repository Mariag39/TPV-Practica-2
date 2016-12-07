#include "Premio.h"


Premio::Premio(Textura_t img, int x, int y, JuegoPG* juego): pTextura(img), pJuego(juego)
{
	visible = false;
	pp = ini;
}

void Premio::draw() const {
   
}
bool Premio::onClick() {
	if (ObjetoPG::dentro(x, y)) {
		pJuego->newPuntos(this);
		pJuego->newBaja(this);
		reinicio();
		return true;
	}
	else if (visible) {
		if (oport < 3)
			oport++;
	}
	else {
		pJuego->newBaja(this);
		//reinicio();
	}
	return false;
}

void Premio::reinicio() {
	pp = ini;
	oport = 0;
	pJuego->random(rect.x, rect.y);
	visible = false;
}
void Premio::update() {
	pp -= 1;
}

Premio::~Premio()
{ 
	//delete guarever
}
