#ifndef BOID_H
#define BOID_H

#include "SimObject.h"

/**
 * @brief The Boid class is a data container and a specific 
 * instance of a SimObject.
 * 
 */
class Boid : public SimObject
{
    public:
        BehaviorComponent behavior;

        /**
         * @brief Construct a new Boid object.
         * 
         */
        Boid() : SimObject() {}
};

#endif // BOID_H