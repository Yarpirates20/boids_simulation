#ifndef COMPONENTS_H
#define COMPONENTS_H

#include <SFML/Graphics.hpp>

struct KinematicsComponent
{
    sf::Vector2f position;
    sf::Vector2f velocity;
    sf::Vector2f acceleration;
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

struct RenderComponent 
{
    sf::Color color;
    sf::ConvexShape body;
};


#endif // COMPONENTS_H