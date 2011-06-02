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
    Path(NodeMap & nodes, const Node & end) { Nodes _nodes(build_node_list_from_nodes(nodes, end)); Edges _edges(build_edges()); }

private:
    Edges _edges;
    Nodes _nodes;
    Nodes build_node_list_from_nodes(NodeMap & nodes, const Node & end);
    Edges build_edges();
};

#endif