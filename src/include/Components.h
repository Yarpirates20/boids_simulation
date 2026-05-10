#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <SFML/Graphics.hpp>

struct KinematicsComponent
{
    sf::Vector2 position;
    sf::Vector2 velocity;
    sf::Vector2 acceleration;
};

struct SettingsComponent
{
    float maxSpeed;
    float maxForce;
    float perceptionRadius;
};

struct BehaviorComponent
{
    float separationWeight;
    float alignmentWeight;
    float cohesionWeight;
};

#endif // COMPONENTS_H