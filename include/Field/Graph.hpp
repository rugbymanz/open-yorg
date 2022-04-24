#pragma once

#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>

#include "ValuesAndTypes.hpp"

class Field;

template<class GR>
class Graph{
public:
    Graph(Field &field);
    virtual void update() = 0;

protected:
    Field &field;
    GR graphField;
    typename GR::template NodeMap<bool> nodeFilter{ graphField};
    std::vector< std::vector<typename GR::NodeIt> > nodeField;
    lemon::FilterNodes<GR> subGraphField{ graphField, nodeFilter };
    typename GR::template NodeMap<FieldCoord> coordMap{ graphField };

    FieldCoord getCoord(typename dijkstra_t<GR>::Path::RevArcIt revArcIt);
};

template <class GR>
Graph<GR>::Graph(Field &field): field{ field }{}


template<class GR>
FieldCoord Graph<GR>::getCoord(typename dijkstra_t<GR>::Path::RevArcIt revArcIt) {
    return coordMap[graphField.source(revArcIt)];
}