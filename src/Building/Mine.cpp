#include "Building/Mine.hpp"
#include "Game.hpp"

Mine::Mine(Field &field, const FieldCoord &fieldCoord) : Building{ fieldCoord } {
    isEmpty = false;
    text.setString("M");
    renderTexture.draw(text);
}

void Mine::draw() {
    Building::draw();
    renderTexture.display();
    Game::window->draw(*this);
}