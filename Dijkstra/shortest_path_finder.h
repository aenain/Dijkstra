#ifndef SHORTEST_PATH_FINDER_H
#define SHORTEST_PATH_FINDER_H
//
//  shortest_path_finder.h
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include "open_street_map.h"
using namespace std;

class ShortestPathFinder {
public:
    // type is temporary
    void between(const Node & begin_node, const Node & end_node);
    ShortestPathFinder(const Nodes & nodes) : _nodes(nodes) {};

private:
    Nodes _nodes;
};

#endif