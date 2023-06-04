#include "GravitationSimulation.hpp"

sf::Vector2f Sec_New_Law(sf::Vector2f F, float m) { return F / m; }

sf::Vector2f Law_of_Univ_Grav(Planet p1, Planet p2, float, float)
{
	Vector2f dir = p2.get_position() - p1.get_position();
	float r = sqrt(dir.x * dir.x + dir.y * dir.y);
	dir.x /= r; dir.y /= r;
	sf::Vector2f acceleraion = Sec_New_Law(dir * ((p1.get_mass() * p2.get_mass()) / (r * r)), p1.get_mass());
	return acceleraion;
}
