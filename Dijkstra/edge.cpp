//
//  edge.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include "edge.h"

template <typename T>
Distance Edge<T>::compute_weight() {
    return sqrt( pow(end.latitude - begin.latitude, 2) + pow(end.longitude - begin.latitude, 2) );
}

template <typename T>
Distance Edge<T>::weight() {
    return _weight;
}

template <typename T>
bool Edge<T>::operator<(const Edge<T> & other) {
    return weight() > other.weight();
}