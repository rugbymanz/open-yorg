#include <assert.h>

#include "Building/Base.hpp"

Base::Base(){
}

void Base::draw(){
    if(getCoord() == ValuesAndTypes::noneFieldCell){
        assert(0 && "Base cell's coordinates are not specified");
    }
}