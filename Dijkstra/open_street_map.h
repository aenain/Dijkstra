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
//#include "ticpp.h"

using namespace std;

class OpenStreetMap {
public:
    void parse_file(const string & source_file);
    bool include(const Node & node);
    Nodes nodes();
    Edges edges();
    //OpenStreetMap(); // TODO! zaincjalizować _nodes i _edges

private:
    string _source_file;
    Nodes _nodes;
    Edges _edges;

    void read_file_into_string(const string & source_file, string & xml);
    Nodes fetch_nodes(simplexml * const xml_tree);
    Edges fetch_edges(simplexml * const xml_tree);
/*
    Nodes fetch_nodes(const TiXmlHandle docHandle);
    Edges fetch_edges(const TiXmlHandle docHandle);
*/
};

#endif