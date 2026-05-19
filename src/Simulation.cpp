#include "Simulation.h"

/** @copydoc Simulation::Simulation(float width, float height, sf::RenderWindow &window)  */
Simulation::Simulation(float width, float height, sf::RenderWindow &window) : worldWidth(width), worldHeight(height)
{
    systems.push_back(std::make_unique<IntegrationSystem>(width, height));
    systems.push_back(std::make_unique<SpatialSystem>(width, height, 50.0f));
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
        if (kinematics.velocity.x != 0.0f || kinematics.velocity.y != 0.0f)
        {
            float radians = std::atan2(kinematics.velocity.y, kinematics.velocity.x);

            float degrees = radians * (180.0f / 3.14159265f);
            render.body.setRotation(sf::degrees(degrees));
        }

        window.draw(render.body);

        sf::Vertex line[] = {
            {kinematics.position, sf::Color::Red},
            {kinematics.position + kinematics.acceleration * 0.5f, sf::Color::Red}};

        window.draw(line, 2, sf::PrimitiveType::Lines);
    }
}

void Simulation::addSingleBoidTest()
{
    auto testBoid = std::make_shared<Boid>();

    testBoid->kinematics.position = sf::Vector2f(worldWidth / 2.0f, worldHeight / 2.0f);
    testBoid->kinematics.velocity = sf::Vector2f(-50.0f, 10.0f);

    testBoid->settings.maxSpeed = 10.0f;

    objects.push_back(testBoid);
}

void Simulation::addTwoBoidsTest()
{
    auto boid1 = std::make_shared<Boid>();
    boid1->kinematics.position = sf::Vector2f(100.0f, 100.0f);
    boid1->kinematics.velocity = sf::Vector2f(10.0f, 0.0f);
    boid1->settings.perceptionRadius = 50.0f;
    boid1->behavior.separationWeight = 1.5f;
    boid1->behavior.alignmentWeight = 0.0f;
    boid1->behavior.cohesionWeight = 0.0f;
    objects.push_back(boid1);

    auto boid2 = std::make_shared<Boid>();
    boid2->kinematics.position = sf::Vector2f(110.0f, 100.0f);
    boid2->kinematics.velocity = sf::Vector2f(-10.0f, 0.0f);
    boid2->settings.perceptionRadius = 50.0f;
    boid2->behavior.separationWeight = 1.5f;
    boid2->behavior.alignmentWeight = 0.0f;
    boid2->behavior.cohesionWeight = 0.0f;
    objects.push_back(boid2);
}
