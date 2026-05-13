#include "Application.h"

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
    while (window->isOpen())
    {
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

        // draw
        window->clear();

        window->display();
    }
}

/** @copydoc Application::getElapsed() */
sf::Time Application::getElapsed()
{
    return m_elapsed;
}

/** @copydoc Application::restartClock() */
void Application::restartClock()
{
    m_elapsed += m_clock.restart();
}
