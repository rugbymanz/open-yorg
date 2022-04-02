#include "Interface.hpp"
#include "Field/Field.hpp"
#include "ValuesAndTypes.hpp"
#include "Field/FieldCell.hpp"

Interface::Interface(Field &field) : field{ field } {}

void Interface::tick(){
    update();
}

void Interface::update(){
    
}

void Interface::selectCell(const FieldCoord &selection){
    if(selectedCell != NONE_FIELD_CELL)
        field.get(selectedCell).setOutlineColor(UNSELECTED);
    field.get(selection).setOutlineColor(SELECTED);
    selectedCell = selection;
}