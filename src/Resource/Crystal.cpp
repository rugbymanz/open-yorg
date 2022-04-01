#include "Resource/Crystal.hpp"
#include "Game.hpp"

Crystal::Crystal(const FieldCoord &fieldCoord): Resource{fieldCoord}{
    isEmpty = false;
    text.setString("C");
    renderTexture.draw(text);
}

void Crystal::draw() {
    Resource::draw();
    renderTexture.display();
    Game::window->draw(*this);
}