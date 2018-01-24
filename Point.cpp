#include "Point.h"



Point::Point()
{
	position = ofVec3f(0, 0, 0);
	position_old = position;
	velocity = ofVec3f(0, 0, 0);
	force = ofVec3f(0, 0, 0);
	is_moving = false;
	dt = 0.025;
	mass = 1.0;
}

Point::Point(ofVec3f x)
{
	position = x;
	position_old = position;
	velocity = ofVec3f(0, 0, 0);
	force = ofVec3f(0, 0, 0);
	is_moving = false;
	dt = 0.025;
	mass = 1.0;
}

Point::Point(float x, float y, float z)
{
	position = ofVec3f(x, y, z);
	position_old = position;
	velocity = ofVec3f(0, 0, 0);
	force = ofVec3f(0, 0, 0);
	is_moving = false;
	dt = 0.025;
	mass = 1.0;
}

Point::~Point()
{

}

ofVec3f Point::pos() { return position; }

ofVec3f Point::operator+ (Point that)
{
	return position + that.pos();
}

void Point::change_position(ofVec3f change)
{
	position = change;
}

void Point::set_mass(float mass)
{
	this->mass = mass;
}

void Point::update_euler_method()
{
	
	if (is_moving)
	{
		velocity += force * dt;
		position_new = position + velocity * dt;
		position_old = position;
		position = position_new;
	}
}

void Point::update_verlet_method()
{
	
	if (is_moving)
	{
		position_new = 2 * position - position_old + (dt*dt*force / mass);
		position_old = position;
		position = position_new;
	}
}

void Point::set_force(ofVec3f f)
{
	force += f;
	
}

void Point::set_velocity()
{
	velocity = position - position_old;
}


void Point::set_movement(bool _move)
{
	is_moving = _move;
}

float Point::get_mass()
{
	return mass;
}

ofVec3f Point::get_v()
{
	return velocity;
}

ofVec3f Point::get_f()
{
	return force;
}

void Point::set_forces_to_zero()
{
	force = { 0,0,0 };
}

void Point::set_gravity_force(ofVec3f f)
{
	force = f;
}

void Point::move(ofVec3f m_vec)
{
	position = position + m_vec;
}