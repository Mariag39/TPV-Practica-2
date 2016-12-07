#include "ObjetoPG.h"
using namespace std;


ObjetoPG::ObjetoPG()
{
}
bool ObjetoPG::dentro(int x, int y) const {
	x = pmx;
	y = pmy;
	pJuego->getMousePos(x, y);
	if (pmx >= rect.x && (rect.x + rect.w) >= pmx && pmy >= rect.y && (rect.y + rect.h) >= pmy) return true;
	else return false;
}
void ObjetoPG::draw() {
	rect.x = pmx;
	rect.y = pmy;
	rect.w = ancho;
	rect.h = alto;
    pJuego->getTextura(texturas)->draw(pJuego->getRender, rect);

}

ObjetoPG::~ObjetoPG()
{
}
