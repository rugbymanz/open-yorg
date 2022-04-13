#pragma once

#include "Bullet/Bullet.hpp"

class DamageCircles;
class Enemies;

class CannonBall: public Bullet{
public:
    CannonBall(sf::Vector2f spawnPosition, sf::Vector2f aim, double damage, double damageRadius, DamageCircles &damgeCircles, Enemies &enemies);
    void tick();

private:
    DamageCircles &damageCircles;
    Enemies &enemies;
    
    void move_();
};