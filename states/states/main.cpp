#include "SDL.h"
#include <string>
#include <SDL_image.h>
#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <algorithm>
#include <fstream>

#include "getMilliCount.h"
#include "keys.h"
#include "Draw.h"
#include "System.h"
#include "random.h"
#include "DrawSystem.h"
#include "Statistics.h"


int main(int, char**){
	random::start();

	int size = 600;
	SDL_Window *window = SDL_CreateWindow("WINDOW", 20, 50, size, size, SDL_WINDOW_SHOWN);
	SDL_Renderer *render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Draw draw(render);
	DrawSystem drawSys(render);
	drawSys.size = 6;

	System sys;

	//statistics
	SDL_Window *windowStat = SDL_CreateWindow("WINDOW", 500, 50, size, size, SDL_WINDOW_SHOWN);
	SDL_Renderer *renderStat = SDL_CreateRenderer(windowStat, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	Draw drawStat(renderStat);
	Statistics stat(&drawStat, &sys);

	
	std::ifstream file("size.size");
	sys.loadFromFile("system.sys");
	file >> drawSys.size;
	file.close();

	int width = sys.map.size();
	int height = 0;
	if (width > 0) {
		height = sys.map[0].size();
	}


	int civilizations = 1000;
	std::vector<Color>& sColors = drawSys.stateColors;
	for (int i = 0; i < civilizations; i++) {
		sColors.push_back(Color(random::random(0, 255), random::random(0, 255), random::random(0, 255), 255));
	}
	stat.sColors = sColors;
	SDL_SetWindowSize(window, drawSys.size*width, drawSys.size*height);

	//time
	int dt = 20;
	int timePrev = getMilliCount();

	Vector2d& cam = drawSys.cam;
	int& view = drawSys.mode;

	bool stop = 0;
	while (!stop) {
		int timeMs = getMilliCount();
		if (timeMs - timePrev > dt) {
			timePrev = timeMs;

			SDL_Event event;
			while (SDL_PollEvent(&event)) {
				switch (event.type) {
				case SDL_QUIT:
					stop = 1;
					break;
				case SDL_KEYDOWN:
					if (getKey(event.key.keysym.sym) == W) {
						cam.y--;
					}
					if (getKey(event.key.keysym.sym) == S) {
						cam.y++;
					}
					if (getKey(event.key.keysym.sym) == A) {
						cam.x--;
					}
					if (getKey(event.key.keysym.sym) == D) {
						cam.x++;
					}
					break;
				case SDL_KEYUP:
					if (getKey(event.key.keysym.sym) == SPACE) {
						view = !view;
					}
					break;
				}

			}
			for(int i=0; i<1; i++)
			sys.step();
			drawSys.drawSys(sys);
			stat.step();
			stat.draw();
			
		//	std::cout << mp << "\n";
		}
	}
	return 0;
}