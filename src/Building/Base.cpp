#include <assert.h>

#include "Building/Base.hpp"
#include "Game.hpp"

Base::Base(const FieldCoord &fieldCoord): Building{fieldCoord}{
    if(Game::gameElements.field.basePosition != ValuesAndTypes::noneFieldCell){
        printf("\nbasePos = %d %d\n", Game::gameElements.field.basePosition.x, Game::gameElements.field.basePosition.y);
        assert(0 && "Base has yet been built");
    }
    Game::gameElements.field.basePosition = coord;
}

void Base::draw(){
    Game::window->draw(*this);
}