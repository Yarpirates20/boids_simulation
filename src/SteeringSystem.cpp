#include "SteeringSystem.h"

/** @copydoc SteeringSystem::separation(const std::shared_ptr<SimObject> &boid, const std::vector<std::shared_ptr<SimObject>> &neighbors) */
sf::Vector2f SteeringSystem::separation(const std::shared_ptr<SimObject> &boid, const std::vector<std::shared_ptr<SimObject>> &neighbors)
{
    auto steeringVector = sf::Vector2f{0.0f, 0.0f};
    int violatingNeighborsCount = 0;

    for (const auto &neighbor : neighbors)
    {
        if (neighbor == boid)
        {
            continue;
        }

        auto diff = boid->kinematics.position - neighbor->kinematics.position;
        auto distance = diff.length();

        if (distance > 0 && distance < boid->settings.desiredSeparation)
        {
            auto normalizedDir = diff / distance;

            auto pushVector = normalizedDir / distance;

            steeringVector += pushVector;

            ++violatingNeighborsCount;
        }
    }

    // Finalize Steering Force
    if (violatingNeighborsCount == 0)
    {
        return sf::Vector2f{0.0f, 0.0f};
    }

    // Average accumulated push vectors
    steeringVector /= static_cast<float>(violatingNeighborsCount);

    // Reynold's Steering --> Desired Velocity - Current Velocity
    // Normalize the avg vector and scale to max speed
    auto desiredVelocity = steeringVector.normalized() * boid->settings.maxSpeed;
    auto steeringForce = desiredVelocity - boid->kinematics.velocity;

    // Clamp final force so it does not exceed maxForce capacity
    if (steeringForce.length() > boid->settings.maxForce)
    {
        steeringForce = steeringForce.normalized() * boid->settings.maxForce;
    }

    return steeringForce;
}

/** @copydoc SteeringSystem::alignment(const std::shared_ptr<SimObject> &boid, const std::vector<std::shared_ptr<SimObject>> &neighbors) */
sf::Vector2f SteeringSystem::alignment(const std::shared_ptr<SimObject> &boid, const std::vector<std::shared_ptr<SimObject>> &neighbors)
{
    sf::Vector2f averageVelocity{0.0f, 0.0f};
    int validNeighbors = 0;

    for (const auto &neighbor : neighbors)
    {
        if (neighbor == boid)
        {
            continue;
        }

        averageVelocity += neighbor->kinematics.velocity;
        ++validNeighbors;
    }

    if (validNeighbors > 0)
    {
        averageVelocity /= static_cast<float>(validNeighbors);

        if (averageVelocity.x != 0.0f || averageVelocity.y != 0.0f)
        {

            auto desiredVelocity = averageVelocity.normalized() * boid->settings.maxSpeed;
            auto steeringForce = desiredVelocity - boid->kinematics.velocity;

            // Clamp
            if (steeringForce.length() > boid->settings.maxForce)
            {
                steeringForce = steeringForce.normalized() * boid->settings.maxForce;
            }

            return steeringForce;
        }
    }

    return sf::Vector2f{0.0f, 0.0f};
}

/** @copydoc SteeringSystem::cohesion(const std::shared_ptr<SimObject> &boid, const std::vector<std::shared_ptr<SimObject>> &neighbors) */
sf::Vector2f SteeringSystem::cohesion(const std::shared_ptr<SimObject> &boid, const std::vector<std::shared_ptr<SimObject>> &neighbors)
{
    sf::Vector2f averagePosition{0.0f, 0.0f};
    int validNeighbors = 0;

    for (const auto &neighbor : neighbors)
    {
        if (neighbor == boid)
        {
            continue;
        }

        averagePosition += neighbor->kinematics.position;
        ++validNeighbors;
    }

    if (validNeighbors > 0)
    {
        averagePosition /= static_cast<float>(validNeighbors);
        auto targetVector = averagePosition - boid->kinematics.position;

        if (targetVector.x != 0.0f || targetVector.y != 0.0f)
        {
            // Reynolds Steering Calculation
            auto desiredVelocity = targetVector.normalized() * boid->settings.maxSpeed;
            auto steeringForce = desiredVelocity - boid->kinematics.velocity;

            // Clamp
            if (steeringForce.length() > boid->settings.maxForce)
            {
                steeringForce = steeringForce.normalized() * boid->settings.maxForce;
            }

            return steeringForce;
        }
    }

    return sf::Vector2f{0.0f, 0.0f};
}

/** @copydoc SteeringSystem::SteeringSystem(SpatialSystem &spatial) */
SteeringSystem::SteeringSystem(SpatialSystem &spatial) : m_spatialSystem(spatial)
{
}

/** @copydoc SteeringSystem::update(std::vector<std::shared_ptr<SimObject>> &objects, float dt) */
void SteeringSystem::update(std::vector<std::shared_ptr<SimObject>> &objects, float dt)
{
    for (auto &obj : objects)
    {
        // Get neighbors from spatial system
        auto neighbors = m_spatialSystem.getNeighbors(obj->kinematics.position);

        // Calculate individual forces
        sf::Vector2f sep = separation(obj, neighbors) * m_separationWeight;
        sf::Vector2f align = alignment(obj, neighbors) * m_alignmentWeight;
        sf::Vector2f coh = cohesion(obj, neighbors) * m_cohesionWeight;

        // Accumulate into acceleration (resetting last frame's force)
        obj->kinematics.acceleration = sep + align + coh;
    }
}
