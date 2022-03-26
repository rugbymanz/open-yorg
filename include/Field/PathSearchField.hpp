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
    std::pair<dijkstra_t::Path*, dijkstra_t*> generatePath(const FieldCoord &source);
    FieldCoord getCoord(dijkstra_t::Path::RevArcIt revArcIt);

private:
    std::vector< std::vector<lemon::ListGraph::NodeIt> > nodeField;
    lemon::ListGraph graphField; 
    lemon::ListGraph::NodeMap<FieldCoord> coordMap{ graphField };
    Field &field;
    lemon::ListGraph::NodeMap<bool> nodeFilter;
    lemon::FilterNodes<lemon::ListGraph> subGraphField;
    
    void update();
    friend class Field;
};