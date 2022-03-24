#pragma once

#include <SFML/Graphics/CircleShape.hpp>
#include <lemon/dijkstra.h>
#include <lemon/list_graph.h>

#include "Can/CanMove.hpp"
#include "Can/CanHaveHp.hpp"
#include "Can/CanDamage.hpp"
#include "Graphical.hpp"

class PathSearchField;

class Enemy: public CanMove, public CanHaveHp, public CanDamage, public sf::CircleShape, public Graphical {
public:
    Enemy(const FieldCoord &spawnPosition, PathSearchField &pathSearchField);
    void attack();

protected:
    //basic initialization
    lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path *path = nullptr;
    lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int> > *dijkstra = nullptr;
    //[]()->lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>>::Path {
    //    lemon::ListGraph g;
    //    lemon::ListGraph::ArcMap<int> lengthMap(g);
    //    lemon::Dijkstra<lemon::ListGraph, lemon::ListGraph::ArcMap<int>> d(g, lengthMap);
    //    d.init();
    //    d.start();
    //    lemon::ListGraph::NodeIt it(g);
    //    return d.path(it);
    //}();
private:
    PathSearchField &pathSearchField;

    void drawPathCoords();
    void draw() override;
    void update();

    friend class Enemies;
};