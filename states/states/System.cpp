#include "System.h"
#include "Vector2d.h"
#include "random.h"

#include <iostream>

System::System(){}
System::System(int width, int height) {
	for (int x = 0; x < width; x++) {
		map.push_back(std::vector<Cell>());
		for (int y = 0; y < height; y++) {
			map[x].push_back(Cell());
		}
	}
}
System::~System(){}

void System::step() {
	time++;
	width = map.size();
	height = 0;
	if (width > 0) {
		height = map[0].size();
	}
	/*shifts = {
		Vector2d(1, 1),
		Vector2d(1, 0),
		Vector2d(1, -1),
		Vector2d(-1, 1),
		Vector2d(-1, 0),
		Vector2d(-1, -1),
		Vector2d(0, 1),
		Vector2d(0, -1)
	};*/
	shifts = {};
	int n = 1;
	for (int x = -n; x <= n; x++) {
		for (int y = -n; y <= n; y++) {
			if(x!=0 || y!=0)
			shifts.push_back(Vector2d(x, y));
		}
	}
	age();
	generation();
	annexation();
	move();
	battle();
}
