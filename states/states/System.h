#pragma once
#include <vector>
#include "Cell.h"
#include <string>

class System{
public:
	int time = 0;
	int ageLimit = 200;
	std::vector<std::vector<Cell>> map;
	System();
	System(int width, int height);
	~System();
	void step();
	void loadFromFile(std::string path);
private:
	int width;
	int height;
	std::vector<Vector2d> shifts;
	void age();
	void generation();
	void move();
	void battle();
	void annexation();
};

