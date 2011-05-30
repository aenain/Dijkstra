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

void ShortestPathFinder::between(const Node & begin_node, const Node & end_node) {
    // time for Dijkstra :)
    // in map _nodes are nodes, but theirs edges contains only ids of connected nodes, not nodes.
    int nodes_left_to_compute_count = static_cast<int>(_nodes.size());

    Node * begin = &_nodes[begin_node.id];
    Node * end = &_nodes[end_node.id];
    Node * current = begin;
    Node * previous = NULL;

    begin->weight = 0;

    while (nodes_left_to_compute_count > 0) {
        current->completely_computed = true;
        nodes_left_to_compute_count--;

        
        // 1. oznacz obecny węzeł za "w pełni obliczony" (jeden mniej pozostał do liczenia!)
        // 2. jeśli wagi dotarcia do sąsiadów są większe niż waga dotarcia do obecnego węzła + waga danej krawędzi,
        //    to za predecessor_id podstaw id obecnego węzła i ustaw nową wagę węzła.
        // 3. idź krawędzią, która ma najmniejszą wagę.
    }
}