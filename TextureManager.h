#ifndef TextureManager_h
#define TextureManager_h

#include "Game.h"

class TextureManager
{
public:
	static SDL_Texture *LoadTexture(const char *fileName);
	static void draw(SDL_Texture *tex, SDL_Rect src, SDL_Rect dest);
};

#endif // TextureManager.h