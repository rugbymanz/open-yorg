#pragma once

#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>

#include "ValuesAndTypes.hpp"

class Field;

class Road{
public:
    Road(Field &field);
    void update();
    void draw();

private:
    Field &field;
    lemon::ListDigraph graphField;
    lemon::ListDigraph::NodeMap<bool> nodeFilter{ graphField, false };
    std::vector< std::vector<lemon::ListDigraph::NodeIt> > nodeField;
    lemon::FilterNodes<lemon::ListDigraph> subGraphField{ graphField, nodeFilter };
    lemon::ListDigraph::NodeMap<FieldCoord> coordMap{ graphField };

    void connect(lemon::ListDigraph::NodeIt node);
    void drawArc(lemon::FilterNodes<lemon::ListDigraph>::ArcIt arcIt);
};