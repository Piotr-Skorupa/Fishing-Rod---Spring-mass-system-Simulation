#include "Spring.h"



Spring::Spring()
{
	is_vein = false;
	position_begin = ofVec3f(0.0, 0.0, 0.0);
	position_end = ofVec3f(100.0,130.0, 100.0);
	start_position_begin = position_begin;
	start_position_end = position_end;
	spring_color = ofColor(255,185,0); 
	length = calculate_length();
	start_length = length;

	

	
}


Spring::Spring(Point first, Point second) 
{
	position_begin = first.pos();
	position_end = second.pos();
	start_position_begin = position_begin;
	start_position_end = position_end;
	spring_color = ofColor(255, 185, 0);
	length = calculate_length();
	start_length = length;
	
}

Spring::Spring(Point* first, Point * second)
{
	position_begin = first->pos();
	position_end = second->pos();
	start_position_begin = position_begin;
	start_position_end = position_end;
	spring_color = ofColor(255, 185, 0);
	length = calculate_length();
	start_length = length;

}

Spring::~Spring()
{

}

void Spring::draw()
{
	ofSetColor(spring_color);
	ofFill();

	if (is_vein == true) {
		ofSetLineWidth(1); 
	}
	else ofSetLineWidth(8);
	
	ofDrawLine(position_begin, position_end);
	ofNoFill();
}

void Spring::change_color(bool _if)
{
	switch (_if)
	{
	case true:
		spring_color = ofColor(160, 160, 160);     //color of fishing vein
		is_vein = true;
		break;
	case false:
		spring_color = ofColor(255, 185, 0);       // color of rod (wood)
		is_vein = false;
		break;
	}

}


void Spring::update_position(Point first, Point second)
{
	position_begin = first.pos();
	position_end = second.pos();
}

void Spring::update_position(ofVec3f first, ofVec3f second)
{
	position_begin = first;
	position_end = second;
}



float Spring::calculate_length()
{
	return position_begin.distance(position_end);
}

float Spring::get_length()
{
	return length;
}