#ifndef ISYSTEM_H
#define ISYSTEM_H

#include "SimObject.h"

#include <vector>

class ISystem
{
    public:
        virtual void update(std::vector<SimObject>, float deltaTime) = 0;
};

#endif // ISYSTEM_H