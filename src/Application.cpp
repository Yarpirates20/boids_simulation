#include "Application.h"
#include <iostream>

/** @copydoc Application::Application() */
Application::Application() : window(new sf::RenderWindow(sf::VideoMode({1775, 976}), "Boids Attack!")), sim(static_cast<float>(window->getSize().x), static_cast<float>(window->getSize().y), *window)
{
    window->setFramerateLimit(60);
}

/** @copydoc Application::~Application() */
Application::~Application()
{
}

/** @copydoc Application::run() */
void Application::run()
{
    sim.addSingleBoidTest();
    
    while (window->isOpen())
    {
        // Capture time the previous frame took to process
        sf::Time dt = m_clock.restart();
        float deltaTime = dt.asSeconds();

        // Handle events
        while (const std::optional event = window->pollEvent())
        {
            if (event->is<sf::Event::Closed>())
            {
                window->close();
            }
            else if (const auto *keyPressed = event->getIf<sf::Event::KeyPressed>())
            {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                {
                    window->close();
                }
            }
        }

        // update
        sim.update(deltaTime);

        // TEST PRINT
        static float timer = 0;
        timer += deltaTime;
        if (timer >= 1.0f)
        {

            for (const auto &boid : sim.getObjects())
            {
                std::cout << "Pos: " << boid->kinematics.position.x << ", " << boid->kinematics.position.y << std::endl;
            }

            timer = 0;
        }

        // draw
        window->clear();

        window->display();
    }
}
