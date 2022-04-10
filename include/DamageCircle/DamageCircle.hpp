#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/Rect.hpp>

#include "Can/CanDamage.hpp"
#include "Graphical.hpp"
#include "SFML/System/Clock.hpp"

class DamageCircle : public CanDamage, public sf::CircleShape, public Graphical, public sf::FloatRect {
public:
	DamageCircle(sf::Vector2f aim, double damage, double damageRadius);
	DamageCircle(FieldCoord aim, double damage, int damageRadius);

	void draw()override;
	virtual void update();
	sf::Vector2f getCenter()override;

private:
	sf::Clock lifeTimeClock;

	virtual void damageNear() = 0;
	void init();
	virtual bool belongsToCircle(sf::Vector2f point) = 0;
};
