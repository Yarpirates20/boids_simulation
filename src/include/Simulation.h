#ifndef SIMULATION_H
#define SIMULATION_H

#include "SimObject.h"
#include "Boid.h"
#include "ISystem.h"
#include "IntegrationSystem.h"
#include "SpatialSystem.h"

#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <cmath>

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
        
        /**
         * @brief Translates abstract velocities of SimObjects
         * into visual pixels to draw in the window.
         * 
         * @param window 
         */
        void render(sf::RenderWindow &window);
        
        // void addBoid();

        /**
         * @brief Get the Objects vector.
         * 
         * @return const std::vector<std::shared_ptr<SimObject>>& Const vector of SimObjects.
         */
        const std::vector<std::shared_ptr<SimObject>>& getObjects() const { return objects; }

        void addSingleBoidTest();

        void addTwoBoidsTest();

};

#endif // SIMULATION_H