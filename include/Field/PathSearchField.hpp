#pragma once

#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>
#include <lemon/adaptors.h>

#include "ValuesAndTypes.hpp"

class Field;
class FieldCell;

class PathSearchField{
public:
    PathSearchField(Field &field);
    std::pair<FieldCoord, FieldCell*> generatePath(const FieldCoord &source);
    void update();

private:
    Field &field;
    lemon::ListGraph graphField;
    lemon::ListGraph::NodeMap<bool> nodeFilter{ graphField, true };
    std::vector< std::vector<lemon::ListGraph::NodeIt> > nodeField;
    lemon::FilterNodes<lemon::ListGraph> subGraphField{ graphField, nodeFilter };
    lemon::ListGraph::NodeMap<FieldCoord> coordMap{ graphField };
    
    FieldCoord getCoord(dijkstra_t::Path::RevArcIt revArcIt);
};