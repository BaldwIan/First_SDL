#include "Game.h"
#include "TextureManager.h"
#include "GameObject.h"
#include "Map.h"

SDL_Renderer *Game::renderer = nullptr;

Map *map;

GameObject *player;
GameObject *monkey;

Game::Game()
{}

Game::~Game()
{}

void Game::init(const char *title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if (fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL initialized properly" << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags);
		if (window)
		{
			std::cout << "Window created." << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created." << std::endl;
		}

		isRunning = true;
	} else
	{
		isRunning = false;
	}

	map = new Map();

	player = new GameObject("assets/player.png", 0, 0);
	monkey = new GameObject("assets/monkey.png", -45, 45);
}

void Game::handleEvents()
{
	SDL_Event event;
	SDL_PollEvent(&event);
	switch(event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;

	default:
		break;
	}
}

void Game::update()
{
	player->update();
	monkey->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->DrawMap();
	player->render();
	monkey->render();
	SDL_RenderPresent(renderer);
}


void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned" << std::endl;
}

bool Game::running()
{
	return isRunning;
}