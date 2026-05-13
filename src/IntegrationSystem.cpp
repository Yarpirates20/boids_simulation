#include "IntegrationSystem.h"

/** @copydoc IntegrationSystem::update(std::vector<std::shared_ptr<SimObject>> &objects, float deltaTime) */
void IntegrationSystem::update(std::vector<std::shared_ptr<SimObject>> &objects, float deltaTime)
{
    for (auto &&i : objects)
    {
        i->kinematics.velocity += i->kinematics.acceleration * deltaTime;

        float speedSq = (i->kinematics.velocity.x * i->kinematics.velocity.x) + (i->kinematics.velocity.y * i->kinematics.velocity.y);

        if (speedSq > i->settings.maxSpeed * i->settings.maxSpeed)
        {
            float speed = std::sqrt(speedSq);

            if (speed != 0.0)
            {
                i->kinematics.velocity = (i->kinematics.velocity / speed) * i->settings.maxSpeed;
            }
        }

        i->kinematics.position += i->kinematics.velocity * deltaTime;
    }
}
