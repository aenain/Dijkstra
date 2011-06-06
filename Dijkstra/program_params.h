#ifndef PROGRAM_PARAMS_H
#define PROGRAM_PARAMS_H
//
//  program_params.h
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//
#include <iostream>
#include <string>
#include "open_street_map.h"
using namespace std;

class ProgramParams {
public:
    static const int VALID_PARAMS_NUMBER_WITH_COORDINATES_AND_OUTPUT = 8;
    static const int VALID_PARAMS_NUMBER_WITH_NODE_IDS_AND_OUTPUT = 6;
    static const int VALID_PARAMS_NUMBER_WITH_COORDINATES = 6;
    static const int VALID_PARAMS_NUMBER_WITH_NODE_IDS = 4;

    bool valid();
    Node begin_node();
    Node end_node();
    string map_source_file();
    bool write_to_file();
    string output_file();
    void print_usage_help();
    void print_wrong_nodes_info();
    // begin_point: { latitude, longitude } || id
    // end_point: { latitude, longitude } || id
    // map_source_file
    // [ -o path_fo_xml_file ]
    ProgramParams(int argc, const char **argv) : _begin_node(0, 0), _end_node(0, 0), _write_to_file(false), _valid(true), _map_source_file(""), _output_file("") { fetch(argc, argv); dispatch(); };

private:
    // name of program, coordinates of begin and end, path to source file with openstreetmap data and optionally path to xml file.
    // or name of program, ids of begin and end node, path to source file with openstreetmap data and optionally path to xml file.
    vector<string> _params;
    Node _begin_node, _end_node;
    string _map_source_file, _output_file;
    bool _valid, _write_to_file;

    void fetch(int argc, const char **argv);
    void dispatch();
    bool validate_params_number_before_create();
    bool validate_params_number_after_create();

    void set_output();
    void set_begin_and_end_nodes();
    void set_begin_and_end_node_coordinates();
    void set_begin_and_end_node_ids();
    void set_map_source_file();

    void remove_used_params(const int begin, const int end);
};

#endif