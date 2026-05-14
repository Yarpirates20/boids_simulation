#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <SFML/Graphics.hpp>

struct KinematicsComponent
{
    sf::Vector2f position = {0.0f, 0.0f};
    sf::Vector2f velocity = {0.0f, 0.0f};
    sf::Vector2f acceleration = {0.0f, 0.0f};
};

struct SettingsComponent
{
    float maxSpeed = 200.0f;
    float maxForce = 5.0f;
    float perceptionRadius = 50.0f;
};

struct BehaviorComponent
{
    float separationWeight = 1.5f;
    float alignmentWeight = 1.0f;
    float cohesionWeight = 1.0f;
};

struct RenderComponent
{
    sf::ConvexShape body;

    RenderComponent()
    {
        body.setPointCount(3);

        body.setPoint(0, sf::Vector2f{15.f, 0.f});
        body.setPoint(1, sf::Vector2f{-15.f, 7.f});
        body.setPoint(2, sf::Vector2f{-15.f, -7.f});

        body.setOrigin(sf::Vector2f{0.f, 0.f});

        body.setFillColor(sf::Color::Magenta);
        body.setOutlineThickness(1.f);
        body.setOutlineColor(sf::Color::Green);
    }
};

#endif // COMPONENTS_H