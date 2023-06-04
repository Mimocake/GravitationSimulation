#include "GravitationSimulation.hpp"
using namespace sf;

int main()
{
    sf::ContextSettings settings;
    settings.antialiasingLevel = 6;
    sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(2400, 1300), "Gravitation", sf::Style::Default, settings);
    Planet planets[5];
    planets[0] = Planet(2, sf::Color::Blue, sf::Vector2f(1200, 650), sf::Vector2f(0.00, 0.0002), 20);
    planets[1] = Planet(2, sf::Color::Green, sf::Vector2f(1100, 650), sf::Vector2f(0.00, -0.15), 5);
    planets[2] = Planet(2, sf::Color::Yellow, sf::Vector2f(1000, 650), sf::Vector2f(0.0, 0.43), 1);
    planets[3] = Planet(2, sf::Color::Red, sf::Vector2f(850, 650), sf::Vector2f(0.0, 0.26), 1);
    planets[4] = Planet(2, sf::Color(127, 127, 127), sf::Vector2f(850, 630), sf::Vector2f(0.0, -0.30), 0.01);
    Universe universe(5);
    universe.set_planets(planets);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }
        universe.calc_accel();
        universe.move_planets();
        universe.draw_planets(window);
        window->display();
    }
    return 0;
}