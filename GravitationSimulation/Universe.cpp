#include "GravitationSimulation.hpp"

Universe::Universe(int n)
{
	num = n;
	planets = new Planet[n];
	for (int i = 0; i < n; i++)
	{
		planets[i] = Planet(0, sf::Color::Black, sf::Vector2f(0, 0), sf::Vector2f(0, 0), 0);
		planets[i].actual_planet.setRadius(0);
		planets[i].actual_planet.setOrigin(0, 0);
		planets[i].actual_planet.setFillColor(sf::Color::Black);
	}

}

void Universe::set_planets(Planet* arr)
{
	for (int i = 0; i < num; i++)
	{
		planets[i] = arr[i];
		planets[i].actual_planet.setRadius(arr[i].get_size());
		planets[i].actual_planet.setOrigin(arr[i].get_size(), arr[i].get_size());
		planets[i].actual_planet.setFillColor(arr[i].get_color());
		planets[i].actual_planet.setPosition(arr[i].get_position());
	}
}

void Universe::calc_accel()
{
	for (int i = 0; i < num; i++)
	{
		planets[i].accel = sf::Vector2f(0, 0);
		for (int j = 0; j < num; j++)
		{
			if (i != j)
			{
				planets[i].accel += Law_of_Univ_Grav(planets[i], planets[j], planets[i].mass, planets[j].mass);
			}
			else continue;
		}
	}
}

void Universe::move_planets()
{
	for (int i = 0; i < num; i++)
	{
		planets[i].move_planet();
	}
}

void Universe::draw_planets(sf::RenderWindow* window)
{
	for (int i = 0; i < num; i++)
	{
		planets[i].draw_planet(window);
	}
}
