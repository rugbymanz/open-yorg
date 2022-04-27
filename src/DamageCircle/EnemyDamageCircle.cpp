#include "DamageCircle/EnemyDamageCircle.hpp"
#include "Algorithms.hpp"
#include "Field/Field.hpp"
#include "Field/FieldCell.hpp"
#include "Building/Building.hpp"

EnemyDamageCircle::EnemyDamageCircle(FieldCoord aim, double damage, int damageRadius, Field &field) : DamageCircle(aim, damage, damageRadius), field{field} {
    damageNear();
}

void EnemyDamageCircle::damageNear() {
    for (int col = 0; col < FIELD_LENGTH; col++)
        for (int row = 0; row < FIELD_WIDTH; row++)
            if (FieldCell &fieldCell = field.get({ col, row }); fieldCell.fieldCellType == FieldCell::FieldCellType::building)
                if (Algorithms::belongsToCircle(fieldCell.getCenter(), getCenter(), getRadius()))
                    static_cast<Building &>(fieldCell).decreaseHp(damage);
}