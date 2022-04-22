#pragma once

#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>

#include "ValuesAndTypes.hpp"
#include "Field/Graph.hpp"

class Road: public Graph<lemon::ListDigraph>{
public:
    Road(Field &field);
    void update() override;
    void draw();

private:
    void connect(lemon::ListDigraph::NodeIt node);
    void drawArc(lemon::FilterNodes<lemon::ListDigraph>::ArcIt arcIt);
};