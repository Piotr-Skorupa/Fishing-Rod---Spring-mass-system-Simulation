#include "Fish.h"



Fish::Fish()
{
	mass = 20.0;
}


Fish::~Fish()
{
}

void Fish::load_model(std::string path, Point p)
{
	model.loadModel(path, 20);
	model.setScale(0.15, 0.15, 0.15);
	model.setRotation(0, 90, 1, 0, 0);  // rotation is difficult
	//model.setRotation(1, 90, 0, 1, 0); 
	model.setRotation(2, 45, 0, 0, 1);
	model.setPosition(p.pos().x, p.pos().y, p.pos().z);
}

void Fish::draw()
{
	model.drawFaces();
}

void Fish::set_mass(float _mass)
{
	mass = _mass;
}
float Fish::get_mass()
{
	return mass;
}