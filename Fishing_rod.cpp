#include "Fishing_rod.h"



Fishing_rod::Fishing_rod()
{
	counter = 0;
	for (auto i = 0; i < LENGTH_OF_ROD; i += 25)
	{
		points.push_back(Point(i, i, i));
	}
	
	
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
	std::cout <<points.size() << std::endl;
	
	for (auto i = 0; i < ending_points.size(); i++) {
		lines.push_back(Spring(starting_points[i], ending_points[i]));
	}

	//tworzenie handlerow

	handling_point = *starting_points[0] + Point(0.0, -50.0, 0.0);
	handlers.emplace_back(Spring(handling_point, *starting_points[0]));
	for (auto i = points.begin(); i != points.end(); i++)
	{
		handlers.emplace_back(Spring(handling_point, *i));
	}

	//koniec wedki i koniec zylki
	end_of_rod = *ending_points.back();
	end_of_vein = end_of_rod + Point(0.0, -150.0, 0.0);
	// utworzenie zylki
	vein = Spring(end_of_rod, end_of_vein);
	vein.change_color(true);
	std::cout << ending_points.size() << ", " << starting_points.size();
	
	for (auto &p : ending_points)
	{
		p->set_movement(true);
	}
	for (auto &p : starting_points)
	{
		p->set_movement(true);
	}
	starting_points[0]->set_movement(false); // pierwszy punkt nieruchomy

	
}




Fishing_rod::~Fishing_rod()
{
}

void Fishing_rod::draw() {

	for (auto &l : lines) {
		l.draw();
	}
	for (auto &l : handlers) {
		l.change_color(true);
		l.draw();
	}
	vein.draw();
}

Point Fishing_rod::get_hook_point()
{
	return end_of_vein;
}

void Fishing_rod::update_tension(Fish &fish)
{
	this->refresh_pointers();

	for (auto i = 0; i < ending_points.size(); i++) {
		
		for (auto i = 0; i < ending_points.size(); i++) {
			starting_points[i]->set_forces_to_zero();
			ending_points[i]->set_forces_to_zero();
		}


		float distance = starting_points[i]->pos().distance(ending_points[i]->pos());
		if (distance != 0)
		{

				starting_points[i]->set_velocity();
				ending_points[i]->set_velocity();
				ofVec3f diff_v = starting_points[i]->get_v() - ending_points[i]->get_v();
				ofVec3f diff_pos = starting_points[i]->pos() - ending_points[i]->pos();
				
				//sily
				ofVec3f f = (distance - lines[i].get_length()) * KS + (diff_v * diff_pos) * KD / distance;
				ofVec3f F = f * (diff_pos / distance);
				ofVec3f F2 = F * (-1, -1, -1);

				starting_points[i]->set_force(-F);
				ending_points[i]->set_force(F);
				
				
		}

		if (counter < 2) {
			starting_points[i]->update_euler_method();
			ending_points[i]->update_euler_method();
			counter++;
		}
		else
		{
			starting_points[i]->update_verlet_method();
			ending_points[i]->update_verlet_method();
		}

			
	}

	
	for (auto i = 0; i < ending_points.size(); i++) {

		std::cout << i << " s "<< starting_points[i]->pos().x << " " << starting_points[i]->pos().y << " " << starting_points[i]->pos().z << std::endl;
		std::cout << i << " e " << ending_points[i]->pos().x << " " << ending_points[i]->pos().y << " " << ending_points[i]->pos().z << std::endl;
	}


	for (auto &h : handlers) {
		float distance = h.calculate_length();
		//std::cout << distance << std::endl;
	}


	this->update();
	fish.update_pos(end_of_vein);
}


void Fishing_rod::update() 
{
	this->refresh_pointers();

	//updating rod
	end_of_rod = *ending_points.back();
	end_of_vein = end_of_rod + Point(0.0, -150.0, 0.0);
	for (auto i = 0; i < lines.size(); i++) {
		lines[i].update_position(*starting_points[i], *ending_points[i]);
	}
	int j = 1;
	for (auto i = points.begin(); i != points.end(); i++)
	{
		handlers[j++].update_position(handling_point, *i);
	}
	vein.update_position(end_of_rod, end_of_vein);
}


void Fishing_rod::tension()
{
	this->refresh_pointers();

	*ending_points.back() =  end_of_rod + Point(0.0, -100.0, 0.0);
	for (auto i = 0; i < ending_points.size(); i++) {

		std::cout << i << " s " << starting_points[i]->pos().x << " " << starting_points[i]->pos().y << " " << starting_points[i]->pos().z << std::endl;
		std::cout << i << " e " << ending_points[i]->pos().x << " " << ending_points[i]->pos().y << " " << ending_points[i]->pos().z << std::endl;
	}
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