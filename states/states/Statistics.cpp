#include "Statistics.h"
#include <iostream>

Statistics::Statistics(){
}
Statistics::Statistics(Draw* _drawTools, System* _system) {
	drawTools = _drawTools;
	system = _system;
	borders = Vector2d(600, 600);
	for (int i = 0; i < states; i++) {
		sizeStat.push_back(std::vector<int>());
	}
}

Statistics::~Statistics(){
}

void Statistics::step() {
	int width = system->map.size();
	int height = 0;
	if (width > 0) {
		height = system->map[0].size();
	}
	for (int i = 0; i < states; i++) {
		sizeStat[i].push_back(0);
	}

	auto& map = system->map;
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (map[x][y].state != 0 && map[x][y].state <= states) {
				sizeStat[map[x][y].state - 1].back()++;
			}
		}
	}
	time++;
}

void Statistics::draw() {
	if (time <= 1) {
		return;
	}
	if (time > borders.x) {
		time = 0;
		drawTools->clear();
		for (int i = 0; i < states; i++) {
			sizeStat[i] = {};
		}
	}
	int width = system->map.size();
	int height = 0;
	if (width > 0) {
		height = system->map[0].size();
	}
	for (int i = 0; i < states; i++) {
		for (int j = time-1; j < time; j++) {
			double k = double(borders.y) / width / height;
			drawTools->drawLine(j, borders.y-sizeStat[i][j]*k, j - 1, borders.y - sizeStat[i][j - 1] * k, sColors[i]);
			//std::cout << "A";
		}
	}
	drawTools->push();
}