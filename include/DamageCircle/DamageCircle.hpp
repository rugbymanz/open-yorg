#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Can/CanDamage.hpp"
#include "Graphical.hpp"
#include "SFML/System/Clock.hpp"

class DamageCircle : public CanDamage, public sf::CircleShape, public Graphical {
public:
	DamageCircle(FieldCoord aim, double damage, double damageRadius);

	void draw()override;
	virtual void update();
	sf::Vector2f getCenter()override;

private:
	sf::Clock lifeTimeClock;
};
