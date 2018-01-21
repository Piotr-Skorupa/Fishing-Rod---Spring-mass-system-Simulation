#pragma once
#include "ofxAssimpModelLoader.h"
#include "ofMain.h"
#include "Point.h"
#include <iostream>
#include <string>

class Fish
{
	ofxAssimpModelLoader model;
	float mass;
	Point p;
public:
	Fish();
	~Fish();
	void load_model(std::string path, Point p);
	void draw();
	void set_mass(float _mass);
	float get_mass();
	void update_pos(Point p);
};

