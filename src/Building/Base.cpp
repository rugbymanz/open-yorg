#include <assert.h>

#include <SFML/Graphics/Text.hpp>

#include "Building/Base.hpp"
#include "Game.hpp"

Base::Base(const FieldCoord &fieldCoord): Building{fieldCoord}{
    text.setString("B");
    renderTexture.draw(text);
    if(Field::basePosition != NONE_FIELD_CELL){
        printf("\nbasePos = %d %d\n", Field::basePosition.x, Field::basePosition.y);
        assert(0 && "Base has yet been built");
    }
    Field::basePosition = coord;
}

void Base::draw(){
    FieldCell::draw();
    Game::window->draw(*this);
}