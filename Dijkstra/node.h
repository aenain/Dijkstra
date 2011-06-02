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

    Node() : id(NULL), location(0.0, 0.0), predecessor_id(NULL), _completely_computed(false), weight(Numbers::MAXIMUM) {};

    Node(const Location &location) : id(NULL), location(location), predecessor_id(NULL), _completely_computed(false), weight(Numbers::MAXIMUM) {};

    Node(const string &id, const Location &location) : id(id), location(location), predecessor_id(NULL), _completely_computed(false), weight(Numbers::MAXIMUM) {};

    Node(const Coordinate &latitude, const Coordinate &longitude) : id(NULL), location(latitude, longitude), predecessor_id(NULL), _completely_computed(false), weight(Numbers::MAXIMUM) {};

    Node(const string &id, const Coordinate &latitude, const Coordinate &longitude) : id(id), location(latitude, longitude), predecessor_id(NULL), _completely_computed(false), weight(Numbers::MAXIMUM) {};

    bool operator==(const Node &other);
    Edge<Node> find_edge_by_end_id(const string & end_id);
    bool is_visited();
    void mark_as_visited();

private:
    bool _completely_computed;
};

bool operator<(const Node &a, const Node &b);

typedef vector<Edge<Node> > Edges;

typedef map<string, Node> Nodes;
typedef vector<Node> NodeList;
typedef priority_queue<Node *> NodeQueue;

#endif