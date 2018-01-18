#include "Fishing_rod.h"



Fishing_rod::Fishing_rod()
{
	for (auto i = 0; i < LENGTH_OF_ROD; i += 25)
	{
		starting_points.push_back(Point(i, i, i));
		ending_points.push_back(Point(i + 25, i + 25, i + 25));
		std::cout << i << std::endl;
	}

	for (auto i = 0; i < starting_points.size(); i++) {
		lines.push_back(Spring(starting_points[i], ending_points[i]));
	}

	//tworzenie handlerow

	handling_point = starting_points[0] + Point(0.0, -50.0, 0.0);
	handlers.emplace_back(handling_point, starting_points[0]);
	for (auto i = ending_points.begin(); i != ending_points.end(); i++)
	{
		handlers.emplace_back(Spring(handling_point, *i));
	}

	//koniec wedki i koniec zylki
	end_of_rod = ending_points.back();
	end_of_vein = end_of_rod + Point(0.0, -150.0, 0.0);
	// utworzenie zylki
	vein = Spring(end_of_rod, end_of_vein);
	vein.change_color(true);
	std::cout << ending_points.size() << ", " << starting_points.size();
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