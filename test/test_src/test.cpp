#define CATCH_CONFIG_MAIN

//it is needed to include sstream before define private 
#include <sstream> 

#define private public

#include "catch.hpp"

#include "Input.hpp"
#include "Game.hpp"
#include "Field/EmptyFieldCell.hpp"

using namespace std;

TEST_CASE("isValidBuildingPosition") {
    Game game(nullptr);

    for (auto iterator1 = game.gameElements.field.field.begin(); iterator1 < game.gameElements.field.field.end(); iterator1++)
    {
        for (auto iterator2 = iterator1->begin(); iterator2 < iterator1->end(); iterator2++)
        {
            *iterator2 = new EmptyFieldCell;

            // REQUIRE(  == 1 );
        }
    }

    for(int i = 0; i < ValuesAndTypes::Field::fieldLength; i++){
        for(int j = 0; j < ValuesAndTypes::Field::fieldWidth; j++){
            FieldCoord fieldCell(i, j);

                REQUIRE(game.input.isValidBuildingPosition(fieldCell) == false);


                REQUIRE(game.gameElements.field.get(fieldCell).isEmpty == true);
        }
    }

   
}