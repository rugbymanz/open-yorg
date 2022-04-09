#pragma once

#include <SFML/Graphics/CircleShape.hpp>

#include "Can/CanDamage.hpp"
#include "Graphical.hpp"
#include "SFML/System/Clock.hpp"

class DamageCircle : public CanDamage, public sf::CircleShape, public Graphical {
public:
	DamageCircle(sf::Vector2f aim, double damage, double damageRadius);
	DamageCircle(FieldCoord aim, double damage, int damageRadius);

	void draw()override;
	virtual void update();
	sf::Vector2f getCenter()override;

private:
	sf::Clock lifeTimeClock;

	void init();
};
