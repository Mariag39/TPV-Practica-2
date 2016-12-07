#include "JuegoPG.h"
#include "SDL.h"
#include "Sound.h"
#include "TexturaSDL.h"
#include "GlobosPG.h"
#include "Premio.h"
#include "Mariposa.h"
#include <iostream>
#include "SDL_image.h"
#include <vector>
#include <time.h>
using namespace std;

JuegoPG::JuegoPG()
{
	//inicializar vectores
	srand(SDL_GetTicks());
	if (initSDL()) {
		error = false;
	}
	else {
		error = true;
	}
	initMedia();
	initObjetos();
	

	gameOver = false;

	punts = 0;
	numMariposas = 5;
	numGlobos = 20;
	exit = false;
	nombarch[0] = "..\\bmps\\sky.png";
	nombarch[1] = "..\\bmps\\yellow.png";
	nombarch[2] = "..\\bmps\\premio.png";
	nombarch[3] = "..\\bmps\\mariposa.png";

}
void JuegoPG::Mensaje(string msg1, string msg2) {
	SDL_ShowSimpleMessageBox(SDL_MESSAGEBOX_INFORMATION,
		msg1.c_str(), msg2.c_str(), nullptr);
}

bool JuegoPG::initSDL() {
	bool success = true; //Initialization flag


						 //Initialize SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "SDL could not initialize! \nSDL_Error: " << SDL_GetError() << '\n';
		success = false;

	}
	else {
		//Create window: SDL_CreateWindow("SDL Hello World", posX, posY, width, height, SDL_WINDOW_SHOWN);
		pWindow = SDL_CreateWindow("SDL Práctica 1", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (pWindow == nullptr) {
			cout << "Window could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
			success = false;
		}
		else {
			//Get window surface:
			pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
			//SDL_SetRenderDrawColor(pRenderer, 0, 0, 0, 255); //Set background color to black 
			if (pRenderer == nullptr) {
				cout << "Renderer could not be created! \nSDL_Error: " << SDL_GetError() << '\n';
				success = false;
			}
		}
	}

	return success;
}
void JuegoPG::closeSDL() {

	SDL_DestroyRenderer(pRenderer);
	pRenderer = nullptr;

	SDL_DestroyWindow(pWindow);
	pWindow = nullptr;

	SDL_Quit();
}
void JuegoPG::render()  {
	//Clear the window to background color 
	SDL_RenderClear(pRenderer);

	SDL_SetRenderDrawColor(pRenderer, 255, 255, 255, 255);

	for (int i = 0; i < objetosvec.size(); i++) {
		objetosvec[i]->draw();
	}

	//Show window																			
	SDL_RenderPresent(pRenderer);
}
void JuegoPG::initMedia() {
    /*music->initMusica();
	music->loadMusic("Donna Summer- Hot Stuff.mp3");*/
	for (size_t i = 0; i < 3; i++) {
		objetostext.push_back(new TexturaSDL());
		objetostext[i]->load(pRenderer, nombarch[i]);
	}
}
void JuegoPG::random(int& x, int& y) {
	y = rand() % SCREEN_HEIGHT;
	x = rand() % SCREEN_WIDTH;
	if (y > SCREEN_HEIGHT - 100) y = SCREEN_HEIGHT - 100;
	if (x > SCREEN_WIDTH - 100) x = SCREEN_WIDTH - 100;

}
bool JuegoPG::initObjetos(){
	
	int x;
	int y;
	for (int i = 0; i < numGlobos; i++) {

		x = rand() % (SCREEN_HEIGHT - 5);
		y = rand() % (SCREEN_WIDTH - 5);
		objetosvec.push_back(new GlobosPG(Textura_t::TGlobo,x, y, this));
	}
	for (int i = 0; i < numMariposas; i++) {

		x = rand() % (SCREEN_HEIGHT - 5);
		y = rand() % (SCREEN_WIDTH - 5);
		objetosvec.push_back(new Mariposa(Textura_t::TMariposa,x, y, this, 10));
	}
	x = rand() % (SCREEN_HEIGHT - 5);
	y = rand() % (SCREEN_WIDTH - 5);
	objetosvec.push_back(new Premio(Textura_t::TPremio,x, y, this));
	return true;
  }

void JuegoPG::freeMedia() {
	for (unsigned int i = 0; i < objetosvec.size(); i++) {
		if (objetosvec[i] != nullptr) {
			delete objetosvec[i];
			
		}
	}
	for (unsigned int i = 0; i < objetostext.size(); i++) {
		delete objetostext[i];
		
	}
}
void JuegoPG::onClick(int mpx, int mpy){
	bool pinchado = false;
	for (int i = objetosvec.size() - 1; i >= 0; i--) {
		if (objetosvec[i]->onClick()) {
			pinchado = true;
		}
	}
}
void JuegoPG::getMousePos(int& mpx, int& mpy) const{
	SDL_GetMouseState(&mpx, &mpy);
}
void JuegoPG::newBaja(ObjetoJuego* po){
	if (typeid(*po) == typeid(GlobosPG)){
		numGlobos--;
		dynamic_cast<GlobosPG*>(po)->visible = false;
	}
	else if (typeid(*po) == typeid(Mariposa)){
		dynamic_cast<Mariposa*>(po)->visible = false;
		newPuntos(po);
	}
	else if (typeid(po) == typeid(Premio)){
		dynamic_cast<Premio*>(po)->visible = false;
	}
}
void JuegoPG::newPuntos(ObjetoJuego* po) {
	if (typeid(po) == typeid(GlobosPG)) {
		punts += dynamic_cast<GlobosPG*>(po)->puntos;
	}
	else if (typeid(po) == typeid(Premio)) {
		punts += dynamic_cast<Premio*>(po)->pp;
	}
	else if (typeid(po) == typeid(Mariposa)){
		newPremio(po);
	} 

}
void JuegoPG::newPremio(ObjetoJuego* po){ 
	
	if (typeid(po) == typeid(Premio)) {
		dynamic_cast<Premio*>(po)->visible = true;
	}
}

void JuegoPG::update() {
	for (int i = 0; i < objetosvec.size(); ++i) {
		objetosvec[i]->update();
	}

}

void JuegoPG::onExit() {
	exit = true;
	cout << "EXIT ";
}
void JuegoPG::run() {
	if (!error) {
		Uint32 MSxUpdate = 500;
		cout << "PLAY\n";
		Uint32 lastUpdate = SDL_GetTicks();
		Mensaje("PLAY","Ready?");
		/*music->PlayMusic();*/
		initMedia();
		render();
		handle_event();
		while (!exit && !gameOver) {
			if (SDL_GetTicks() - lastUpdate >= MSxUpdate) {
				update();
				lastUpdate = SDL_GetTicks();
			}
			render();
			handle_event();
		}

		if (exit || gameOver) {
			string puntuacion = to_string(punts);
			Mensaje("Game Over", "Puntuacion: " +puntuacion);
			closeSDL();
			cout << "\nHas obtenido " << punts << " puntos\n";
		}
		/*music->close();*/
		SDL_Delay(1000);
		
		cin.get();
	}
}

void JuegoPG::handle_event() {
	SDL_Event e;
	while (SDL_PollEvent(&e) && !exit) {
		if (e.type == SDL_QUIT) {
			onExit();
		}
	else if (e.type == SDL_MOUSEBUTTONUP) {
		if (e.button.button == SDL_BUTTON_LEFT) {
			cout << "CLICK";
			onClick(e.button.x, e.button.y);
		}
	}
}
}


JuegoPG::~JuegoPG()
{
	freeMedia ();
	closeSDL();
	
	
}
