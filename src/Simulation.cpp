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

/** @copydoc Simulation::render(sf::RenderWindow &window) */
void Simulation::render(sf::RenderWindow &window)
{
    for (auto &obj : objects)
    {
        // Get components
        auto &kinematics = obj->kinematics;
        auto &render = obj->render;

        // Update shape's position
        render.body.setPosition(kinematics.position);

        // Update shape's rotation based on velocity
        // Only update rotation if the boid is actually moving
        if (kinematics.velocity.x != 0 || kinematics.velocity.y != 0)
        {
            float radians = std::atan2(kinematics.velocity.y, kinematics.velocity.x);

            float degrees = radians * (180.0f / M_PI);
            render.body.setRotation(sf::degrees(degrees));
        }

        window.draw(render.body);
    }
}

void Simulation::addSingleBoidTest()
{
    auto testBoid = std::make_shared<Boid>();

    testBoid->kinematics.position = sf::Vector2f(worldWidth / 2.0f, worldHeight / 2.0f);
    testBoid->kinematics.velocity = sf::Vector2f(100.0f, 50.0f);

    testBoid->settings.maxSpeed = 10.0f;

    objects.push_back(testBoid);
}
