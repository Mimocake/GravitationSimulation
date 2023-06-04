#include <SFML/Graphics.hpp>
#include <iostream>
#include <Windows.h>
#include <math.h>
#include <vector>
using namespace sf;
using namespace std;

class Planet
{
private:
	sf::CircleShape actual_planet;
	sf::Vector2f vel;
	sf::Vector2f position;
	sf::Vector2f accel;
	float mass;
public:
	friend class Universe;
	Planet();
	Planet(int size, sf::Color color, sf::Vector2f pos , sf::Vector2f vel, float m);
	void set_accel(sf::Vector2f);
	void set_position(sf::Vector2f);
	sf::Vector2f get_position();
	int get_size();
	sf::Color get_color();
	float get_mass();

	void move_planet();
	void draw_planet(sf::RenderWindow*);
};

class Universe
{
private: 
	Planet* planets;
	int num;
public:
	friend Planet;
	Universe(int);
	void set_planets(Planet*);
	void calc_accel();
	void move_planets();
	void draw_planets(sf::RenderWindow*);
};

sf::Vector2f Sec_New_Law(sf::Vector2f, float);
sf::Vector2f Law_of_Univ_Grav(Planet, Planet, float, float);
