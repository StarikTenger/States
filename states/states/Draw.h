#pragma once
#include "SDL.h"
#include <string>
#include <SDL_image.h>

struct Color {
	int r, g, b, a;
	Color() {};
	Color(int r1, int g1, int b1, int a1);
};
class Draw {
private:

public:
	SDL_Renderer* render;
	Draw() {}
	Draw(SDL_Renderer* rend);
	SDL_Texture* loadImage(std::string path);
	void drawImage(SDL_Texture *tex, double x, double y, double width, double height, double angle);
	void drawLine(double x1, double y1, double x2, double y2, Color color);
	void drawStrokeRect(double x, double y, double width, double height, Color color);
	void drawFillRect(double x, double y, double width, double height, Color color);
	void clear();
	void push();
};

