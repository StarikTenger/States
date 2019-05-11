#include "System.h"
#include "Vector2d.h"
#include "random.h"

#include <vector>

void System::annexation() {
	std::vector<std::vector<Cell>> map1 = map;
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < map[x].size(); y++) {
			if (map1[x][y].state == 0) {
				int n = 0;
				int neighbor = 0;
				std::vector<int> neighbors;
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
					if (map1[x1][y1].state != 0) {
						neighbors.push_back(map1[x1][y1].state);
					}
				}
				auto h = map1[x][y].hardness;
				if (random::random(1, h.y) <= h.x && neighbors.size()>0)
					map[x][y].state = neighbors[random::random(0, neighbors.size()-1)];
			}
		}
	}
}