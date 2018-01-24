#pragma once
#include "Point.h"
#include "Spring.h"
#include "ofMain.h"
#include "Defs.h"
#include <iostream>
#include <vector>
#include "Fish.h"


class Fishing_rod
{
	
	
	std::vector<Point> points;
	std::vector<Point*> starting_points;
	std::vector<Point*> ending_points;
	std::vector<Point> points_for_vein;
	std::vector<Spring> lines;
	std::vector<Spring> vein;
						
	std::vector<Spring> handlers;			// springi do polaczenia handler_pointa z punktami
	int counter;
public:
	Fishing_rod();
	~Fishing_rod();
	Point get_hook_point();

	void draw();
	void update_tension(Fish &fish);
	void tension();
	void update();
	void refresh_pointers();
	void move_right();
	void move_left();
};

