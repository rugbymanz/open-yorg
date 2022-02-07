#include "Interface.hpp"
#include "Game.hpp"
#include "ValuesAndTypes.hpp"

void Interface::tick(){
    update();
}

void Interface::update(){
    
}

void Interface::selectCell(const FieldCoord &selection){
    if(selectedCell != ValuesAndTypes::noneFieldCell)
        Game::gameElements.field.get(selectedCell).setOutlineColor(ValuesAndTypes::Colors::unselected);
    Game::gameElements.field.get(selection).setOutlineColor(ValuesAndTypes::Colors::selected);
    selectedCell = selection;
}