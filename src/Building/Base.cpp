#include <assert.h>

#include "Building/Base.hpp"

Base::Base(){
    type = Building::Types::base;
}

void Base::draw(){
    if(getCoord() == ValuesAndTypes::noneFieldCell){
        assert(0 && "Base cell's coordinates are not specified");
    }
}