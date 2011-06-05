//
//  path.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 31/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <fstream>
#include "path.h"
using namespace std;

Path::Path(NodeMap &nodes, Node &end) {
    copy_node_map(nodes);
    build_node_list_from_nodes(nodes, end);
    build_edges();
}

void Path::copy_node_map(NodeMap &nodes) {
    _nodes_by_id = nodes;
}

void Path::build_node_list_from_nodes(NodeMap &nodes, Node &end) {
    Node &current = end;
    
    while (true) {
        _nodes.insert(_nodes.begin(), current);
        if (current.predecessor_id.empty()) break;
        
        current = nodes[current.predecessor_id];
    }
}

void Path::build_edges() {
    Nodes::iterator previous = _nodes.begin();
    
    for (Nodes::iterator current = _nodes.begin() + 1; current != _nodes.end(); current++, previous++) {
        Edge<Node> edge = previous -> find_edge_by_end_id(current -> id);
        
        if (edge.valid()) {
            _edges.push_back(edge);
        }
    }
}

void Path::print() {
    Distance total_distance = 0;

    if (! _edges.empty()) {
        Way current_way(_edges.at(0).way);
        Distance distance_on_current_way = 0;

        for (Edges::iterator edge = _edges.begin(); edge != _edges.end(); edge++) {
            if (edge -> way == current_way) {
                distance_on_current_way += edge -> length();
            }
            else {
                print_way_with_distance(current_way, distance_on_current_way);
                total_distance += distance_on_current_way;
                distance_on_current_way = edge -> length();
                current_way = edge -> way;
            }
        }

        total_distance += distance_on_current_way;
        print_way_with_distance(current_way, distance_on_current_way);
    }
    else {
        cout << "There is no edges between given nodes." << endl;
    }

    cout << "Total distance: " << distance_for_human(total_distance) << endl;
}

void Path::print_way_with_distance(const Way &way, const Distance &distance) {
    cout << distance_for_human(distance) << " " << way.name() << endl;
}

string Path::distance_for_human(Distance distance) {
    string unit = "m";
    
    if (distance >= 1000.0) {
        distance /= 1000.0; // in kilometers
        unit = "km";
        return Numbers::to_s(distance) + unit;
    }
    
    return Numbers::to_s(distance, 0) + unit;
}

void Path::write_to_file(const string &filepath) {
    ofstream file;
    file.open(filepath.c_str());

    if (file.is_open()) {
        file << to_xml();
        file.close();
    }
}

string & Path::xml_ways() {
    string *xml_ways = new string;
    string xml_nodes;

    if (! _edges.empty()) {
        Edge<Node> first_edge = _edges.at(0);

        Way current_way(first_edge.way);
        Distance distance_on_current_way = 0;

        Node node = find_node(first_edge.begin_id);
        xml_nodes = node.to_xml();

        for (Edges::iterator edge = _edges.begin(); edge != _edges.end(); edge++) {
            node = find_node(edge -> begin_id);

            if (edge -> way == current_way) {
                xml_nodes += node.to_xml();
                distance_on_current_way += edge -> length();
            }
            else {
                *xml_ways += current_way.to_xml(distance_on_current_way, xml_nodes);

                xml_nodes.clear();
                xml_nodes = node.to_xml();

                node = find_node(edge -> end_id);
                xml_nodes += node.to_xml();

                distance_on_current_way = edge -> length();
                current_way = edge -> way;
            }
        }
        
        *xml_ways += current_way.to_xml(distance_on_current_way, xml_nodes);
    }

    return *xml_ways;
}

Node Path::find_node(const string &id) {
    return _nodes_by_id[id];
}

string & Path::to_xml() {
    string *xml = new string("<path>\n" + xml_ways() + "</path>\n");
    return *xml;
}

Nodes Path::nodes() {
    return _nodes;
}

Edges Path::edges() {
    return _edges;
}
