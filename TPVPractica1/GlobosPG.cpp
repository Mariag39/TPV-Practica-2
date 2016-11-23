#include "GlobosPG.h"
#include "JuegoPG.h"
#include "SDL_image.h"
using namespace std;

GlobosPG::GlobosPG(TexturaSDL* img, int px, int py, JuegoPG* juego) :pTextura(img)
{

	
	if (rand() % 100 < PVIS) visible = true; else visible = false;
	explotado = false;
	rect.x = px;
	rect.y = py;
	rect.w = pTextura->getWidth();
	rect.h = pTextura->getHeight();
	desinflado = 5;
	

}

bool GlobosPG::onClick() {
	bool destruido = false;
	if (visible && !explotado) {
		if (pmx >= rect.x && (rect.x + rect.w) >= pmx && pmy >= rect.y && (rect.y + rect.h) >= pmy) {
			visible = false;
			destruido = true;
			//puntos++;
			explotado = true;

		}
	}
	return destruido;
	
}

bool GlobosPG::update() {                        //¡no es bool!
	//actualiza el estado de los globos
	bool destruido = false;
	if (!explotado && visible) {

		if ((rand() % 100 > PDES)) {
			rect.h -= desinflado;
			rect.w -= desinflado;
			puntos += 5;
			if (rect.h <= 0 || rect.w <= 0) {
				visible = false;
				destruido = true;
				explotado = true;
			}
		}

	}
	if (!explotado && !visible)
		if (rand() % 100 < PVIS) visible = true; else visible = false;
	return destruido;
}




void GlobosPG::draw() const {
	if (visible && !explotado) {

		pTextura->draw(pRenderer, rect);
	}
}

GlobosPG::~GlobosPG()
{
	delete pTextura;
	
}
