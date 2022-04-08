#include "DamageCircle/DamageCircle.hpp"
#include "Algorithms.hpp"
#include "Game.hpp"
#include "ValuesAndTypes.hpp"

DamageCircle::DamageCircle(FieldCoord aim, double damage, double damageRadius) : CanDamage{ aim, damage, damageRadius } {
    setRadius(damageRadius);
    setPosition(Algorithms::mapFieldCoordToVector2fCentered(aim) - sf::Vector2f{ getRadius(), getRadius() });
    setOutlineColor(UNSELECTED);
    setOutlineThickness(CELL_OUTLINE_THICKNESS);
    setFillColor(sf::Color{ 255, 0, 0, 125 });
};

void DamageCircle::draw() {
    Graphical::draw();
    renderTexture.display();
    Game::window->draw(*this);
}

void DamageCircle::update() {
    if (DAMAGE_CIRCLE_LIFE_TIME < lifeTimeClock.getElapsedTime().asSeconds())
        deleted = true;
}

sf::Vector2f DamageCircle::getCenter() {
    return { getPosition().x + getRadius(), getPosition().y + getRadius() };
}