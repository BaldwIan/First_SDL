#ifndef Game_h
#define Game_h

#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>



class Game
{
public:
	Game();
	~Game();

	void init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen);
	
	void handleEvents();
	void update();
	void render();
	void clean();

	bool running();

	static SDL_Renderer *renderer;


private:
	bool isRunning;
	SDL_Window *window;

};

#endif Game_h