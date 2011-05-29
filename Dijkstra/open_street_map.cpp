//
//  open_street_map.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <string>
#include "open_street_map.h"
#include "simplexml.h"
using namespace std;

void OpenStreetMap::parse_file(const string & source_file) {
    ifstream source;
    string xml;

    source.open(source_file.c_str(), ios::in);
    source >> xml;

    simplexml * xml_tree = new simplexml(xml.c_str());
    //xml_tree -> child("osm") -> child("node", 3);
    
}

bool OpenStreetMap::include(const Node & node) {
    return true; // TODO!
}

Nodes OpenStreetMap::nodes() {
    return _nodes;
}

Edges OpenStreetMap::edges() {
    return _edges;
}