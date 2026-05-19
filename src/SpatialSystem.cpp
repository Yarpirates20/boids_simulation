#include "SpatialSystem.h"

/** @copydoc SpatialSystem::getIndex(int x, int y) const */
int SpatialSystem::getIndex(int x, int y) const
{
    return y * m_cols + x;
}

/** @copydoc SpatialSystem::getGridCoords(const sf::Vector2f &position) const */
sf::Vector2i SpatialSystem::getGridCoords(const sf::Vector2f &position) const
{
    int x = static_cast<int>(position.x / m_cellSize);
    int y = static_cast<int>(position.y / m_cellSize);

    return sf::Vector2i(x, y);
}

/** @copydoc SpatialSystem::SpatialSystem(float width, float height, float cellSize) */
SpatialSystem::SpatialSystem(float width, float height, float cellSize) : m_cellSize(cellSize), m_cols(static_cast<int>(width / cellSize) + 1), m_rows(static_cast<int>(height / cellSize) + 1), m_grid(m_cols * m_rows)
{
}

/** @copydoc SpatialSystem::update(std::vector<std::shared_ptr<SimObject>> &objects, float dt) */
void SpatialSystem::update(std::vector<std::shared_ptr<SimObject>> &objects, float dt)
{
    for (auto &&cell : m_grid)
    {
        cell.clear();
    }

    for (const auto &obj: objects)
    {
        sf::Vector2i gridCoords = getGridCoords(obj->kinematics.position);

        if (gridCoords.x >= 0 && gridCoords.x < m_cols &&
            gridCoords.y >= 0 && gridCoords.y < m_rows)
        {
            int index = getIndex(gridCoords.x, gridCoords.y);

            m_grid[index].push_back(obj);
        }
        
    }
}

/** @copydoc patialSystem::getNeighbors(const sf::Vector2f &pos) const */
std::vector<std::shared_ptr<SimObject>> SpatialSystem::getNeighbors(const sf::Vector2f &pos) const
{
    std::vector<std::shared_ptr<SimObject>> localNeighbors;

    auto coord = getGridCoords(pos);

    for (int dx = -1; dx <= 1; ++dx)
    {
        for (int dy = -1; dy <= 1; ++dy)
        {
            int neighborX = coord.x + dx;
            int neighborY = coord.y + dy;

            if (neighborX >= 0 && neighborX < m_cols && neighborY >= 0 && neighborY < m_rows)
            {
                int index = getIndex(neighborX, neighborY);

                const auto &cellBoids = m_grid[index];
                localNeighbors.insert(localNeighbors.end(), cellBoids.begin(), cellBoids.end());
            }
        }
    }

    return localNeighbors;
}
