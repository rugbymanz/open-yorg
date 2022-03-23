#pragma once

#include "Field/PathSearchField.hpp"
#include "Algorithms.hpp"
#include "Field/Field.hpp"

PathSearchField::PathSearchField(Field &field) : field{field} {
    nodeField.resize(FIELD_LENGTH);

    for (auto row = nodeField.begin(); row < nodeField.end(); row++) {
        row->resize(FIELD_WIDTH);
        for (auto col = row->begin(); col < row->end(); col++)
            graphField.addNode();
    }
    {
        int i = 0;
        for (lemon::ListGraph::NodeIt it(graphField); it != lemon::INVALID; ++it, i++) {
            FieldCoord fieldCoord = Algorithms::mapFlatIndexToFieldCoord(i);
            nodeField[fieldCoord.x][fieldCoord.y] = it;
        }
    }
    for (int i = 0; i < nodeField.size() - 1; i++) {
        for (int j = 0; j < nodeField[i].size() - 1; j++) {
            graphField.addEdge(nodeField[i][j + 1], nodeField[i][j]);
            graphField.addEdge(nodeField[i + 1][j], nodeField[i][j]);
        }
    }

    for (int j = 1; j < nodeField[CELL_LENGTH - 1].size(); j++)
        graphField.addEdge(nodeField[CELL_LENGTH - 1][j - 1], nodeField[CELL_LENGTH - 1][j]);
}

lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path PathSearchField::generatePath(const FieldCoord &source){
    if (source == NONE_FIELD_CELL) {
        lemon::ListGraph g;
        lemon::ListGraph::ArcMap<int> lengthMap(g);
        lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>> d(g, lengthMap);
        d.init();
        d.start();
        lemon::ListGraph::NodeIt it(g);
        return d.path(it);
    }
    lemon::ListGraph::NodeIt sourceIt(nodeField[source.x][source.y]);
    FieldCoord basePosition = field.basePosition;
    lemon::ListGraph::NodeIt destinationIt(nodeField[basePosition.x][basePosition.y]);

    lemon::ListGraph::ArcMap<int> lengthMap(graphField);
    for (lemon::ListGraph::ArcIt it(graphField); it != lemon::INVALID; ++it)
        lengthMap[it] = 1;

    lemon::ListGraph::NodeMap<int> distMap(graphField);
    lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int> > dijkstra(graphField, lengthMap);
    dijkstra.run(sourceIt, destinationIt);

    lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path path = dijkstra.path(destinationIt);
#ifdef _DEBUG
    std::cout << std::endl << "dijkstra" << std::endl;
    for (lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path::RevArcIt it(path); it != lemon::INVALID; ++it) {
        FieldCoord fieldCoord = Algorithms::mapFlatIndexToFieldCoord(graphField.id(graphField.source(it)));
        std::cout << fieldCoord.x << ' ' << fieldCoord.y << std::endl;
    }
#endif

    return path;
}