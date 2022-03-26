#include <assert.h>

#include <SFML/Graphics/Text.hpp>

#include "Building/Base.hpp"
#include "Game.hpp"

Base::Base(Field &field, const FieldCoord &fieldCoord): Building{fieldCoord}{
    isEmpty = false;
    text.setString("B");
    renderTexture.draw(text);
    if(field.basePosition != NONE_FIELD_CELL){
        printf("\nbasePos = %d %d\n", field.basePosition.x, field.basePosition.y);
        assert(0 && "Base has yet been built");
    }
    field.basePosition = coord;
}

void Base::draw(){
    FieldCell::draw();
    Game::window->draw(*this);
}