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
class Building;
class Field;
class DamageCircles;

class Enemy: public CanMove, public CanHaveHp, public CanShoot, public sf::CircleShape, public Graphical {
public:
    Enemy(const FieldCoord &spawnPosition, PathSearchField &pathSearchField, Bullets &bullets, double damage, Field &field, int damageRadius, DamageCircles &damageCircles);
    virtual ~Enemy() = default;
    void draw() override;
    virtual void update();
    sf::Vector2f getCenter() const override;

private:
    Field &field;
    PathSearchField &pathSearchField;
    Bullets &bullets;
    DamageCircles &damageCircles;
    
    void move_() override;
    void shootAim()override;
    void findNextNode() override;
};