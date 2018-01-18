#pragma once
#include "ofMain.h"

class Point
{
	ofVec3f position;
	ofVec3f velocity;
	ofVec3f force; //sila po angielsku ?
	bool is_moving;
	float dt;

public:

	Point();
	Point(ofVec3f x);
	Point(float x, float y, float z);
	~Point();

	ofVec3f pos();
	ofVec3f operator+ (Point that);
	void update_euler_method();
};

