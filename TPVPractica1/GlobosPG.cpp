#include "GlobosPG.h"
#include "JuegoPG.h"
#include "SDL_image.h"
using namespace std;

GlobosPG::GlobosPG(Textura_t img, int px, int py, JuegoPG* juego) :pTextura(img), pJuego(juego)
{
	if (rand() % 100 < PVIS) visible = true; else visible = false;
	explotado = false;
	rect.x = px;
	rect.y = py;
	rect.w = 100;
	rect.h = 150;
	desinflado = 5;
	
}

bool GlobosPG::onClick() {
	bool destruido = false;
	if (visible && !explotado) {
		  if (ObjetoPG::dentro(rect.x,rect.y)){ 
			  pJuego->newBaja(this);
			  pJuego->newPuntos(this);
			  destruido = true;
			  explotado = true;
		}
	}
	return destruido;
	
}

void GlobosPG::update() {                       
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
		if (rand() % 100 < PVIS) visible = true; 
		else {
			visible = false;
			pJuego->newBaja(this);
		}
	//return destruido;
}

void GlobosPG::draw() const {
	
	}


GlobosPG::~GlobosPG()
{
	
	
}
