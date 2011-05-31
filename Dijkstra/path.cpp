//
//  path.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include "path.h"

void Path::print() {
    // trzeba listę node'ów przeczytać i dla każdego node'a 
}

NodeList Path::nodes() {
    return _nodes;
}

EdgeList Path::edges() {
    return _edges;
}

NodeList Path::build_node_list_from_nodes(Nodes & nodes, const Node & end) {
    NodeList node_list;
    Node current = end;

    while (true) {
        node_list.insert(node_list.begin(), current);
        if (current.predecessor_id.empty()) break;

        current = nodes[current.predecessor_id];
    }

    return node_list;
}

EdgeList Path::build_edge_list() {
    EdgeList edge_list;
    Node current = _nodes.at(0);
    // TODO!
    return edge_list;
}