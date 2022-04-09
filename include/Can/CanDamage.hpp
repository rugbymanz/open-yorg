#pragma once

#include "ValuesAndTypes.hpp"

class CanDamage{
public:
    double damage = NONE;

    CanDamage(sf::Vector2f aim, double damage, double damageRadius);
    CanDamage(FieldCoord aim, double damage, int damageRadius);

    int getDamageRadiusi();
    int getDamageRadiusd();
    FieldCoord getAimFieldCoord();
    sf::Vector2f getAimVector2f();

    void setDamageRadiusi(int damageRadius);
    void setDamageRadiusd(double damageRadius);
    void setAimFieldCoord(FieldCoord aim);
    void setAimVector2f(sf::Vector2f aim);

private:
    double damageRadius = NONE;
    sf::Vector2f aim = NONE_VECTOR2F;
};