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
    return true; // TODO!
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
    fetch_edges_for_nodes(xml_tree);
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

void OpenStreetMap::fetch_edges_for_nodes(simplexml * const xml_tree) {
    Edges edges;
    Node current, other;
    vector<string> connected_nodes_ids;

    int ways_counter = 0;
    int nodes_counter = 0;

    string id;

    while (simplexml * way_in_xml = xml_tree -> child(ways_counter)) {
        ways_counter++;
        if (strcmp(way_in_xml -> key(), "way")) continue; // fixes bug in library

        nodes_counter = 0;
        connected_nodes_ids.clear();

        while (simplexml * node_in_xml = way_in_xml -> child(nodes_counter)) {
            nodes_counter++;
            if (strcmp(node_in_xml -> key(), "nd")) continue; // fixes bug in library

            id = node_in_xml -> property("ref");
            connected_nodes_ids.push_back(id);
        }

        for (int i = 0; i < connected_nodes_ids.size(); i++) {
            current = _nodes[connected_nodes_ids[i]];

            if (i > 0) {
                other = _nodes[connected_nodes_ids[i - 1]];
                Edge<Node> edge(current, other);
                current.edges.push(edge);
            }

            if (i < connected_nodes_ids.size() - 1) {
                other = _nodes[connected_nodes_ids[i + 1]];
                Edge<Node> edge(current, other);
                current.edges.push(edge);
            }
        }
    }
}