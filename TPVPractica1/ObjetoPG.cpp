#include "ObjetoPG.h"
using namespace std;


ObjetoPG::ObjetoPG()
{
	rect.x = x;
	rect.y = y;
	rect.w = ancho;
	rect.h = alto;
}
bool ObjetoPG::dentro(int x, int y) const {
	int pmx;
	int pmy;
	pJuego->getMousePos(pmx, pmy);
	return (pmx >= x && (x + rect.w) >= pmx && pmy >= y && (y + rect.h) >= pmy);
	
}
void ObjetoPG::draw() {
	
    pJuego->getTextura(texturas)->draw(pJuego->getRender, rect);
}

ObjetoPG::~ObjetoPG()
{
}
