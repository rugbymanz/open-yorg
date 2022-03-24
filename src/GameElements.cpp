#include "GameElements.hpp"

void GameElements::tick(){
    field.tick();
    enemies.update();
    enemies.draw();
    // resourceBalls.tick();
    // bullets.tick()
}