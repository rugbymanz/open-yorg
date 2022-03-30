#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>

#include "Can/CanMove.hpp"
#include "Can/CanHaveHp.hpp"
#include "Can/CanDamage.hpp"
#include "Graphical.hpp"

class PathSearchField;

class Enemy: public CanMove, public CanHaveHp, public CanDamage, public sf::CircleShape, public Graphical {
public:
    Enemy(const FieldCoord &spawnPosition, PathSearchField &pathSearchField);
    virtual ~Enemy();
    void attack();

protected:
    std::vector<FieldCoord> path;
    int pathPosIndex = NONE;
private:
    PathSearchField &pathSearchField;
    
    void move_();
    void draw() override;
    void update();

    friend class Enemies;
};