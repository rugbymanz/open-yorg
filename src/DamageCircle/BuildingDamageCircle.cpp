#include "DamageCircle/BuildingDamageCircle.hpp"
#include "Algorithms.hpp"
#include "Building/Building.hpp"
#include "Enemy/Enemy.hpp"
#include "Enemy/Enemies.hpp"

BuildingDamageCircle::BuildingDamageCircle(sf::Vector2f aim, double damage, double damageRadius, Enemies &enemies) : DamageCircle(aim, damage, damageRadius), enemies{ enemies } {
    damageNear();
}

void BuildingDamageCircle::damageNear() {
    std::vector<Enemy*> enemiesInCircle = enemies.findAllInCircle(getCenter(), getRadius());
    for (auto &el : enemiesInCircle) {
        el->decreaseHp(damage);
    }
}