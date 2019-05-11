#pragma once
#include "System.h"
#include "Draw.h"

class Statistics{
public:
	Draw* drawTools;
	System* system;
	int states = 100;
	std::vector<std::vector<int>> sizeStat;
	std::vector<Color> sColors;
	Vector2d borders;
	int time = 0;

	Statistics();
	Statistics(Draw* _drawTools, System* _system);
	~Statistics();

	void step();
	void draw();
};

