#include "ObjetoPG.h"
using namespace std;


ObjetoPG::ObjetoPG()
{
}
bool ObjetoPG::dentro(int x, int y) const {
	int pmx = x;
	int pmy = y;
	pJuego->getMousePos(x, y);
	return (pmx >= x && (x + ancho) >= pmx && pmy >= y && (y + alto) >= pmy);
	
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
