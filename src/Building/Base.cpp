#include <assert.h>

#include "Building/Base.hpp"
#include "Game.hpp"

Base::Base(const FieldCoord &fieldCoord): Building{fieldCoord}{
    if(Field::basePosition != NONE_FIELD_CELL){
        printf("\nbasePos = %d %d\n", Field::basePosition.x, Field::basePosition.y);
        assert(0 && "Base has yet been built");
    }
    Field::basePosition = coord;
}

void Base::draw(){
    Game::window->draw(*this);
}