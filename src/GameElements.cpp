#include "GameElements.hpp"

void GameElements::tick(){
    field.tick();
    resourceBalls.update();
    enemies.update();
    enemies.draw();
    // resourceBalls.tick();
    bullets.tick();
    damageCircles.tick();
}