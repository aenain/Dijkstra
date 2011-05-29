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
    static const int VALID_PARAMS_NUMBER = 6;

    bool valid();
    Node start_point();
    Node finish_point();
    string open_street_map_source_file();
    // start_point: { longitude, latitude }
    // finish_point: { longitude, latitude }
    // openstreetmap_source_file
    ProgramParams(int argc, const char * argv[]) : _start_point(0, 0), _finish_point(0, 0), _open_street_map_source_file() { validate_after_create(argc, argv); };

private:
    // name of program, coordinates of start and finish, path to source file with openstreetmap data.
    Node _start_point, _finish_point;
    string _open_street_map_source_file;
    bool _valid;

    void validate_after_create(int argc, const char * argv[]);
};

#endif