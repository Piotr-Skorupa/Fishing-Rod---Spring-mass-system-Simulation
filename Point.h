#pragma once
#include "ofMain.h"

class Point
{
	ofVec3f position_old;
	ofVec3f position_new;
	ofVec3f position;
	ofVec3f velocity;
	ofVec3f force; //sila po angielsku ?
	bool is_moving;
	float dt;
	float mass;

public:

	Point();
	Point(ofVec3f x);
	Point(float x, float y, float z);
	~Point();

	ofVec3f pos();
	ofVec3f operator+ (Point that);
	void update_euler_method();
	void update_verlet_method();
	void change_position(ofVec3f change);
	void set_force(ofVec3f f);
	void set_gravity_force(ofVec3f f);
	void set_forces_to_zero();
	void set_velocity();
	void set_movement(bool _move);
	void set_mass(float mass);
	void move(ofVec3f m_vec);
	
	float get_mass();
	ofVec3f get_v();
	ofVec3f get_f();
};

