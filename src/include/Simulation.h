#ifndef SIMULATION_H
#define SIMULATION_H

#include "SimObject.h"
#include "Boid.h"
#include "ISystem.h"
#include "IntegrationSystem.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>

class Simulation
{
    private:
        std::vector<std::shared_ptr<SimObject>> objects;
        std::vector<std::unique_ptr<ISystem>> systems;
        float worldWidth;
        float worldHeight;

    public:
        /**
         * @brief Construct a new Simulation object.
         * 
         * @param width Window width.
         * @param height Window height.
         * @param window Reference to sf::RenderWindowS
         */
        Simulation(float width, float height, sf::RenderWindow &window);

        /**
         * @brief Destroy the Simulation object
         * 
         */
        ~Simulation();

        /**
         * @brief Manages the order in which Systems process data
         * 
         * @param deltaTime Processing time for a single frame
         */
        void update(float deltaTime);
        
        // void render();
        
        // void addBoid();

        /**
         * @brief Get the Objects vector.
         * 
         * @return const std::vector<std::shared_ptr<SimObject>>& Const vector of SimObjects.
         */
        const std::vector<std::shared_ptr<SimObject>>& getObjects() const { return objects; }

        void addSingleBoidTest();

};

#endif // SIMULATION_H