#ifndef SPATIALSYSTEM_H
#define SPATIALSYSTEM_H

#include "ISystem.h"
#include "Boid.h"


#include <vector>
#include <memory>



/**
 * @brief This class manages the boids in a grid cell and it's neighbors.
 * 
 */
class SpatialSystem : public ISystem
{
    private:
        float m_cellSize;
        int m_cols;
        int m_rows;

        std::vector<std::vector<std::shared_ptr<Boid>>> m_grid;

        int getIndex(int x, int y) const;

    public:
        SpatialSystem(float width, float height, float cellSize);

    void update(std::vector<std::shared_ptr<SimObject>> &objects, float dt) override;

    std::vector<std::shared_ptr<SimObject>> getNeighbors(const sf::Vector2f &pos) const;
};

#endif // SPATIALSYSTEM_H