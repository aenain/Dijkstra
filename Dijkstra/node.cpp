//
//  node.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include "node.h"

bool Node::operator==(const Node & other) {
    bool same_location = (location == other.location);
    bool same_id = (id == other.id);

    return same_location || same_id;
}

Edge<Node> Node::find_edge_by_end_id(const string &end_id) {
    Edges copied_edges = edges;
    Edge<Node> edge_to_find(id, end_id);

    while (! copied_edges.empty()) {
        Edge<Node> edge(copied_edges.top());
        copied_edges.pop();

        if (edge_to_find == edge)
            return edge;
    }

    return edge_to_find;
}