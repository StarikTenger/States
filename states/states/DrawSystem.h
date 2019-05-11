#pragma once
#include "Draw.h"
#include "System.h"

class DrawSystem{
public:
	std::vector<Color> stateColors;
	int width, height;
	Vector2d cam;
	int size = 1;
	int mode = 0;

	Draw draw;
	DrawSystem();
	DrawSystem(SDL_Renderer * rend);
	~DrawSystem();
	void drawSys(System& sys);
};

