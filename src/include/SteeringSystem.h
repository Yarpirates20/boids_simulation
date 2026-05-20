#ifndef STEERINGSYSTEM_H
#define STEERINGSYSTEM_H

#include "ISystem.h"
#include "SpatialSystem.h"
#include "SimObject.h"

#include <vector>
#include <memory>

class SteeringSystem : public ISystem
{
private:
    SpatialSystem &m_spatialSystem;

    // Core flocking weights
    float m_separationWeight = 1.5f;
    float m_alignmentWeight = 1.0f;
    float m_cohesionWeight = 1.0f;

    /**
     * @brief Prevents boids from crowding or crashing into each other.
     * 
     * @param boid Individual boid to calculate. 
     * @param neighbors The boid's neighbors in the grid.
     * @return sf::Vector2f Average steering force vector.
     */
    sf::Vector2f separation(const std::shared_ptr<SimObject> &boid, const std::vector<std::shared_ptr<SimObject>> &neighbors);

    /**
     * @brief Makes boids travel in the same general direction as the group.
     * 
     * @param boid Individual boid to calculate alignment for.
     * @param neighbors The nearby boids in the grid.
     * @return sf::Vector2f Average velocity vector. 
     */
    sf::Vector2f alignment(const std::shared_ptr<SimObject> &boid, const std::vector<std::shared_ptr<SimObject>> &neighbors);

    /**
     * @brief Keeps the flock from scattering into isolated units by pulling
     * them toward each other.
     * 
     * @param boid The current boid to check.
     * @param neighbors The current boid's neighbors.
     * @return sf::Vector2f The group's center of mass.
     */
    sf::Vector2f cohesion(const std::shared_ptr<SimObject> &boid, const std::vector<std::shared_ptr<SimObject>> &neighbors);


    

public:
    /**
     * @brief Construct a new Steering System object.
     * 
     * @param spatial SpatialSystem for neighborhood queries.
     */
    SteeringSystem(SpatialSystem &spatial);

    /**
     * @brief Gathers forces and modify's boid's raw acceleration component.
     * 
     * @param objects List of SimObjects.
     * @param dt Delta time.
     */
    void update(std::vector<std::shared_ptr<SimObject>> &objects, float dt) override;       
};

#endif // STEERINGSYSTEM_H