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
    Node * predecessor; // pointer to predecessor on the shortest path
    bool completely_computed;
    
    Node(const Distance & latitude, const Distance & longitude) : latitude(latitude), longitude(longitude), predecessor(NULL), completely_computed(false) {};

    Node(const string & id, const Distance & latitude, const Distance & longitude) : id(id), latitude(latitude), longitude(longitude), predecessor(NULL), completely_computed(false) {};

    bool operator==(const Node & other);
    
private:
    
};

typedef priority_queue<Edge<Node> > Edges;
typedef map<string, Node> Nodes;
#endif