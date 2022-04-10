#pragma once

#include <SFML/System/Clock.hpp>

#include "Can/CanDamage.hpp"

class CanShoot : public CanDamage {
public:
	CanShoot(sf::Vector2f aim, double damage, double damageRadius);
	CanShoot(FieldCoord aim, double damage, int damageRadius);
protected:
	virtual void shootAim();
	bool isTimeToShoot();
	double fireRate = NONE;
	bool attacking = false;
	void attack();
private:
	sf::Clock fireRateClock;

	void findAim();
};