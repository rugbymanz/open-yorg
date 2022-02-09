#include "Game.hpp"

ValuesAndTypes Game::valuesAndTypes;
Input Game::input;
sf::RenderWindow *Game::window = nullptr;
GameElements Game::gameElements;
Interface Game::interface;
Clock Game::clock;

void Game::tick(){
    // interface.tick();
    // gameElements.tick();
    // clock.tick()
}

Game::Game(sf::RenderWindow *const window){
    this->window = window;
}
