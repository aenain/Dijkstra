#ifndef NODE_H
#define NODE_H
//
//  node.h
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include <queue>
#include <map>
#include "edge.h"
#include "location.h"
using namespace std;

class Node {
public:
    string id;
    Location location;
    Distance weight;
    vector<Edge<Node> > edges; // dirty hack I know, but works :)
    string predecessor_id; // id of predecessor on the shortest path

    Node() : id(""), location(0.0, 0.0), predecessor_id(""), _completely_computed(false), weight(Numbers::MAXIMUM) {};

    Node(const Location &location) : id(""), location(location), predecessor_id(""), _completely_computed(false), weight(Numbers::MAXIMUM) {};

    Node(const string &id, const Location &location) : id(id), location(location), predecessor_id(""), _completely_computed(false), weight(Numbers::MAXIMUM) {};

    Node(const Coordinate &latitude, const Coordinate &longitude) : id(""), location(latitude, longitude), predecessor_id(""), _completely_computed(false), weight(Numbers::MAXIMUM) {};

    Node(const string &id, const Coordinate &latitude, const Coordinate &longitude) : id(id), location(latitude, longitude), predecessor_id(""), _completely_computed(false), weight(Numbers::MAXIMUM) {};

    bool operator==(const Node &other);
    Edge<Node> find_edge_by_end_id(const string & end_id);
    bool valid() const;
    bool visited() const;
    void mark_as_visited();
    string & to_xml() const;

private:
    bool _completely_computed;
};

bool operator<(const Node &a, const Node &b);

typedef vector<Edge<Node> > Edges;

typedef vector<Node> Nodes;
typedef map<string, Node> NodeMap;
typedef priority_queue<Node> NodeQueue;

#endif