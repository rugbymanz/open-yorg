#include <SFML/Graphics/Sprite.hpp>

#include "Enemy/Enemy.hpp"
#include "Algorithms.hpp"
#include <Game.hpp>

Enemy::Enemy(const FieldCoord &spawnPosition, PathSearchField &pathSearchField) : pathSearchField{ pathSearchField } {
    currentPosition = Algorithms::mapFieldCoordToVector2f(spawnPosition);
    path = pathSearchField.generatePath(spawnPosition);
    setPosition(spawnPosition.x * CELL_LENGTH, spawnPosition.y * CELL_WIDTH);
    setRadius(CELL_LENGTH / 2);
    setOutlineColor(UNSELECTED);
    setOutlineThickness(CELL_OUTLINE_THICKNESS);
    setTexture(&renderTexture.getTexture());

    text.setString("E");
    renderTexture.draw(text);

    std::cout << "printing path" << std::endl;
    for (auto &el : path) {
        std::cout << el.x << ' ' << el.y << std::endl;
    }
}

Enemy::~Enemy() {
}

void Enemy::drawPathCoords() {

}

void Enemy::draw(){
    Graphical::draw();
    drawPathCoords();
    Game::window->draw(*this);
}

void Enemy::update(){
    

    // moveSprite
}