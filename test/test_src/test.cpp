#define CATCH_CONFIG_MAIN

//it is needed to include sstream before define private 
#include <sstream> 

#define private public

#include "catch.hpp"

#include "Input.hpp"
#include "Game.hpp"

TEST_CASE() {
    Game game(nullptr);
    

    // REQUIRE(  == 1 );
}