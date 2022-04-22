#pragma once

#include "Field/PathSearchField.hpp"
#include "Algorithms.hpp"
#include "Field/Field.hpp"
#include "Field/FieldCell.hpp"

PathSearchField::PathSearchField(Field &field) : Graph{ field } {
    nodeField.resize(FIELD_LENGTH);
    for (int col = 0; col < FIELD_LENGTH; col++) {
        nodeField[col].resize(FIELD_WIDTH);
        for (int row = 0; row < FIELD_WIDTH; row++)
            graphField.addNode();
    }
    {
        int i = 0;
        for (lemon::ListGraph::NodeIt it(graphField); it != lemon::INVALID; ++it, i++) {
            FieldCoord fieldCoord = Algorithms::flatIndexToFieldCoord(i);
            nodeField[fieldCoord.x][fieldCoord.y] = it;
        }
    }
    for (int col = 0; col < FIELD_LENGTH; col++)
        for (int row = 0; row < FIELD_WIDTH; row++)
            nodeFilter[nodeField[col][row]] = true;
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
            coordMap[nodeField[col][row]] = { col, row };
}

void PathSearchField::update() {
    for (int col = 0; col < FIELD_LENGTH; col++)
        for (int row = 0; row < FIELD_WIDTH; row++)
            if (FieldCell &fieldCell = field.get({ col, row }); !fieldCell.isEmpty && !fieldCell.isDestructable)
                nodeFilter[nodeField[col][row]] = false;
            else
                nodeFilter[nodeField[col][row]] = true;
}