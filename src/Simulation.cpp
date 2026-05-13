#include "Simulation.h"

/** @copydoc Simulation::Simulation() */
/* Simulation::Simulation()
{
    // window = new sf::RenderWindow(sf::VideoMode({1775, 976}), "Boids Attack!");

    // window->setFramerateLimit(60);


} */

/** @copydoc Simulation::Simulation(float width, float height, sf::RenderWindow &window)  */
Simulation::Simulation(float width, float height, sf::RenderWindow &window)
{
    systems.push_back(std::make_unique<IntegrationSystem>(width, height));
}

/** @copydoc Simulation::~Simulation() */
Simulation::~Simulation()
{
}
