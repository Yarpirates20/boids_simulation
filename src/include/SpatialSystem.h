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

    /**
     * @brief Takes 2D grid coordinates and squashes them into 1D index.
     * 
     * @param x Grid X-coordinate.
     * @param y Grid Y-coordinate.
     * @return int The converted vector index.
     */
    int getIndex(int x, int y) const;

    /**
     * @brief Translates continuous world position (pixels) into discrete 2D 
     * grid coordinates (columns and row columns).
     * 
     * @param position The pixel coordinates.
     * @return sf::Vector2i The Grid coordinates.
     */
    sf::Vector2i getGridCoords(const sf::Vector2f &position) const;

public:
    /**
     * @brief Construct a new Spatial System object.
     * 
     * @param width World width.
     * @param height World height.
     * @param cellSize Cell size approximate to perception radius.
     */
    SpatialSystem(float width, float height, float cellSize);

    void update(std::vector<std::shared_ptr<SimObject>> &objects, float dt) override;

    std::vector<std::shared_ptr<SimObject>> getNeighbors(const sf::Vector2f &pos) const;
};

#endif // SPATIALSYSTEM_H