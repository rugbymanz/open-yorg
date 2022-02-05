#include <assert.h>

#include "Building/Base.hpp"
#include "Game.hpp"

Base::Base(const FieldCoord &fieldCoord): Building{fieldCoord}{
}

void Base::draw(){
    Game::window->draw(*this);
}