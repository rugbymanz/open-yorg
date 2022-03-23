#pragma once

#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>
#include <lemon/grid_graph.h>

#include "ValuesAndTypes.hpp"

class Field;

class PathSearchField{
public:
    enum class Walkability{
        walkable,
        unwalkable
    };

    PathSearchField(Field &field);
    lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path generatePath(const FieldCoord &source);

private:
    std::vector< std::vector<lemon::ListGraph::NodeIt> > nodeField;
    lemon::ListGraph graphField;
    lemon::ListGraph::NodeMap<int> nodeMap{ graphField };
    Field &field;
};