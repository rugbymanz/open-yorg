#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>

#include "Can/CanMove.hpp"
#include "Can/CanHaveHp.hpp"
#include "Can/CanShoot.hpp"
#include "Graphical.hpp"

class PathSearchField;
class Bullets;

class Enemy: public CanMove, public CanHaveHp, public CanShoot, public sf::CircleShape, public Graphical {
public:
    Enemy(const FieldCoord &spawnPosition, PathSearchField &pathSearchField, Bullets &bullets);
    virtual ~Enemy();
    void attack();
    void draw() override;
    void update()override;

protected:
    FieldCoord nextMoveFieldCoord;
    sf::Vector2f getCenter() override;
private:
    PathSearchField &pathSearchField;
    Bullets &bullets;
    
    void move_();
    void shootAim()override;
};