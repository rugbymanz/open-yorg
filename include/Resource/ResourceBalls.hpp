#pragma once

#include <vector>

#include "ResourceBall.hpp"

class ResourceBalls{
public:
    void tick();
    static void append(const size_t amount, const ResourceBall &resourceBall);
    
private:
    std::vector<ResourceBall> resourceBalls;

    void update();
    bool isResourceNearby(const FieldCell &fieldCell);
};