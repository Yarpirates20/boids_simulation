#include "IntegrationSystem.h"

/** @copydoc IntegrationSystem::update(std::vector<std::shared_ptr<SimObject>> &objects, float deltaTime) */
void IntegrationSystem::update(std::vector<std::shared_ptr<SimObject>> &objects, float deltaTime)
{
    for (auto &&i : objects)
    {
        // Update velocity
        i->kinematics.velocity += i->kinematics.acceleration * deltaTime;

        float speedSq = (i->kinematics.velocity.x * i->kinematics.velocity.x) + (i->kinematics.velocity.y * i->kinematics.velocity.y);

        // Clamp
        if (speedSq > i->settings.maxSpeed * i->settings.maxSpeed)
        {
            float speed = std::sqrt(speedSq);

            if (speed != 0.0)
            {
                i->kinematics.velocity = (i->kinematics.velocity / speed) * i->settings.maxSpeed;
            }
        }

        // Update position
        i->kinematics.position += i->kinematics.velocity * deltaTime;

        // Bounds checking
        if (i->kinematics.position.x > worldWidth)
        {
            i->kinematics.position.x = 0;
        }
        else if (i->kinematics.position.x < 0)
        {
            i->kinematics.position.x = worldWidth;
        }

        if (i->kinematics.position.y > worldHeight)
        {
            i->kinematics.position.y = 0;
        }
        else if (i->kinematics.position.y < worldHeight)
        {
            i->kinematics.position.y = worldHeight;
        }
        
        // Reset acceleration
        i->kinematics.acceleration = sf::Vector2f(0,0);

        
    }
}
