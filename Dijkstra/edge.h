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
#include "gps.h"
#include "way.h"
using namespace std;

template <class T>
class Edge {
public:
    string begin_id, end_id;
    Way way;

    Distance length() const;
    bool valid() const;

    Edge(const string & begin_id, const string & end_id) : begin_id(begin_id), end_id(end_id), way("0", "NoName"), _length(0), _valid(false) {};
    Edge(T const begin, T const end, const Way & way) : begin_id(begin.id), end_id(end.id), way(way), _length(compute_length(begin, end)), _valid(true) {};
    Edge(T const begin, T const end, const Way & way, const Distance & length) : begin_id(begin.id), end_id(end.id), way(way), _length(length), _valid(true) {};

    bool operator<(const Edge<T> other);

private:
    bool _valid;
    Distance _length;
    Distance compute_length(T const begin, T const end);
};

template <class T>
Distance Edge<T>::compute_length(T begin, T end) {
    return GPS::distance(begin.location, end.location);
}

template <class T>
Distance Edge<T>::length() const {
    return _length;
}

template <class T>
bool Edge<T>::valid() const {
    return _valid;
}

template <class T>
bool operator<(Edge<T> a, Edge<T> b) {
    return a.length() > b.length();
}

template <class T>
bool operator==(Edge<T> a, Edge<T> b) {
    return (a.begin_id == b.begin_id && a.end_id == b.end_id);
}
#endif