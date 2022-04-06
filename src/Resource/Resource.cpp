#include "Resource/Resource.hpp"

Resource::Resource(const FieldCoord &fieldCoord): FieldCell{fieldCoord}{
    isEmpty = false;
}

void Resource::update(){}