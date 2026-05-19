#ifndef SPATIALTESTSYSTEM_H
#define SPATIALTESTSYSTEM_H

#include "ISystem.h"
#include "SpatialSystem.h"
#include "SimObject.h"

#include <vector>
#include <memory>

class SpatialTestSystem : public ISystem
{
    private:
        SpatialSystem &m_spatialSystem;
    
    public:
        SpatialTestSystem(SpatialSystem &spatial) : m_spatialSystem(spatial) {}

        void update(std::vector<std::shared_ptr<SimObject>> &objects, float dt) override
        {
            if (objects.empty())
            {
                return;
            }

            for (auto &obj : objects)
            {
                obj->render.body.setFillColor(sf::Color::White);
            }

            auto &tracker = objects[0];
            tracker->render.body.setFillColor(sf::Color::Green);

            auto neighbors = m_spatialSystem.getNeighbors(tracker->kinematics.position);

            for (auto &neighbor : neighbors)
            {
                if (neighbor != tracker)
                {
                    neighbor->render.body.setFillColor(sf::Color::Red);
                }
            }
            
        }
};

#endif // SPATIALTESTSYSTEM_H