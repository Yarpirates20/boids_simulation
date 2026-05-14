#ifndef APPLICATION_H
#define APPLICATION_H

#include <SFML/Graphics.hpp>
#include "Simulation.h"

class Application
{
    private:
        sf::RenderWindow *window;
   
        Simulation sim;
        
        sf::Clock m_clock;

    public:
        /**
         * @brief Construct a new Application object.
         * 
         */
        Application();

        /**
         * @brief Destroy the Application object.
         * 
        */
        ~Application();

        /**
         * @brief Runs the main application loop.
         * 
         */
        void run();

    
};

#endif // APPLICATION_H