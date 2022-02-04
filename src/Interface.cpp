#include "Interface.hpp"
#include "Game.hpp"
#include "ValuesAndTypes.hpp"

void Interface::tick(){
    update();
}

void Interface::update(){
    
}

void Interface::selectCell(const FieldCoord &selection){
    Game::gameElements.field.get(selectedCell).setOutlineColor(ValuesAndTypes::Colors::normal);
    Game::gameElements.field.get(selection).setOutlineColor(ValuesAndTypes::Colors::selected);
    selectedCell = selection;
}