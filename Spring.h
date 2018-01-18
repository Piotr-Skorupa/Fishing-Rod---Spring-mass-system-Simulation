#pragma once
#include "ofMain.h"
#include "Point.h"

class Spring
{
	ofVec3f position_begin;
	ofVec3f position_end;
	float length, start_length;
	ofVec3f start_position_begin; //natural starting position of material
	ofVec3f start_position_end;   //
	ofColor spring_color;
	bool is_vein;   // czy zylka czy wedka ? -> potrzebne do rysowania

public:
	Spring();
	Spring(Point first, Point second);
	~Spring();
	void draw();
	void tensioning(ofVec3f vec);
	void change_color(bool _if);
	void update_position(Point first, Point second);
	void update_position(ofVec3f first, ofVec3f second);
	float calculate_length();
};

