#include "Spring.h"



Spring::Spring()
{
	is_vein = false;
	position_begin = ofVec3f(0.0, 0.0, 0.0);
	position_end = ofVec3f(100.0,130.0, 100.0);
	start_position_begin = position_begin;
	start_position_end = position_end;
	spring_color = ofColor(255,185,0); 
}


Spring::~Spring()
{
}

Spring::Spring(Point first, Point second) 
{
	position_begin = first.pos();
	position_end = second.pos();
	start_position_begin = position_begin;
	start_position_end = position_end;
	spring_color = ofColor(255, 185, 0);
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
		spring_color = ofColor(160, 160, 160);     //kolor zylki
		is_vein = true;
		break;
	case false:
		spring_color = ofColor(255, 185, 0);       // powrot do koloru pierwotnego (wedzisko)
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


void Spring::tensioning(ofVec3f vec)
{
	position_end += vec;
	position_begin += vec;
}


