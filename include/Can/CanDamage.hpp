#pragma once

#include "ValuesAndTypes.hpp"

class CanDamage{
public:
    double damage = NONE;

    CanDamage(sf::Vector2f aim, double damage, double damageRadius);
    CanDamage(FieldCoord aim, double damage, int damageRadius);

    template<class T>
    T getDamageRadius();

    template<class T>
    T getAimCoord(); 

	template<class T>
    void setDamageRadius(T damageRadius);

    template<class T>
    void setAimCoord(T aim);

private:
    double damageRadius = NONE;
    sf::Vector2f aim = NONE_VECTOR2F;
};