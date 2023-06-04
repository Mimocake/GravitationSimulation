#include "GravitationSimulation.hpp"

Planet::Planet()
{
	actual_planet.setRadius(0);
	actual_planet.setOrigin(0, 0);
	actual_planet.setFillColor(sf::Color::Black);
	position = sf::Vector2f(0, 0);
	vel = sf::Vector2f(0, 0);
	this->mass = 0;
}

Planet::Planet(int size, sf::Color col, sf::Vector2f pos, sf::Vector2f veloc, float mass)
{
	actual_planet.setRadius(size);
	actual_planet.setOrigin(size, size);
	actual_planet.setFillColor(col);
	position = pos;
	vel = veloc;
	this->mass = mass;
}

void Planet::set_accel(sf::Vector2f acc) { accel = acc; }

void Planet::set_position(sf::Vector2f pos)
{
	actual_planet.setPosition(pos);
	position = pos;
}

sf::Vector2f Planet::get_position() { return position; }

float Planet::get_mass() { return mass; }

int Planet::get_size() { return actual_planet.getRadius(); }

sf::Color Planet::get_color() { return actual_planet.getFillColor(); }

void Planet::move_planet()
{
	vel += accel;
	position += vel;
	actual_planet.move(vel);
}

void Planet::draw_planet(sf::RenderWindow* window) { window->draw(actual_planet); }
