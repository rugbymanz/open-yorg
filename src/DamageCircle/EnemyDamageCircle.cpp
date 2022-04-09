#include "DamageCircle/EnemyDamageCircle.hpp"
#include "Algorithms.hpp"
#include "Field/Field.hpp"
#include "Field/FieldCell.hpp"
#include "Building/Building.hpp"

EnemyDamageCircle::EnemyDamageCircle(FieldCoord aim, double damage, int damageRadius, Field &field) : DamageCircle(aim, damage, damageRadius), field{field} {
    damageNearCells();
}

void EnemyDamageCircle::damageNearCells() {
    for (int col = 0; col < FIELD_LENGTH; col++)
        for (int row = 0; row < FIELD_WIDTH; row++) 
            if (FieldCell &fieldCell = field.get({ col, row }); belongsToCircle(field.get({ col, row }).getCenter()))
                if (fieldCell.isDestructable)
                    static_cast<Building &>(fieldCell).decreaseHp(damage);
}

bool EnemyDamageCircle::belongsToCircle(sf::Vector2f point) {
    sf::Vector2f distance = Algorithms::calculateDistanceVector(point, getCenter());
    return ( (abs(distance.x) < getRadius() ) && ( abs(distance.y) < getRadius() ) );
}