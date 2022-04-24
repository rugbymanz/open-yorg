#pragma once

#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>

#include "ValuesAndTypes.hpp"
#include "Field/Graph.hpp"

class FieldCell;

class Road: public Graph<lemon::ListDigraph>{
public:
    Road(Field &field);
    void update() override;
    void draw();
    std::pair<FieldCoord, bool> generatePath(const FieldCoord &source, ResourceType type);

private:
    void connect(lemon::ListDigraph::NodeIt node);
    void drawArc(lemon::FilterNodes<lemon::ListDigraph>::ArcIt arcIt);
};