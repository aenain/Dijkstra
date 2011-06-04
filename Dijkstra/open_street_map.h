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
#include "edge.h"
#include "node.h"
#include "xml.h"

using namespace std;

class OpenStreetMap {
public:
    void parse_file(const string & source_file);
    void fill_up_information_about_node(Node &node);
    bool include(const Node & node);
    NodeMap nodes();
    OpenStreetMap() : _minimum(0, 0), _maximum(0, 0) {}; // TODO! zaincjalizować _nodes

private:
    string _source_file;
    Location _minimum, _maximum; // range of map
    NodeMap _nodes;

    void read_file_into_string(const string & source_file, string & xml);

    NodeMap fetch_nodes(const XMLNode xml_tree);
    void fetch_and_build_nodes_edges(const XMLNode xml_tree);

    void build_nodes_edges_in_way(vector<string> node_ids, const Way & way);

    void fetch_and_set_map_range(const XMLNode xml_tree);
    bool in_map_range(const Node &node);

    bool check_if_way_is_oneway(const XMLNode xml_way);
    string fetch_way_name(const XMLNode xml_way);
    vector<string> fetch_way_node_ids(const XMLNode xml_way);

    string find_node_id(const Node &node);
};

#endif