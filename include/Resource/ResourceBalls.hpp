#pragma once

#include <list>

class ResourceBall;
class FieldCell;

class ResourceBalls{
public:
    void tick();
    void append(ResourceBall *resourceBall);
    void update();
    
private:
    std::list<ResourceBall*> resourceBalls;

    bool isResourceNearby(const FieldCell &fieldCell);
};