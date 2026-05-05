#include "Simulation.h"

/** @copydoc Simulation::Simulation() */
Simulation::Simulation()
{
    window = new sf::RenderWindow(sf::VideoMode({1775, 976}), "Boids Attack!");
}

/** @copydoc Simulation::~Simulation() */
Simulation::~Simulation()
{
    while (window->isOpen())
    {
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
            else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window->close();
                }
            }
        }
    }
}

/** @copydoc Simulation::run() */
void Simulation::run()
{
}
