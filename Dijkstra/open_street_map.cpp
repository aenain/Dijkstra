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

Edges OpenStreetMap::edges() {
    return _edges;
}

/*
void OpenStreetMap::parse_file(const string & source_file) {
    TiXmlDocument document(source_file);
    document.LoadFile();
    TiXmlHandle docHandle(&document);

    _nodes = fetch_nodes(docHandle);
    _edges = fetch_edges(docHandle);
}

Nodes OpenStreetMap::fetch_nodes(const TiXmlHandle docHandle) {
    Nodes nodes;
    int nodes_counter = 0;
    TiXmlHandle osmHandle = docHandle.FirstChild("osm");

    while (TiXmlElement * node = osmHandle.Child("node", nodes_counter).ToElement()) {
        // zwracają const char *
        // node.Attribute("id");
        // node.Attribute("lon");
        // node.Attribute("lat");
        nodes_counter++;
    }

    return nodes;
}

Edges OpenStreetMap::fetch_edges(const TiXmlHandle docHandle) {
    Edges edges;
    int ways_counter = 0;
    int nodes_counter = 0;
    TiXmlHandle osmHandle = docHandle.FirstChild("osm");

    while (true) {
        TiXmlHandle wayHandle = osmHandle.Child("way", ways_counter);

        if (! wayHandle.ToElement())
            break;

        nodes_counter = 0;

        while (TiXmlElement * node = wayHandle.Child("nd", nodes_counter).ToElement()) {
            // zwracają const char *
            // node.Attribute("ref");
            nodes_counter++;
        }
        ways_counter++;
    }

    return edges;
}
*/

void OpenStreetMap::parse_file(const string & source_file) {
    string xml;
    read_file_into_string(source_file, xml);
    simplexml * xml_tree = new simplexml(xml.c_str());

    cout << "Fetching nodes..." << endl;
    _nodes = fetch_nodes(xml_tree);
    cout << "Fetching edges..." << endl;
    _edges = fetch_edges(xml_tree);
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

    while (simplexml * node_in_xml = xml_tree -> child(nodes_counter)) {
        nodes_counter++;
        if (strcmp(node_in_xml -> key(), "node")) continue; // fixes bug in library
        // node_in_xml -> property("id")
        // node_in_xml -> property("lon")
        // node_in_xml -> property("lat")
        //Node node(
        //nodes.push_back
    }

    return nodes;
}

Edges OpenStreetMap::fetch_edges(simplexml * const xml_tree) {
    Edges edges;

    int ways_counter = 0;
    int nodes_counter = 0;

    while (simplexml * way_in_xml = xml_tree -> child(ways_counter)) {
        ways_counter++;
        if (strcmp(way_in_xml -> key(), "way")) continue; // fixes bug in library
        // way_in_xml -> property("id")
        nodes_counter = 0;

        while (simplexml * node_in_xml = way_in_xml -> child(nodes_counter)) {
            nodes_counter++;
            if (strcmp(node_in_xml -> key(), "nd")) continue; // fixes bug in library
            // node_in_xml -> property("ref") // id of node
            // TODO! wyszukiwanie node'ów, żeby dodawać krawędzie
            // Edge edge(
            // edges.push_back
        }
    }

    return edges;
}

void Edge::compute_and_set_weight() {
    // sqrt( pow(finish.latidude - start.latitude, 2) + pow(finish.logitude - start.longitude, 2) )
    // TODO! jak to obliczać? jakiego typu ustawić te współrzędne? jak je porównywać?
}