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
    std::pair<lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path *, lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int> > *> generatePath(const FieldCoord &source);
    FieldCoord getCoord(lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path::RevArcIt revArcIt);

private:
    std::vector< std::vector<lemon::ListGraph::NodeIt> > nodeField;
    lemon::ListGraph graphField;
    lemon::ListGraph::NodeMap<FieldCoord> coordMap{ graphField };
    Field &field;
};