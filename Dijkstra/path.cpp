//
//  path.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include "path.h"
using namespace std;

void Path::print() {
    Distance total_distance = 0;

    if (! _edges.empty()) {
        Way current_way(_edges.at(0).way);
        Distance distance_on_current_way = 0;

        for (EdgeList::iterator edge = _edges.begin(); edge != _edges.end(); edge++) {
            distance_on_current_way += edge -> length();

            if (! (edge -> way == current_way)) {
                cout << distance_on_current_way << " " << current_way.name() << endl;
                total_distance += distance_on_current_way;
                current_way = edge -> way;
            }
        }
    }
    else {
        cout << "There is no edges." << endl;
    }

    cout << "Total distance: " << total_distance << endl;
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
    NodeList::iterator previous = _nodes.begin();

    for (NodeList::iterator current = _nodes.begin() + 1; current != _nodes.end(); current++, previous++) {
        Edge<Node> edge = previous -> find_edge_by_end_id(current -> id);

        if (edge.valid())
            edge_list.push_back(edge);
    }

    return edge_list;
}

