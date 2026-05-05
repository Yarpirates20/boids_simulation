#ifndef SIMULATION_H
#define SIMULATION_H

#include <SFML/Graphics.hpp>

class Simulation
{
    private:
        sf::RenderWindow *window;


    public:
        /**
         * @brief Construct a new Simulation object
         * 
         */
        Simulation();

        /**
         * @brief Destroy the Simulation object
         * 
         */
        ~Simulation();

        /**
         * @brief Runs the main simulation loop.
         * 
         */
        void run();
};

#endif // SIMULATION_H