//
//  edge.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include "edge.h"

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