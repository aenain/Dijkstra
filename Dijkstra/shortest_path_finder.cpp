//
//  shortest_path_finder.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include "shortest_path_finder.h"
using namespace std;

// Dijkstra's algorithm.
Path ShortestPathFinder::between(const Node &begin_node, const Node &end_node) {
    long long int nodes_to_compute_count = _nodes.size();
    Node *previous = NULL;
    Node *start = &_nodes[begin_node.id];
    Node *end = &_nodes[end_node.id];

    build_nodes_queue_from_node(start);
    cout << _nodes_queue.top() -> weight << endl;

    while (Node *current = _nodes_queue.top()) {
        if (nodes_to_compute_count > 0)
            _nodes_queue.pop();
        else
            break;

        if (*current == *end)
            break;

        if (! current -> is_visited()) {
            current -> mark_as_visited();
            nodes_to_compute_count--;

            update_weight_of_nodes_connected_with_node(current);
            set_predecessor_of_node(current, previous);

            previous = current;
        }
    }

    cout << "Tworzę ścieżkę" << endl;

    Path path(_nodes, *end);
    return path;
}

void ShortestPathFinder::build_nodes_queue_from_node(Node *start) {
    for (NodeMap::iterator node = _nodes.begin(); node != _nodes.end(); node++) {
        Node *current = &(node -> second);

        if (*current == *start) {
            current -> weight = 0;
            cout << "current weight: " << current -> weight << endl;
        }

        _nodes_queue.push(current);
    }
}

void ShortestPathFinder::update_weight_of_nodes_connected_with_node(const Node *node) {
    Distance weight_from_current_node;

    cout << "ilość edges: " << node -> edges.size();
    for (Edges::const_iterator edge = node -> edges.begin(); edge != node -> edges.end(); edge++) {
        Node *end_node = &_nodes[edge -> end_id];
        weight_from_current_node = node -> weight + edge -> length();

        cout << "Długość krawędzi: " << edge -> length() << endl;
        cout << "Wagi: " << weight_from_current_node << "~" << node -> weight << endl;
        if (weight_from_current_node < end_node -> weight && ! end_node -> is_visited()) {
            cout << "zmniejszam wagę! poprzednik: " << node -> id << endl;
            end_node -> weight = weight_from_current_node;
            set_predecessor_of_node(end_node, node);

            _nodes_queue.push(end_node);
        }
    }
}

void ShortestPathFinder::set_predecessor_of_node(Node *node, const Node *predecessor) {
    if (node && predecessor) {
        node -> predecessor_id = predecessor -> id;
    }
}