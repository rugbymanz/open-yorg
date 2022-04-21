#pragma once

#include <SFML/System/Clock.hpp>

#include "Can/CanDamage.hpp"
#include "SFML/System/Vector2.hpp"
#include "ValuesAndTypes.hpp"

class CanShoot : public CanDamage {
public:
	CanShoot(sf::Vector2f aim, double damage, double damageRadius);
	CanShoot(FieldCoord aim, double damage, int damageRadius);
protected:
	virtual void shootAim();
	bool isTimeToAttack();
	double fireRate = NONE;
	bool attacking = false;
	void attack();
	template<class T>
	void setAttackRadius(T attackRadius);
	template<class T>
	T getAttackRadius();
private:
	sf::Clock fireRateClock;
	double attackRadius = NONE;

	void findAim();
};