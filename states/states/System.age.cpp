#include "System.h"
#include "Vector2d.h"
#include "random.h"

void System::age() {
	for (int x = 0; x < width; x ++) {
		for (int y = 0; y < map[x].size(); y++) {
			if (map[x][y].state == 0) {
				map[x][y].age = 0;
			}
			else if(map[x][y].age<ageLimit){
				map[x][y].age++;
			}
		}
	}
}