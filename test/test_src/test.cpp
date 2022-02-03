#define CATCH_CONFIG_MAIN

//it is needed to include sstream before define private 
#include <sstream> 

#define private public

#include "catch.hpp"

#include "Input.hpp"
#include "Game.hpp"

TEST_CASE("isValidBuildingPosition") {
    Game game(nullptr);
    REQUIRE(game.input.isValidBuildingPosition(FieldCoord(1, 1)) == true );

    // REQUIRE(  == 1 );
}