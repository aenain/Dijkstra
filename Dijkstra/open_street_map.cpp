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

bool OpenStreetMap::include(const Node & node) {
    return true; // TODO! ważne, sprawdzenie, czy węzły podane jako argumenty wywołania programu znajdują się w pliku z danymi
}

Nodes OpenStreetMap::nodes() {
    return _nodes;
}

void OpenStreetMap::parse_file(const string & source_file) {
    string xml;
    read_file_into_string(source_file, xml);
    simplexml * xml_tree = new simplexml(xml.c_str());

    cout << "Fetching nodes..." << endl;
    _nodes = fetch_nodes(xml_tree);

    cout << "Fetching edges..." << endl;
    fetch_and_build_nodes_edges(xml_tree);
}

void OpenStreetMap::read_file_into_string(const string & source_file, string & xml) {
    ifstream source;
    string line;
    source.open(source_file.c_str(), ios::in);
    while (getline(source, line)) {
        xml += line;
    }
}

Nodes OpenStreetMap::fetch_nodes(simplexml * const xml_tree) {
    Nodes nodes;
    int nodes_counter = 0;

    string id;
    Distance latitude, longitude;

    while (simplexml * node_in_xml = xml_tree -> child(nodes_counter)) {
        nodes_counter++;
        if (strcmp(node_in_xml -> key(), "node")) continue; // fixes bug in library

        id = node_in_xml->property("id");
        latitude = Numbers::to_f(node_in_xml->property("lat"));
        longitude = Numbers::to_f(node_in_xml->property("lon"));

        Node node(id, latitude, longitude);
        nodes.insert(pair<string, Node>(id, node));
    }

    return nodes;
}

void OpenStreetMap::fetch_and_build_nodes_edges(simplexml * const xml_tree) {
    vector<string> way_node_ids;

    int ways_counter = 0;
    string way_id, way_name;

    while (simplexml * way_in_xml = xml_tree -> child(ways_counter)) {
        ways_counter++;
        if (strcmp(way_in_xml -> key(), "way")) continue; // fixes bug in library
        way_id = fetch_element_id(way_in_xml);
        way_name = fetch_way_name(way_in_xml);
        Way way(way_id, way_name);

        way_node_ids = fetch_way_node_ids(way_in_xml);
        build_nodes_edges_in_way(way_node_ids, way);
    }
}

string OpenStreetMap::fetch_element_id(simplexml * const element_in_xml, const string & id_property_name) { // id_property_name is set by default to "id"
    string id = element_in_xml -> property(id_property_name.c_str());
    return id;
}

string OpenStreetMap::fetch_way_name(simplexml * const way_in_xml) {
    int tags_counter = 0;
    string name = "Lack of name...";

    while (simplexml * tag_in_xml = way_in_xml -> child(tags_counter)) {
        tags_counter++;
        if (strcmp(tag_in_xml -> key(), "tag")) continue; // fixes bug in library
        if (strcmp(tag_in_xml -> property("k"), "name")) continue; // I want to fetch only this tag which contains information about name of the street

        name = tag_in_xml -> property("v");
    }

    return name;
}

vector<string> OpenStreetMap::fetch_way_node_ids(simplexml * const way_in_xml) {
    vector<string> way_node_ids;
    int nodes_counter = 0;
    string id;

    while (simplexml * node_in_xml = way_in_xml -> child(nodes_counter)) {
        nodes_counter++;
        if (strcmp(node_in_xml -> key(), "nd")) continue; // fixes bug in library
        
        id = node_in_xml -> property("ref");
        way_node_ids.push_back(id);
    }

    return way_node_ids;
}

void OpenStreetMap::build_nodes_edges_in_way(vector<string> way_node_ids, const Way & way) {
    Node current, other;

    for (int i = 0; i < way_node_ids.size(); i++) {
        current = _nodes[way_node_ids[i]];
        
        if (i > 0) {
            other = _nodes[way_node_ids[i - 1]];
            Edge<Node> edge(current, other, way);
            current.edges.push(edge);
        }
        
        if (i < way_node_ids.size() - 1) {
            other = _nodes[way_node_ids[i + 1]];
            Edge<Node> edge(current, other, way);
            current.edges.push(edge);
        }
    }
}