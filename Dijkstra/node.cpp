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
    Edge<Node> edge_to_find(id, end_id);

    for (Edges::iterator edge = edges.begin(); edge != edges.end(); edge++) {
        if (*edge == edge_to_find) {
            return *edge;
        }
    }

    return edge_to_find;
}

bool Node::valid() const {
    return !id.empty();
}

bool Node::visited() const {
    return _completely_computed;
}

void Node::mark_as_visited() {
    _completely_computed = true;
}

bool operator<(const Node &a, const Node &b) {
    return (a.weight > b.weight);
}