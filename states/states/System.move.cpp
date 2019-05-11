#include "System.h"
#include "Vector2d.h"
#include "random.h"

void System::move() {
	std::vector<std::vector<Cell>> map1 = map;
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < map[x].size(); y++) {
			map[x][y].power = 0;
		}
	}
	for (int x = width-1; x >=0; x--) {
		for (int y = 0; y < map[x].size(); y++) {
			if (map1[x][y].state == 0 || map1[x][y].power <= 0) {
				continue;
			}
			bool danger = 0;
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
				if (map1[x1][y1].state != map1[x][y].state) {
					//danger = 1;
					break;
				}
			}
			if (danger) {
				map[x][y].power += map1[x][y].power;
				//continue;
			}
			else {
				int n = random::random(0, shifts.size() - 1);
				Vector2d pos = shifts[n];
				int x1 = x + pos.x;
				int y1 = y + pos.y;
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
				if (map1[x1][y1].state != map1[x][y].state || map1[x1][y1].age > map1[x][y].age) {
					map[x][y].power += map1[x][y].power;
				}else
				map[x1][y1].power += map1[x][y].power;
			}
		}
	}
}