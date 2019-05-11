#pragma once
#include "Vector2d.h"

class Cell{
public:
	int neighbors = 0;

	int state = 0;
	int power = 0;
	int resourses = 1;
	Vector2d chance;
	long long age = 0;
	Vector2d hardness;
	Cell();
	~Cell();
};

