#include "Simulation.h"

/** @copydoc Simulation::Simulation(float width, float height, sf::RenderWindow &window)  */
Simulation::Simulation(float width, float height, sf::RenderWindow &window) : worldWidth(width), worldHeight(height)
{
    systems.push_back(std::make_unique<IntegrationSystem>(width, height));
}

/** @copydoc Simulation::~Simulation() */
Simulation::~Simulation()
{
}

/** @copydoc Simulation::update(float deltaTime) */
void Simulation::update(float deltaTime)
{
    for (auto &&sys : systems)
    {
        sys->update(objects, 1.0f);
    }
    
}

void Simulation::addSingleBoidTest()
{
    auto testBoid = std::make_shared<Boid>();

    testBoid->kinematics.position = sf::Vector2f(worldWidth / 2.0f, worldHeight / 2.0f);
    testBoid->kinematics.velocity = sf::Vector2f(100.0f, 50.0f);

    testBoid->settings.maxSpeed = 200.0f;

    objects.push_back(testBoid);
}
