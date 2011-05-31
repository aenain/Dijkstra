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
#include "way.h"
using namespace std;

template <class T>
class Edge {
public:
    string begin_id, end_id;
    Way way;
    Distance weight();

    Edge(T const begin, T const end, const Way & way) : begin_id(begin.id), end_id(end.id), way(way), _weight(compute_weight(begin, end)) {};
    Edge(T const begin, T const end, const Way & way, const Distance & weight) : begin_id(begin.id), end_id(end.id), way(way), _weight(weight) {};

    bool operator<(const Edge<T> other);

private:
    Distance _weight;
    Distance compute_weight(T const begin, T const end);
};

template <class T>
Distance Edge<T>::compute_weight(T begin, T end) {
    return sqrt( pow(end.latitude - begin.latitude, 2) + pow(end.longitude - begin.latitude, 2) );
}

template <class T>
Distance Edge<T>::weight() {
    return _weight;
}

template <class T>
bool Edge<T>::operator<(const Edge<T> other) {
    return weight() > other.weight();
}

template <class T>
bool operator<(Edge<T> a, Edge<T> b) {
    return a.weight() > b.weight();
}

#endif