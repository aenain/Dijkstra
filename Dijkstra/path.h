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
    NodeList nodes();
    EdgeList edges();

    // nodes are not changed, but I must not use const. Why? no idea, just throws an error.
    Path(Nodes & nodes, const Node & end) { NodeList _nodes(build_node_list_from_nodes(nodes, end)); EdgeList _edges(build_edge_list()); }

private:
    EdgeList _edges;
    NodeList _nodes;
    NodeList build_node_list_from_nodes(Nodes & nodes, const Node & end);
    EdgeList build_edge_list();
};

#endif