#include "Resource/Resource.hpp"

Resource::Resource(const FieldCoord &fieldCoord): FieldCell{fieldCoord, 2}{
    isEmpty = false;
}

void Resource::update(){}