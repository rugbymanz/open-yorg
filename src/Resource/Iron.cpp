#include "Resource/Iron.hpp"
#include "Game.hpp"

Iron::Iron(const FieldCoord &fieldCoord): Resource{fieldCoord}{
    text.setString("I");
    renderTexture.draw(text);
    resourceType = ResourceType::iron;
}

void Iron::draw() {
    Resource::draw();
    renderTexture.display();
    Game::window->draw(*this);
}