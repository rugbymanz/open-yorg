#pragma once

#include "ValuesAndTypes.hpp"

class Road{
public:
    static FieldCoord findPath(const FieldCoord &source, const FieldCoord &destination);

    void tick();

private:
    void update();
    // adjacency_list road;
};