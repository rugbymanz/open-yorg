#include "Field/Road.hpp"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/Vertex.hpp"
#include "SFML/System/Vector2.hpp"
#include "ValuesAndTypes.hpp"
#include "Field/Field.hpp"
#include "Field/FieldCell.hpp"
#include "Algorithms.hpp"
#include "lemon/adaptors.h"
#include "lemon/core.h"
#include "lemon/list_graph.h"
#include <algorithm>
#include "Game.hpp"

Road::Road(Field &field): field{field}{
    nodeField.resize(FIELD_LENGTH);
    for (int col = 0; col < FIELD_LENGTH; col++) {
        nodeField[col].resize(FIELD_WIDTH);
        for (int row = 0; row < FIELD_WIDTH; row++)
            graphField.addNode();
    }
    {
        int i = 0;
        for (lemon::ListDigraph::NodeIt it(graphField); it != lemon::INVALID; ++it, i++) {
            FieldCoord fieldCoord = Algorithms::flatIndexToFieldCoord(i);
            nodeField[fieldCoord.x][fieldCoord.y] = it;
        }
    }
    for (int col = 0; col < FIELD_LENGTH; col++)
        for (int row = 0; row < FIELD_WIDTH; row++)
            nodeFilter[nodeField[col][row]] = false;

    for (int col = 0; col < FIELD_LENGTH; col++)
        for (int row = 0; row < FIELD_WIDTH; row++)
            coordMap[nodeField[col][row]] = { col, row };
}


void Road::update(){
    for(lemon::FilterNodes<lemon::ListDigraph>::NodeIt it(subGraphField); it != lemon::INVALID; ++it)
        if(!field.get(coordMap[it]).isDestructable)
            nodeFilter[it] = false;
    for(int col = 0; col < FIELD_LENGTH; col++)
        for(int row = 0; row < FIELD_WIDTH; row++)
			if(lemon::ListDigraph::NodeIt node = nodeField[col][row]; field.get({col, row}).isDestructable && !nodeFilter[node]){
                nodeFilter[node] = true;
                connect(node);
            }
}

void Road::draw(){
    for(lemon::FilterNodes<lemon::ListDigraph>::ArcIt it(subGraphField); it != lemon::INVALID; ++it)
        drawArc(it);
}

void Road::drawArc(lemon::FilterNodes<lemon::ListDigraph>::ArcIt arcIt)
{
    lemon::ListDigraph::Node sourceNode = subGraphField.source(arcIt);
    lemon::ListDigraph::Node targetNode = subGraphField.target(arcIt);
    sf::Vertex line[] = { sf::Vertex{Algorithms::fieldCoordToVector2fCentered(coordMap[sourceNode])}, sf::Vertex{ Algorithms::fieldCoordToVector2fCentered(coordMap[targetNode])}};
    Game::window->draw(line, 2, sf::Lines);
}

void Road::connect(lemon::ListDigraph::NodeIt node){
    FieldCoord nodeCoord = {coordMap[node].x, coordMap[node].y};
    int nodeConnectionRadius = field.get({coordMap[node].x, coordMap[node].y}).connectionRadius;
    for(lemon::FilterNodes<lemon::ListDigraph>::NodeIt it(subGraphField); it != lemon::INVALID; ++it){
        if(node == it)
            continue;
		FieldCoord itCoord = {coordMap[it].x, coordMap[it].y};
        int itConnectionRadius = field.get({coordMap[it].x, coordMap[it].y}).connectionRadius;
        int connectionRadius = std::max(nodeConnectionRadius, itConnectionRadius);
		if(Algorithms::belongsToCircle(itCoord, nodeCoord, connectionRadius)){
            subGraphField.addArc(it, node);
            subGraphField.addArc(node, it);
        }
    }
}
