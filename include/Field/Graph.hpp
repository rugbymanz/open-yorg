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
    FieldCoord generatePath(const FieldCoord &source, const FieldCoord &destination);

protected:
    Field &field;
    GR graphField;
    typename GR::template NodeMap<bool> nodeFilter{ graphField};
    std::vector< std::vector<typename GR::NodeIt> > nodeField;
    lemon::FilterNodes<GR> subGraphField{ graphField, nodeFilter };
    typename GR::template NodeMap<FieldCoord> coordMap{ graphField };

private:
    FieldCoord getCoord(typename dijkstra_t<GR>::Path::RevArcIt revArcIt);
};

template <class GR>
Graph<GR>::Graph(Field &field): field{ field }{}

template<class GR>
FieldCoord Graph<GR>::generatePath(const FieldCoord &source_, const FieldCoord &destination_){
    if (source_ == NONE_FIELD_CELL) {
        return NONE_FIELD_CELL;
    }
    lemon::ListGraph::Node source(nodeField[source_.x][source_.y]);
    lemon::ListGraph::Node destination(nodeField[destination_.x][destination_.y]);

    lemon::FilterNodes<lemon::ListGraph>::ArcMap<int> lengthMap(subGraphField);
    for (lemon::ListGraph::ArcIt it(graphField); it != lemon::INVALID; ++it)
        lengthMap[it] = 1;
    dijkstra_t<GR> dijkstra{ subGraphField, lengthMap };
    dijkstra.run(source, destination);

    typename dijkstra_t<GR>::Path path{ dijkstra.path(destination) };
    {
        int pathLength = path.length();
        if (pathLength == 1) {
            return destination_;
        }
        int pathLengthIndex = pathLength - 1;
        typename dijkstra_t<GR>::Path::RevArcIt it(path);

        for (; pathLengthIndex > 1; ++it, pathLengthIndex--);
        FieldCoord fieldCoord = getCoord(it);
        return fieldCoord;
    }
}

template<class GR>
FieldCoord Graph<GR>::getCoord(typename dijkstra_t<GR>::Path::RevArcIt revArcIt) {
    return coordMap[graphField.source(revArcIt)];
}