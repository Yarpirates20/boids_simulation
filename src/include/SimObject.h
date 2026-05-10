#ifndef SIMOBJECT_H
#define SIMOBJECT_H

#include "Components.h"

/**
 * @brief Generic SimObject class that uses
 * interfaces to use components.
 *
 */
class SimObject
{
public:
    uint64_t id;

    KinematicsComponent kinematics;
    SettingsComponent settings;

    virtual ~SimObject() = default;

    /**
     * @brief Get the Id object.
     *
     * @return uint64_t Returns the uint64_t unique ID.
     */
    uint64_t getId() const { return id; }

protected:
    // Static counter in class memory determines unique ID
    // for each created entity.
    inline static uint64_t nextId = 0;

    SimObject() : id(nextId++) {}
};

#endif // SIMOBJECT_H