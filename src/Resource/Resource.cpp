#include "Resource/Resource.hpp"

Resource::Resource(const FieldCoord &fieldCoord): FieldCell{fieldCoord, 2}{
    fieldCellType = FieldCellType::resource;
}

void Resource::update(){}