#include "Game.hpp"

Input Game::input;
sf::RenderWindow *Game::window = nullptr;
GameElements Game::gameElements;
Interface Game::interface;
ValuesAndTypes Game::valuesAndTypes;
Clock Game::clock;

void Game::tick(){
    // interface.tick();
    // gameElements.tick();
    // clock.tick()
}

Game::Game(sf::RenderWindow *const window){
    this->window = window;
}
