#include "Field/Road.hpp"
#include "Building/Building.hpp"
#include "SFML/Graphics/Color.hpp"
#include "SFML/Graphics/PrimitiveType.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
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

Road::Road(Field &field): Graph{field}{
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

void Road::drawArc(lemon::FilterNodes<lemon::ListDigraph>::ArcIt arcIt) {
    lemon::ListDigraph::Node sourceNode = subGraphField.source(arcIt);
    lemon::ListDigraph::Node targetNode = subGraphField.target(arcIt);
    sf::Vector2f source = Algorithms::fieldCoordToVector2fCentered(coordMap[sourceNode]);
    sf::Vector2f target = Algorithms::fieldCoordToVector2fCentered(coordMap[targetNode]);
    float length = Algorithms::calculateEuclideanDistance(source, target);
    float thickness = 1;
    sf::RectangleShape line;
    line.setSize({length, thickness});
    line.setPosition(source);
    line.setFillColor(sf::Color::Green);
    line.setRotation(Algorithms::radiansToDegrees( Algorithms::calculateAzimuth(source, target) ));
    Game::window->draw(line);
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

std::pair<FieldCoord, bool> Road::generatePath(const FieldCoord &source_, ResourceType type){
    if (source_ == NONE_FIELD_CELL) {
        return std::make_pair(NONE_FIELD_CELL, false);
    }
    lemon::ListDigraph::Node source(nodeField[source_.x][source_.y]);

    lemon::FilterNodes<lemon::ListDigraph>::ArcMap<int> lengthMap(subGraphField);
    for (lemon::ListDigraph::ArcIt it(graphField); it != lemon::INVALID; ++it)
        lengthMap[it] = 1;
    dijkstra_t<lemon::ListDigraph> dijkstra{ subGraphField, lengthMap };
    dijkstra.init();
    dijkstra.addSource(source);
    bool reachedDestination = false;
    while(!reachedDestination){
        lemon::ListDigraph::Node nextNode = dijkstra.nextNode();
        if(nextNode == lemon::INVALID)
            return std::make_pair(NONE_FIELD_CELL, false);
        if(static_cast<Building&>(field.get(coordMap[nextNode])).compatibleResource == type)
            reachedDestination = true;
        else
            dijkstra.processNextNode();
    }

    lemon::ListDigraph::Node destination = dijkstra.nextNode();
    FieldCoord destinationCoord = field.get(coordMap[destination]).getCoord();

    dijkstra_t<lemon::ListDigraph>::Path path{ dijkstra.path(destination) };
    {
        int pathLength = path.length();
		if(pathLength <= 1){
            return std::make_pair(destinationCoord, dijkstra.reached(destination));
        }
        int pathLengthIndex = pathLength - 1;
        dijkstra_t<lemon::ListDigraph>::Path::RevArcIt it(path);

        for (; pathLengthIndex > 1; ++it, pathLengthIndex--);
        FieldCoord fieldCoord = getCoord(it);
        return std::make_pair(fieldCoord, true);
    }
}