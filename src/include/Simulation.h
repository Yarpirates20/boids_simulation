#ifndef SIMULATION_H
#define SIMULATION_H

#include "SimObject.h"
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

        void update(float deltaTime);
        
        // void render();
        
        // void addBoid();

        /**
         * @brief Get the Objects vector.
         * 
         * @return const std::vector<std::shared_ptr<SimObject>>& Const vector of SimObjects.
         */
        const std::vector<std::shared_ptr<SimObject>>& getObjects() const { return objects; }

};

#endif // SIMULATION_H