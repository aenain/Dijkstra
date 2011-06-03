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
    static const int VALID_PARAMS_NUMBER_WITH_COORDINATES = 6;
    static const int VALID_PARAMS_NUMBER_WITH_NODE_IDS = 4;

    bool valid();
    Node begin_node();
    Node end_node();
    string open_street_map_source_file();
    // begin_point: { latitude, longitude } || id
    // end_point: { latitude, longitude } || id
    // openstreetmap_source_file
    ProgramParams(int argc, const char * argv[]) : _begin_node(0, 0), _end_node(0, 0), _valid(false), _open_street_map_source_file("") { validate_after_create(argc, argv); };

private:
    // name of program, coordinates of begin and end, path to source file with openstreetmap data.
    // or name of program, ids of begin and end node, path to source file with openstreetmap data.
    Node _begin_node, _end_node;
    string _open_street_map_source_file;
    bool _valid;

    void validate_after_create(int argc, const char * argv[]);
};

#endif