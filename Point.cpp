#include "Point.h"



Point::Point()
{
	position = ofVec3f(0, 0, 0);
	velocity = ofVec3f(0, 0, 0);
	force = ofVec3f(0, 0, 0);
	is_moving = false;
	dt = 0.1;
}

Point::Point(ofVec3f x)
{
	position = x;
	velocity = ofVec3f(0, 0, 0);
	force = ofVec3f(0, 0, 0);
	is_moving = false;
	dt = 0.1;
}

Point::Point(float x, float y, float z)
{
	position = ofVec3f(x, y, z);
	velocity = ofVec3f(0, 0, 0);
	force = ofVec3f(0, 0, 0);
	is_moving = false;
	dt = 0.1;
}

Point::~Point()
{

}

ofVec3f Point::pos() { return position; }

ofVec3f Point::operator+ (Point that)
{
	return position + that.pos();
}

void Point::update_euler_method()
{
	// tutaj zaczac pisac eulera
}