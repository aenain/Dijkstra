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
using namespace std;

class Node {
public:
    string id;
    Distance latitude, longitude;
    Distance weight;
    priority_queue<Edge<Node> > edges; // dirty hack I know, but works :)
    string predecessor_id; // id of predecessor on the shortest path
    bool completely_computed;

    Node() : latitude(0.0), longitude(0.0), predecessor_id(NULL), completely_computed(false), weight(Numbers::MAXIMUM) {};
    
    Node(const Distance & latitude, const Distance & longitude) : latitude(latitude), longitude(longitude), predecessor_id(NULL), completely_computed(false), weight(Numbers::MAXIMUM) {};

    Node(const string & id, const Distance & latitude, const Distance & longitude) : id(id), latitude(latitude), longitude(longitude), predecessor_id(NULL), completely_computed(false), weight(Numbers::MAXIMUM) {};

    bool operator==(const Node & other);
    Edge<Node> find_edge_by_end_id(const string & end_id);
private:
};


typedef priority_queue<Edge<Node> > Edges;
typedef vector<Edge<Node> > EdgeList;

typedef map<string, Node> Nodes;
typedef vector<Node> NodeList;

#endif