#include <SFML/Graphics/Sprite.hpp>

#include "Enemy/Enemy.hpp"
#include "Algorithms.hpp"
#include <Game.hpp>

Enemy::Enemy(const FieldCoord &spawnPosition, PathSearchField &pathSearchField) : pathSearchField{ pathSearchField } {
    nextMoveFieldCoord = pathSearchField.generatePath(spawnPosition);
    speed = 0.01 * CELL_LENGTH;
    //skip self
    setPosition(Algorithms::mapFieldCoordToVector2f(spawnPosition));
    setRadius(CELL_LENGTH / 2);
    setOutlineColor(UNSELECTED);
    setOutlineThickness(CELL_OUTLINE_THICKNESS);
    setTexture(&renderTexture.getTexture());

    text.setString("E");
    renderTexture.draw(text);
}

Enemy::~Enemy() {
}

void Enemy::draw(){
    Graphical::draw();
    Game::window->draw(*this);
}

void Enemy::move_() {
    sf::Vector2f step = Algorithms::mapFieldCoordToVector2f(nextMoveFieldCoord) - getPosition();
    if (abs(step.x) < speed && abs(step.y) < speed)
        nextMoveFieldCoord = pathSearchField.generatePath(Algorithms::mapVector2fToFieldCoord(getPosition()));
    step = { static_cast<float>( (step.x>0?1:-1) * speed), static_cast<float>((step.y > 0 ? 1 : -1) * speed) };
    move(step);
}

void Enemy::update(){
    move_();

    // moveSprite
}