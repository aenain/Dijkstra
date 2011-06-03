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
#include "path.h"
using namespace std;

class ShortestPathFinder {
public:
    Path between(const Node &begin_node, const Node &end_node);
    ShortestPathFinder(const NodeMap &nodes) : _nodes(nodes) {};

private:
    NodeMap _nodes;
    NodeQueue _nodes_queue;
    void build_nodes_queue_from_node(Node *start);
    void update_weight_of_nodes_connected_with_node(const Node *node);
    void set_predecessor_of_node(Node *node, const Node *predecessor);
};

#endif