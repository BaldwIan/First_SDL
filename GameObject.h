#include "Game.h"

class GameObject
{
public:
	GameObject(const char *texturesheet, SDL_Renderer *ren, int x, int y);
	~GameObject();

	void update();
	void render();

private:
	int xpos, ypos;

	SDL_Texture *objTexture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer *renderer;

};