#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Can/CanDamage.hpp"

class DamageCircle : public CanDamage, public sf::CircleShape {
	DamageCircle(FieldCoord aim, double damage, double damageRadius);
};