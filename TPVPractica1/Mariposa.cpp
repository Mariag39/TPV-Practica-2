#include "Mariposa.h"


Mariposa::Mariposa(Textura_t img, int px, int py, JuegoPG* juego, int numFrames) : pTextura(img), pJuego(juego), frames(numFrames)
{
	visible = true;
	puntos = 0;
	actframe = 1;
	velx = -5;
	vely = -5;
	clicks = 0;
}
void Mariposa::draw() const {
	pJuego->getTextura(texturas)->animationRect(frames, actframe);
}
void Mariposa::movimiento() {
	pJuego->random(rect.x, rect.y);
}
bool Mariposa::onClick() {
	if (visible && ObjetoPG::dentro(x, y)) {
		clicks++;
		movimiento();
		if (clicks == 3) {
			pJuego->newPremio(this);//this???
			clicks = 0;
		}

	}
	else {
		return false;
	}
}
void Mariposa::update() {
	rect.x += velx;
	rect.y += vely;
	if (actframe < frames - 1)
		actframe++;
	else actframe = 0;
}

Mariposa::~Mariposa()
{
	//delete guarever
}
