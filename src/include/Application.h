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
        sf::Time m_elapsed;

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

        /**
         * @brief Get the elapsed time between frames.
         * 
         * @return sf::Time Length of time as sf::Time type.
         */
        sf::Time getElapsed();

        /**
         * @brief Restarts the time count between frames.
         * 
         */
        void restartClock();
};

#endif // APPLICATION_H