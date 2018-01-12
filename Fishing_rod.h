#pragma once
#include "Point.h"
#include "Spring.h"
#include "ofMain.h"
#include "Defs.h"
#include <iostream>
#include <vector>


class Fishing_rod
{
	Point end_of_rod;
	Point end_of_vein;
	Spring vein;
	std::vector<Point> starting_points;
	std::vector<Point> ending_points;
	std::vector<Spring> lines;
public:
	Fishing_rod();
	~Fishing_rod();
	Point get_hook_point();

	void draw();
};

