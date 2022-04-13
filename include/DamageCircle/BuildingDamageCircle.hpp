#pragma once

#include "DamageCircle/DamageCircle.hpp"

class Enemies;

class BuildingDamageCircle : public DamageCircle {
public:
	BuildingDamageCircle(sf::Vector2f aim, double damage, double damageRadius, Enemies &enemies);
private:
	Enemies &enemies;

	void damageNear()override;
};