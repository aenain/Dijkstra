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
    T begin, end;
    Distance weight();

    Edge(T const begin, T const end) : begin(begin), end(end) { _weight(compute_weight()); };
    Edge(T const begin, T const end, const Distance & weight) : begin(begin), end(end), _weight(weight) {};
    bool operator<(const Edge<T> & other);
    
private:
    Distance _weight;
    Distance compute_weight();
};



#endif