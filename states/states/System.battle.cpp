#include "System.h"
#include "Vector2d.h"
#include "random.h"

#include <iostream>

void System::battle(){
	std::vector<std::vector<Cell>> map1 = map;
	for (int x = 0; x < map.size(); x++) {
		for (int y = 0; y < map[x].size(); y++) {
			if (map1[x][y].state == 0) {
				continue;
			}
			int state = map1[x][y].state;
			if (map1[x][y].power <= 0)
				continue;
			for (Vector2d s : shifts) {
				int x1 = x + s.x;
				int y1 = y + s.y;
				if (x1 < 0) {
					x1 += width;
				}
				if (x1 > width - 1) {
					x1 -= width;
				}
				if (y1 < 0) {
					y1 += height;
				}
				if (y1 > height - 1) {
					y1 -= height;
				}
				if (map1[x1][y1].state != state && map1[x1][y1].state!=0) {
					int p = map1[x][y].power;
					//std::cout << state << "P = " << p << "\n";
					//if (map[x1][y1].power < p)
					map[x1][y1].power -= p;
						//map[x1][y1].state = state;
				}
			}
		}
	}
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < map[x].size(); y++) {
			if (map[x][y].power < 0) {
				map[x][y].state = 0;
			}
		}
	}
}