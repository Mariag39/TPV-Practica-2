#include "JuegoPG.h"
#include "SDL.h"
#include "Sound.h"
#include "TexturaSDL.h"
#include "GlobosPG.h"
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
	/*music->initMusica();
	music->loadMusic("Donna Summer- Hot Stuff.mp3");*/

	gameOver = false;

	punts = 0;
	numGlobos = 20;
	exit = false;
	nombarch[0] = "..\\bmps\\sky.png";
	nombarch[1] = "..\\bmps\\yellow.png";
	nombarch[2] = "png de premio";
	nombarch[3] = "png de mariposa";

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
	background.h = SCREEN_HEIGHT;
	background.w = SCREEN_WIDTH;
	background.y = 0;
	background.x = 0;
	sky->draw(pRenderer, background);
	// Draw objets Draw()

	for (int i = 0; i < globosvec.size(); i++) {
		globosvec[i]->draw();
	}

	//Show window																			
	SDL_RenderPresent(pRenderer);
}
void JuegoPG::initMedia() { //ahora es initMedia  
	/*
	TexturaSDL* globostext = new TexturaSDL();
	globostext->load(pRenderer, );
	m_globostext.push_back(globostext);


	int x;
	int y;
	for (int i = 0; i < numGlobos; i++) {
		x = rand() % (SCREEN_HEIGHT - 5);
		y = rand() % (SCREEN_WIDTH - 5);
		GlobosPG* globos = new GlobosPG(m_globostext[0], x, y); //falta el puntero a juegoPG
		globosvec.push_back(globos);

	}
	return true;*/
	
	


}
void JuegoPG::freeMedia() {  // ahora es freeMedia
	for (int i = 0; i < globosvec.size(); ++i) {
		delete globosvec[i];
	}
	delete m_globostext[0];
}
void JuegoPG::onClick(int mpx, int mpy) {
	for (int i = 0; i < globosvec.size(); ++i) {
		if (globosvec[i]->onClick()) {
			punts += globosvec[i]->puntos;
			numGlobos--;
		}
	}
}
void JuegoPG::getMousePos(int& mpx, int& mpy) const{
	SDL_GetMouseState(&mpx, &mpy);
}
void JuegoPG::newBaja(ObjetoJuego* po){

}


void JuegoPG::update() {
	for (int i = 0; i < globosvec.size(); ++i) {
		if (globosvec[i]->update()) {
			numGlobos--;
			
		}
	}
	if (numGlobos <= 0) {
		gameOver = true;
	}
	else {
		gameOver = false;
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
	delete sky;
	
}
