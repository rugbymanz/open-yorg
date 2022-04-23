#pragma once

#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>
#include <lemon/adaptors.h>

#include "ValuesAndTypes.hpp"
#include "Field/Graph.hpp"

class PathSearchField: public Graph<lemon::ListGraph>{
public:
    PathSearchField(Field &field);
    void update() override;
    FieldCoord generatePath(const FieldCoord &source) override;

};