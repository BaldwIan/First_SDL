#include "GameObject.h"
#include "TextureManager.h"

GameObject::GameObject(const char *texturesheet, int x, int y)
{
	objTexture = TextureManager::LoadTexture(texturesheet);

	xpos = x;
	ypos = y;

	srcRect.h = 32;
	srcRect.w = 32;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.w = srcRect.w * 2;
	destRect.h = srcRect.h * 2;
}

GameObject::~GameObject()
{}

void GameObject::update()
{
	xpos++;
	ypos++;

	destRect.x = xpos;
	destRect.y = ypos;
}

void GameObject::render()
{
	SDL_RenderCopy(Game::renderer, objTexture, &srcRect, &destRect);
}