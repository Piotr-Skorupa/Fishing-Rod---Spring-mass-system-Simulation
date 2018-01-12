#include "Point.h"



Point::Point()
{
	position = ofVec3f(0, 0, 0);
}


Point::~Point()
{
}

Point::Point(ofVec3f x)
{
	position = x;
}
Point::Point(float x, float y, float z)
{
	position = ofVec3f(x, y, z);
}

ofVec3f Point::pos() { return position; }

ofVec3f Point::operator+ (Point that)
{
	return position + that.pos();
}