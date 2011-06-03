#ifndef PATH_H
#define PATH_H
//
//  path.h
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include "way.h"
#include "edge.h"
#include "node.h"
using namespace std;

class Path {
public:
    void print();
    Nodes nodes();
    Edges edges();

    // nodes are not changed, but I must not use const. Why? no idea, just throws an error.
    Path(NodeMap &nodes, Node &end);

private:
    Edges _edges;
    Nodes _nodes;
    void build_node_list_from_nodes(NodeMap &nodes, Node &end);
    void build_edges();
    void print_way_with_distance(const Way &way, const Distance &distance);
    string distance_for_human(Distance distance);
};

#endif