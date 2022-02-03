#define CATCH_CONFIG_MAIN

//it is needed to include sstream before define private 
#include <sstream> 

#define private public

#include "catch.hpp"

#include "Input.hpp"
#include "Game.hpp"

TEST_CASE( "getString()" ) {
    Game game(nullptr);
    SECTION("test"){
        REQUIRE(game.input.getString() == "test");
    }
    
    SECTION("game g"){
        REQUIRE(game.input.getString() == "game g");
    }

    // REQUIRE(  == 1 );
}