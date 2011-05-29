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
    void between(const Node & start_point, const Node & finish_point);
    ShortestPathFinder(const Nodes & nodes, const Edges & edges) : _nodes(nodes), _edges(edges) {};

private:
    const Nodes _nodes;
    const Edges _edges;
};

#endif