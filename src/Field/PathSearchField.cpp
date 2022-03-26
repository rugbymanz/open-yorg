#pragma once

#include "Field/PathSearchField.hpp"
#include "Algorithms.hpp"
#include "Field/Field.hpp"

PathSearchField::PathSearchField(Field &field) : field{field} {
    nodeField.resize(FIELD_LENGTH);
    for (int col = 0; col < FIELD_LENGTH; col++) {
        nodeField[col].resize(FIELD_WIDTH);
        for (int row = 0; row < FIELD_WIDTH; row++)
            graphField.addNode();
    }
    {
        int i = 0;
        for (lemon::ListGraph::NodeIt it(graphField); it != lemon::INVALID; ++it, i++) {
            FieldCoord fieldCoord = Algorithms::mapFlatIndexToFieldCoord(i);
            nodeField[fieldCoord.x][fieldCoord.y] = it;
        }
    }
    for (int col = 0; col < FIELD_LENGTH - 1; col++) {
        for (int row = 0; row < FIELD_WIDTH - 1; row++) {
            graphField.addEdge(nodeField[col][row + 1], nodeField[col][row]);
            graphField.addEdge(nodeField[col + 1][row], nodeField[col][row]);
        }
    }

    for (int col = 1; col < CELL_LENGTH; col++)
        graphField.addEdge(nodeField[col - 1][CELL_WIDTH - 1], nodeField[col][CELL_WIDTH - 1]);

    for (int col = 0; col < FIELD_LENGTH; col++)
        for (int row = 0; row < FIELD_WIDTH; row++)
            coordMap[nodeField[col][row] ] = { col, row };
}

std::pair<lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path*, lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int> > *> PathSearchField::generatePath(const FieldCoord &source_){
    if (source_ == NONE_FIELD_CELL) {
        lemon::ListGraph g;
        lemon::ListGraph::ArcMap<int> lengthMap(g);
        lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>> d(g, lengthMap);
        d.init();
        d.start();
        lemon::ListGraph::NodeIt it(g);
        return std::make_pair(new lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path(d.path(it)), &d);
    }
    lemon::ListGraph::NodeIt source(nodeField[source_.x][source_.y]);
    FieldCoord basePosition = field.basePosition;
    lemon::ListGraph::NodeIt destination(nodeField[basePosition.x][basePosition.y]);

    lemon::ListGraph::ArcMap<int> lengthMap(graphField);
    for (lemon::ListGraph::ArcIt it(graphField); it != lemon::INVALID; ++it)
        lengthMap[it] = 1;

    lemon::ListGraph::NodeMap<int> distMap(graphField);
    lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int> > *dijkstra = new lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int> >(graphField, lengthMap);
    dijkstra->run(source, destination);

    lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path *path = new lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path(dijkstra->path(destination) );
//#ifdef _DEBUG
//    std::cout << std::endl << "dijkstra" << std::endl;
//    for (lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path::RevArcIt it(path); it != lemon::INVALID; ++it) {
//        FieldCoord fieldCoord = Algorithms::mapFlatIndexToFieldCoord(graphField.id(graphField.source(it)));
//        std::cout << fieldCoord.x << ' ' << fieldCoord.y << std::endl;
//    }
//#endif
    return std::make_pair(path, dijkstra);
}

FieldCoord PathSearchField::getCoord(lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path::RevArcIt revArcIt) {
    return coordMap[graphField.source(revArcIt)];
}

void PathSearchField::update() {
    std::cout << "printing node count"<< std::endl << lemon::countNodes(graphField) << std::endl;
    for (int col = 0; col < FIELD_LENGTH; col++)
        for (int row = 0; row < FIELD_WIDTH; row++)
            if (!field.get({ col, row }).isEmpty && nodeField[col][row])
                graphField.erase(nodeField[col][row]);

    std::cout << lemon::countNodes(graphField) << std::endl;
}