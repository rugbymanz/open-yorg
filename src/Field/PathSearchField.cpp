#pragma once

#include "Field/PathSearchField.hpp"
#include "Algorithms.hpp"
#include "Field/Field.hpp"

lemon::ListGraph PathSearchField::pathSearchField;
std::vector< std::vector<lemon::ListGraph::NodeIt> > PathSearchField::field;

PathSearchField::PathSearchField() {
    field.resize(FIELD_LENGTH);

    for (auto row = field.begin(); row < field.end(); row++) {
        row->resize(FIELD_WIDTH);
        for (auto col = row->begin(); col < row->end(); col++)
            pathSearchField.addNode();
    }
    {
        int i = 0;
        for (lemon::ListGraph::NodeIt it(pathSearchField); it != lemon::INVALID; ++it, i++) {
            FieldCoord fieldCoord = Algorithms::mapFlatIndexToFieldCoord(i);
            field[fieldCoord.x][fieldCoord.y] = it;
        }
    }
    for (int i = 0; i < field.size() - 1; i++) {
        for (int j = 0; j < field[i].size() - 1; j++) {
            pathSearchField.addEdge(field[i][j + 1], field[i][j]);
            pathSearchField.addEdge(field[i + 1][j], field[i][j]);
        }
    }

    for (int j = 1; j < field[CELL_LENGTH - 1].size(); j++) 
        pathSearchField.addEdge(field[CELL_LENGTH - 1][j - 1], field[CELL_LENGTH - 1][j]);
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
    lemon::ListGraph::NodeIt sourceIt(field[source.x][source.y]);
    FieldCoord basePosition = Field::basePosition;
    lemon::ListGraph::NodeIt destinationIt(field[basePosition.x][basePosition.y]);

    lemon::ListGraph::ArcMap<int> lengthMap(pathSearchField);
    for (lemon::ListGraph::ArcIt it(pathSearchField); it != lemon::INVALID; ++it)
        lengthMap[it] = 1;

    lemon::ListGraph::NodeMap<int> distMap(pathSearchField);
    lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int> > dijkstra(pathSearchField, lengthMap);
    dijkstra.run(sourceIt, destinationIt);

    lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path path = dijkstra.path(destinationIt);
#ifdef _DEBUG
    std::cout << std::endl << "dijkstra" << std::endl;
    for (lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path::RevArcIt it(path); it != lemon::INVALID; ++it) {
        FieldCoord fieldCoord = Algorithms::mapFlatIndexToFieldCoord(pathSearchField.id(pathSearchField.source(it)));
        std::cout << fieldCoord.x << ' ' << fieldCoord.y << std::endl;
    }
#endif

    return path;
}