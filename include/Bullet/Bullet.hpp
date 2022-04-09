#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Graphical.hpp"
#include "Can/CanMove.hpp"
#include "Can/CanDamage.hpp"

class Bullet: public sf::CircleShape, public Graphical, public CanMove, public CanDamage{
public:
    Bullet(sf::Vector2f spawnPosition, FieldCoord aim, double damage, int damageRadius);
    Bullet(sf::Vector2f spawnPosition, sf::Vector2f aim, double damage, double damageRadius);
    // void update();
    // void damage();
    // void erase();
    void draw() override;
    void update();
protected:
    sf::Vector2f getCenter() override;
    void move_() override;

private:
    void init(sf::Vector2f spawnPosition);
};