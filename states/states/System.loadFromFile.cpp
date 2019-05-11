#include "System.h"
#include "random.h"
#include <fstream>

//using namespace random;
void System::loadFromFile(std::string path) {
	std::ifstream file(path);
	Vector2d borders;
	int states = 0;
	int startPoints = 1;
	int power = 1;
	int limit = 50;
	Vector2d expanseChance(1, 1);
	Vector2d soldierChance(1, 1);
	while (1) {
		std::string command;
		file >> command;
		if (command == "END") {
			break;
		}
		if (command == "BORDERS") {
			file >> borders.x >> borders.y;
		}
		if (command == "STATES") {
			file >> states;
		}
		if (command == "STARTPOINTS") {
			file >> startPoints;
		}
		if (command == "EXPANSECHANCE") {
			file >> expanseChance.x >> expanseChance.y;
		}
		if (command == "ARMYCHANCE") {
			file >> soldierChance.x >> soldierChance.y;
		}
		if (command == "RESOURCES") {
			file >> power;
		}
		if (command == "AGELIMIT") {
			file >> limit;
		}
	}
	*this = System(borders.x, borders.y);
	ageLimit = limit;
	Cell cell;
	cell.hardness = expanseChance;
	cell.chance = soldierChance;
	cell.resourses = power;

	for (int x = 0; x < borders.x; x++) {
		for (int y = 0; y < borders.y; y++) {
			map[x][y] = cell;
		}
	}

	if(states>1000){
		states = 1000;
	}

	for (int i = 0; i < states; i++) {
		for (int j = 0; j < startPoints; j++) {
			map[random::random(0, borders.x - 1)][random::random(0, borders.y - 1)].state = i+1;
		}
	}
	file.close();
}