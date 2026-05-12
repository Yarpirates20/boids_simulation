#ifndef ISYSTEM_H
#define ISYSTEM_H

#include "SimObject.h"

#include <vector>

class ISystem
{
    public:
        virtual void update(std::vector<std::shared_ptr<SimObject>>& objects, float deltaTime) = 0;
};

#endif // ISYSTEM_H