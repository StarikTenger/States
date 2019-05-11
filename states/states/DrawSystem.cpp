#include "DrawSystem.h"

DrawSystem::DrawSystem(){
}
DrawSystem::DrawSystem(SDL_Renderer * rend) {
	draw = Draw(rend);
}
DrawSystem::~DrawSystem(){
}

void DrawSystem::drawSys(System& sys) {
	width = sys.map.size();
	height = 0;
	if (width > 0) {
		height = sys.map[0].size();
	}

	draw.clear();
	//draw.drawStrokeRect(0, 0, sys.map.size()*size, sys.map[0].size()*size, Color(255, 255, 255, 255));
	for (int x = 0; x < sys.map.size(); x++) {
		for (int y = 0; y < sys.map[x].size(); y++) {
			int x1 = x + cam.x;
			int y1 = y + cam.y;
			while (x1 < 0) {
				x1 += width;
			}
			while (x1 > width - 1) {
				x1 -= width;
			}
			while (y1 < 0) {
				y1 += height;
			}
			while (y1 > height - 1) {
				y1 -= height;
			}
			if (sys.map[x1][y1].state) {
				int s = sys.map[x1][y1].state;
				int p = sys.map[x1][y1].power;
				if (mode) {
					int ageLimit = sys.ageLimit;
					if (sys.ageLimit == 0) {
						ageLimit = 1;
					}
					p = (double)sys.map[x1][y1].age/(double)ageLimit*255;
				}
				Color c = stateColors[s - 1];
				if (p > 255) {
					p = 255;
				}
				c.a = 100;
				//if(!mode)
				draw.drawFillRect(x*size, y*size, size, size, c);
				draw.drawFillRect(x*size, y*size, size, size, Color(c.r, c.g, c.b, p));

			}
		}
	}
	draw.push();
}


