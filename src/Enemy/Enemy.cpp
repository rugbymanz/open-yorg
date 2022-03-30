#include <SFML/Graphics/Sprite.hpp>

#include "Enemy/Enemy.hpp"
#include "Algorithms.hpp"
#include <Game.hpp>

Enemy::Enemy(const FieldCoord &spawnPosition, PathSearchField &pathSearchField) : pathSearchField{ pathSearchField } {
    path = pathSearchField.generatePath(spawnPosition);
    speed = 0.05 * CELL_LENGTH;
    //skip self
    pathPosIndex = path.size() - 2;
    setPosition(Algorithms::mapFieldCoordToVector2f(spawnPosition));
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

void Enemy::draw(){
    Graphical::draw();
    Game::window->draw(*this);
}

void Enemy::move_() {
    sf::Vector2f step = Algorithms::mapFieldCoordToVector2f(path[pathPosIndex]) - getPosition();
    if (abs(step.x) < speed && abs(step.y) < speed)
        if(pathPosIndex > 0)
            pathPosIndex--;
    step = { static_cast<float>( (step.x>0?1:-1) * speed), static_cast<float>((step.y > 0 ? 1 : -1) * speed) };
    move(step);
}

void Enemy::update(){
    move_();

    // moveSprite
}