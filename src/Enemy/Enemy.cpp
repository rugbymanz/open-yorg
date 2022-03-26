#include <SFML/Graphics/Sprite.hpp>

#include "Enemy/Enemy.hpp"
#include "Field/PathSearchField.hpp"
#include "Algorithms.hpp"
#include <Game.hpp>

Enemy::Enemy(const FieldCoord &spawnPosition, PathSearchField &pathSearchField) : pathSearchField{ pathSearchField } {
    currentPosition = Algorithms::mapFieldCoordToVector2f(spawnPosition);
    auto pair = pathSearchField.generatePath(spawnPosition);
    path = pair.first;
    dijkstra = pair.second;
    setPosition(spawnPosition.x * CELL_LENGTH, spawnPosition.y * CELL_WIDTH);
    setRadius(CELL_LENGTH / 2);
    setOutlineColor(UNSELECTED);
    setOutlineThickness(CELL_OUTLINE_THICKNESS);
    setTexture(&renderTexture.getTexture());

    text.setString("E");
    renderTexture.draw(text);

    std::cout << "printing path" << std::endl;
    for (lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path::RevArcIt it(*path); it != lemon::INVALID; ++it) {
        FieldCoord fieldCoord = pathSearchField.getCoord(it);
        std::cout << fieldCoord.x << ' ' << fieldCoord.y << std::endl;
    }
}

Enemy::~Enemy() {
    delete path;
    delete dijkstra;
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