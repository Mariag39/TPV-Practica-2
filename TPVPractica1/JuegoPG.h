#pragma once
#include "SDL.h"
#include <vector>
#include "SDL_image.h"
#include "Sound.h"
#include "ObjetoJuego.h"
using namespace std;


 enum Textura_t { TFondo = 0, TGlobo = 1, TPremio = 2, TMariposa = 3 };
class JuegoPG
{
	
public:
	JuegoPG();
	~JuegoPG();
	void run();
	void onExit();
	
	TexturaSDL* getTextura(Textura_t et) const { return m_globostext[et]; } //es el vector de texturas??
	SDL_Renderer* getRender() const;
	void getMousePos(int& mpx, int& mpy) const;
	void newBaja(ObjetoJuego* po); // Los objetos informarán al juego cuando causen baja  
	void newPuntos(ObjetoJuego* po); // Los objetos informarán al juego cuando se obtengan puntos 
	void newPremio(ObjetoJuego* po); // Los objetos informará al juego cuando se obtenga un premio 
	void initMedia(); // carga las texturas en el vector de texturas (fuente y música)  
	void freeMedia();
	

private:
	/*Sound* music;*/
	bool initSDL();
	
	vector<string> nombarch;
	void closeSDL();
	void Mensaje(string msg1, string msg2);
	void render() ;
	void onClick(int mpx, int mpy);
	void update();
	void handle_event();
	SDL_Window* pWindow;
	SDL_Renderer* pRenderer;
	SDL_Texture* pTexture;
	vector<TexturaSDL*> m_globostext;
	vector<ObjetoJuego*> globosvec; //era GlobosPG
	const int SCREEN_WIDTH = 640;   //Screen dimension
	const int SCREEN_HEIGHT = 480;  //Screen dimension
	SDL_Rect background;
	TexturaSDL* sky;
	bool error;
	bool exit;
	bool gameOver;
	int punts;
	int numGlobos;

};

