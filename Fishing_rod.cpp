#include "Fishing_rod.h"



Fishing_rod::Fishing_rod()
{
	counter = 0;
	// points for rod
	for (auto i = 0; i < LENGTH_OF_ROD; i += 25)
	{
		points.push_back(Point(i, i, i));
	}
	// pointers to points for rod --> this will simplify drwing of rod
	for (auto i = 0; i < points.size(); i ++)
	{
		if (i == 0) {
			Point * p = &points[i];
			starting_points.push_back(std::move(p));
		}
		else if (i == 7) {
			Point * p = &points[i];
			ending_points.push_back(std::move(p));
		}
		else {
			Point * p = &points[i];
			Point * p1 = &points[i];
			starting_points.push_back(std::move(p));
			ending_points.push_back(std::move(p1));
		}
	}
	
	// buliding rod with springs
	for (auto i = 0; i < ending_points.size(); i++) {
		lines.push_back(Spring(starting_points[i], ending_points[i]));
	}
	

	//creating points for fishing vein
	Point end_of_rod = *ending_points.back();
	Point middle_of_vein = end_of_rod + Point(0.0, -25.0, 0.0);
	Point middle_of_vein2 = end_of_rod + Point(0.0, -50.0, 0.0);
	Point middle_of_vein3 = end_of_rod + Point(0.0, -75.0, 0.0);
	Point middle_of_vein4 = end_of_rod + Point(0.0, -100.0, 0.0);
	Point middle_of_vein5 = end_of_rod + Point(0.0, -125.0, 0.0);
	Point end_of_vein = end_of_rod + Point(0.0, -150.0, 0.0);
	// pushing points to std::vector
	points_for_vein.push_back(end_of_rod);
	points_for_vein.push_back(middle_of_vein);
	points_for_vein.push_back(middle_of_vein2);
	points_for_vein.push_back(middle_of_vein3);
	points_for_vein.push_back(middle_of_vein4);
	points_for_vein.push_back(middle_of_vein5);
	points_for_vein.push_back(end_of_vein);

	// creating Springs for vein
	vein.push_back(Spring(points_for_vein[0], points_for_vein[1]));
	vein.push_back(Spring(points_for_vein[1], points_for_vein[2]));
	vein.push_back(Spring(points_for_vein[2], points_for_vein[3]));
	vein.push_back(Spring(points_for_vein[3], points_for_vein[4]));
	vein.push_back(Spring(points_for_vein[4], points_for_vein[5]));
	vein.push_back(Spring(points_for_vein[5], points_for_vein[6]));

	for (auto &v : vein) {
		v.change_color(true);
	}
	
	for (auto &p : ending_points)
	{
		p->set_movement(false);
	}
	for (auto &p : starting_points)
	{
		p->set_movement(false);
	}
	
	points.back().set_mass(100.0);
	points_for_vein[0].set_movement(false);
	for (auto i = 1; i < points_for_vein.size(); i++)
	{
		points_for_vein[i].set_movement(true);
	}
	
	
}




Fishing_rod::~Fishing_rod()
{
}

void Fishing_rod::draw() {

	for (auto &l : lines) {
		l.draw();
	}
	
	for (auto &v : vein) {
		v.draw();
	}
	
}

Point Fishing_rod::get_hook_point()
{
	return points_for_vein.back();
}

void Fishing_rod::update_tension(Fish &fish)
{
	
	this->refresh_pointers();
	
	std::cout << points.back().pos().x << std::endl;
	
	for (auto &p : points_for_vein) {
		p.set_mass(fish.get_mass());
	}
	// gravity
	for (auto &p : points_for_vein) {
		ofVec3f gravity_force = { 0, -p.get_mass()*G, 0 };
		p.set_gravity_force(gravity_force);
		//p.set_forces_to_zero();
	}

	for (auto i = 0; i < vein.size(); i++) {
		float distance = points_for_vein[i].pos().distance(points_for_vein[i + 1].pos());

		if (distance != 0)
		{
			points_for_vein[i].set_velocity();
			points_for_vein[i + 1].set_velocity();

			ofVec3f diff_v = points_for_vein[i].get_v() - points_for_vein[i + 1].get_v();
			ofVec3f diff_pos = points_for_vein[i].pos() - points_for_vein[i + 1].pos();

			//sily
			ofVec3f f = (distance - vein[i].get_length()) * KS + (diff_v * diff_pos) * KD / distance;
			ofVec3f F = f * (diff_pos / distance);

			points_for_vein[i].set_force(-F);
			points_for_vein[i + 1].set_force(F);

		}
	}
		if (counter < 2) {
			for (auto &p : points_for_vein)
				p.update_euler_method();
			counter++;
		}
		else
		{
			for (auto &p : points_for_vein)
				p.update_verlet_method();
		}


	/*
	for (auto i = 0; i < ending_points.size(); i++) {

		std::cout << i << " s "<< starting_points[i]->pos().x << " " << starting_points[i]->pos().y << " " << starting_points[i]->pos().z << std::endl;
		std::cout << i << " e " << ending_points[i]->pos().x << " " << ending_points[i]->pos().y << " " << ending_points[i]->pos().z << std::endl;
	}
	*/

	this->update();
	fish.update_pos(points_for_vein.back());
}


void Fishing_rod::update() 
{
	this->refresh_pointers();

	//updating rod
	points_for_vein.front() = points.back();
	
	for (auto i = 0; i < lines.size(); i++) {
		lines[i].update_position(*starting_points[i], *ending_points[i]);
	}
	//updating vein
	for (auto i = 0; i < vein.size(); i++) {
		vein[i].update_position(points_for_vein[i], points_for_vein[i + 1]);
	}	
}


void Fishing_rod::tension()
{
	this->refresh_pointers();

	points_for_vein.back() = points_for_vein.back() + Point(0.0, -50.0, 0.0);
	points_for_vein.back().set_movement(true);
}

void Fishing_rod::refresh_pointers() 
{
	starting_points.clear();
	ending_points.clear();

	for (auto i = 0; i < points.size(); i++)
	{
		if (i == 0) {
			Point * p = &points[i];
			starting_points.push_back(std::move(p));
		}
		else if (i == 7) {
			Point * p = &points[i];
			ending_points.push_back(std::move(p));
		}
		else {
			Point * p = &points[i];
			Point * p1 = &points[i];
			starting_points.push_back(std::move(p));
			ending_points.push_back(std::move(p1));
		}
	}
}

void Fishing_rod::move_right()
{
	if (points.back().pos().x < 300) {
		for (auto &p : points) {
			p.move(ofVec3f(10, 0, 0));
		}
	}
}

void Fishing_rod::move_left()
{
	if (points.back().pos().x > -300) {
		for (auto &p : points) {
			p.move(ofVec3f(-10, 0, 0));
		}
	}
}