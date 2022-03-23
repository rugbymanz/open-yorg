#pragma once

#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>
#include <lemon/grid_graph.h>

#include "ValuesAndTypes.hpp"

class PathSearchField{
public:
    enum class Walkability{
        walkable,
        unwalkable
    };

    PathSearchField();
    lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path generatePath(const FieldCoord &source);

private:
    std::vector< std::vector<lemon::ListGraph::NodeIt> > field;
    lemon::ListGraph pathSearchField;
    lemon::ListGraph::NodeMap<int> nodeMap{ pathSearchField };
};