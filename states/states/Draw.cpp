#include "Draw.h"
#include "SDL.h"
#include <string>
#include <SDL_image.h>
#include <iostream>
Draw::Draw(SDL_Renderer * rend) {
	render = rend;
}

SDL_Texture* Draw::loadImage(std::string path)
{

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(render, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return newTexture;
}
void Draw::drawImage(SDL_Texture *tex, double x, double y, double width, double height, double angle) {
	angle = angle / M_PI * 180;

	SDL_Rect pos;
	pos.x = x - width / 2;
	pos.y = y - height / 2;
	SDL_QueryTexture(tex, NULL, NULL, &pos.w, &pos.h);

	pos.w = width;
	pos.h = height;

	SDL_RenderCopyEx(render,
		tex,
		NULL,
		&pos,
		angle,
		NULL,
		SDL_FLIP_NONE);
}
void Draw::drawLine(double x1, double y1, double x2, double y2, Color color) {
	//SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_ADD);
	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
	SDL_RenderDrawLine(render, x1, y1, x2, y2);
}
void Draw::drawStrokeRect(double x, double y, double width, double height, Color color) {
	//SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_ADD);
	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
	SDL_Rect* rect = new SDL_Rect;
	rect->x = x;
	rect->y = y;
	rect->w = width;
	rect->h = height;
	SDL_RenderDrawRect(render, rect);
	delete rect;
}
void Draw::drawFillRect(double x, double y, double width, double height, Color color) {
	SDL_SetRenderDrawBlendMode(render, SDL_BLENDMODE_ADD);
	SDL_SetRenderDrawColor(render, color.r, color.g, color.b, color.a);
	SDL_Rect* rect = new SDL_Rect;
	rect->x = x;
	rect->y = y;
	rect->w = width;
	rect->h = height;
	SDL_RenderFillRect(render, rect);
	delete rect;
}
void Draw::clear() {
	SDL_SetRenderDrawColor(render, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(render);
}
void Draw::push() {
	SDL_RenderPresent(render);
}