#include "System.h"
#include "Vector2d.h"
#include "random.h"

void System::generation() {
	for (int x = 0; x < width; x++) {
		for (int y = 0; y < height; y++) {
			if (random::random(1, map[x][y].chance.y) <= map[x][y].chance.x && map[x][y].state != 0) {
				map[x][y].power += map[x][y].resourses;
			}
		}
	}
}