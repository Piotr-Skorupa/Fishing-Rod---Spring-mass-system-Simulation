#pragma once
#include "ofMain.h"

class Point
{
	ofVec3f position;
public:

	Point();
	Point(ofVec3f x);
	Point(float x, float y, float z);
	~Point();

	ofVec3f pos();
	ofVec3f operator+ (Point that);
};

