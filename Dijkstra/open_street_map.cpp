//
//  open_street_map.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include "open_street_map.h"
using namespace std;

bool OpenStreetMap::include(const Node &node_to_find) {
    // checking if node is in map range doesn't make sense, because it's not restricted, eg. there are nodes in *.osm which aren't in range declared in this file.
    return ! find_node_id(node_to_find).empty();
}


bool OpenStreetMap::in_map_range(const Node &node) {
    bool latitude_in_range = Numbers::in_range(node.location.latitude, _minimum.latitude, _maximum.latitude);
    bool longitude_in_range = Numbers::in_range(node.location.longitude, _minimum.longitude, _maximum.longitude);
    
    return latitude_in_range && longitude_in_range;
}

string OpenStreetMap::find_node_id(const Node &node_to_find) {
    string id;
    
    for (NodeMap::iterator node = _nodes.begin(); node != _nodes.end(); node++) {
        if (node -> second == node_to_find) {
            id = node -> second.id;
            break;
        }
    }
    
    return id;
}

void OpenStreetMap::fill_up_information_about_node(Node &node_to_update) {
    string node_id = find_node_id(node_to_update);

    if (! node_id.empty()) {
        node_to_update = _nodes[node_id];
    }
}

NodeMap OpenStreetMap::nodes() {
    return _nodes;
}

void OpenStreetMap::parse_file(const string &source_file) {
    string xml;
    read_file_into_string(source_file, xml);
    XMLNode xml_tree = XML::BuildTree(xml);

    fetch_and_set_map_range(xml_tree);

    cout << "Fetching nodes..." << endl;
    _nodes = fetch_nodes(xml_tree);

    cout << "Fetching edges..." << endl;
    fetch_and_build_nodes_edges(xml_tree);
}

void OpenStreetMap::read_file_into_string(const string &source_file, string &xml) {
    ifstream source;
    string line;
    source.open(source_file.c_str(), ios::in);

    if (source.is_open()) {
        while (getline(source, line)) {
            xml += line;
        }

        source.close();
    }
}

NodeMap OpenStreetMap::fetch_nodes(const XMLNode xml_tree) {
    NodeMap nodes;

    string id;
    Coordinate latitude, longitude;

    XMLNodes xml_nodes = XML::Children(xml_tree, "node");

    for (XMLNodes::iterator node = xml_nodes.begin(); node != xml_nodes.end(); node++) {
        id = XML::Id(*node);
        latitude = Numbers::to_f(XML::Property(*node, "lat"));
        longitude = Numbers::to_f(XML::Property(*node, "lon"));

        Node new_node(id, latitude, longitude);
        nodes.insert(pair<string, Node>(id, new_node));
    }

    return nodes;
}

void OpenStreetMap::fetch_and_build_nodes_edges(const XMLNode xml_tree) {
    vector<string> way_node_ids;
    string way_id, way_name;
    bool is_oneway;

    XMLNodes xml_ways = XML::Children(xml_tree, "way");

    for (XMLNodes::iterator way = xml_ways.begin(); way != xml_ways.end(); way++) {
        way_id = XML::Id(*way);
        way_name = fetch_way_name(*way);
        is_oneway = check_if_way_is_oneway(*way);
        Way new_way(way_id, way_name, is_oneway);

        way_node_ids = fetch_way_node_ids(*way);
        build_nodes_edges_in_way(way_node_ids, new_way);
    }
}

string OpenStreetMap::fetch_way_name(const XMLNode xml_way) {
    string name = "Lack of name...";
    XMLNode tag_with_way_name = XML::ChildWithProperty(xml_way, "tag", "k", "name");

    if (tag_with_way_name) {
        name = XML::Property(tag_with_way_name, "v");
    }

    return name;
}

bool OpenStreetMap::check_if_way_is_oneway(const XMLNode xml_way) {
    XMLNode tag_with_oneway_info = XML::ChildWithProperty(xml_way, "tag", "k", "oneway");

    if (tag_with_oneway_info) {
        return (XML::Property(tag_with_oneway_info, "v") == "yes");
    }

    return false;
}

vector<string> OpenStreetMap::fetch_way_node_ids(const XMLNode xml_way) {
    vector<string> way_node_ids;
    string id;

    XMLNodes xml_way_nodes = XML::Children(xml_way, "nd");

    for (XMLNodes::iterator node = xml_way_nodes.begin(); node != xml_way_nodes.end(); node++) {
        id = XML::Property(*node, "ref");
        way_node_ids.push_back(id);
    }

    return way_node_ids;
}

void OpenStreetMap::build_nodes_edges_in_way(vector<string> way_node_ids, const Way &way) {
    Node *current, *other;

    for (int i = 0; i < way_node_ids.size(); i++) {
        current = &_nodes[way_node_ids[i]];
        
        if (i > 0 && ! way.oneway()) {
            other = &_nodes[way_node_ids[i - 1]];
            Edge<Node> edge(*current, *other, way);
            current -> edges.push_back(edge);
        }
        
        if (i < way_node_ids.size() - 1) {
            other = &_nodes[way_node_ids[i + 1]];
            Edge<Node> edge(*current, *other, way);
            current -> edges.push_back(edge);
        }
    }
}

void OpenStreetMap::fetch_and_set_map_range(const XMLNode xml_tree) {
    XMLNode bounds = XML::Child(xml_tree, "bounds");

    _minimum.latitude = Numbers::to_f(XML::Property(bounds, "minlat"));
    _minimum.longitude = Numbers::to_f(XML::Property(bounds, "minlon"));

    _maximum.latitude = Numbers::to_f(XML::Property(bounds, "maxlat"));
    _maximum.longitude = Numbers::to_f(XML::Property(bounds, "maxlon"));
}