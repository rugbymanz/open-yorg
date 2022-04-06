#pragma once

#include <SFML/System/Clock.hpp>

#include "Can/CanDamage.hpp"

class CanShoot : public CanDamage {
public:
	CanShoot(FieldCoord aim, double damage);
protected:
	virtual void shootAim();
	bool isTimeToShoot();
	double fireRate = NONE;
private:
	sf::Clock clock;

	void findAim();
};