#ifndef OPEN_STREET_MAP_H
#define OPEN_STREET_MAP_H
//
//  open_street_map.h
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <map>
#include "simplexml.h"
#include "edge.h"
#include "node.h"

using namespace std;

class OpenStreetMap {
public:
    void parse_file(const string & source_file);
    bool include(const Node & node);
    Nodes nodes();
    //OpenStreetMap(); // TODO! zaincjalizować _nodes

private:
    string _source_file;
    Nodes _nodes;

    void read_file_into_string(const string & source_file, string & xml);
    Nodes fetch_nodes(simplexml * const xml_tree);
    void fetch_edges_for_nodes(simplexml * const xml_tree);
};

#endif