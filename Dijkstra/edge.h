#ifndef EDGE_H
#define EDGE_H
//
//  edge.h
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include "numbers.h"
using namespace std;

template <typename T>
class Edge {
public:
    string begin_id, end_id;
    Distance weight();

    Edge(T const begin, T const end) : begin_id(begin.id), end_id(end.id), _weight(compute_weight(begin, end)) {};
    Edge(T const begin, T const end, const Distance & weight) : begin_id(begin.id), end_id(end.id), _weight(weight) {};
    bool operator<(const Edge<T> & other);

private:
    Distance _weight;
    Distance compute_weight(T const begin, T const end);
};



#endif