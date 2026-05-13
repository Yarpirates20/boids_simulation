#ifndef INTEGRATIONSYSTEM_H
#define INTEGRATIONSYSTEM_H

#include "ISystem.h"

/**
 * @brief This class is responsible for taking the forces calculated by other 
 * systems and translating them into physical movement.
 * 
 */
class IntegrationSystem : public ISystem
{
    private:
        float worldWidth;
        float worldHeight;

    public:
        /**
         * @brief Construct a new Integration System object.
         * 
         */
        IntegrationSystem(float w, float h) : worldWidth(w), worldHeight(h) {}

        /**
         * @brief Loops through list of SimObjects and updates velocity, 
         * position, checks boundaries, and resets.
         * 
         * @param objects List of object pointers.
         * @param deltaTime Change in time as a float.
         */
        void update(std::vector<std::shared_ptr<SimObject>>& objects, float deltaTime);
};

#endif // INTEGRATIONSYSTEM_H