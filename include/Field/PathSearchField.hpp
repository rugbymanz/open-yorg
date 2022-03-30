#pragma once

#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>
#include <lemon/grid_graph.h>
#include <lemon/adaptors.h>

#include "ValuesAndTypes.hpp"

class Field;

class PathSearchField{
public:
    PathSearchField(Field &field);
    std::vector<FieldCoord> generatePath(const FieldCoord &source);
    FieldCoord getCoord(dijkstra_t::Path::RevArcIt revArcIt);

private:
    Field &field;
    lemon::ListGraph graphField;
    lemon::ListGraph::NodeMap<bool> nodeFilter{ graphField, true };
    std::vector< std::vector<int> > nodeField;
    lemon::FilterNodes<lemon::ListGraph> subGraphField{ graphField, nodeFilter };
    lemon::ListGraph::NodeMap<FieldCoord> coordMap{ graphField };
    
    void update();
    friend class Field;
};