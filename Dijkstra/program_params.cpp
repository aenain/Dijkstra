//
//  program_params.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 29/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include "program_params.h"
using namespace std;

bool ProgramParams::valid() {
    return _valid;
}

Node ProgramParams::begin_point() {
    return _begin_point;
}

Node ProgramParams::end_point() {
    return _end_point;
}

string ProgramParams::open_street_map_source_file() {
    return _open_street_map_source_file;
}

void ProgramParams::validate_after_create(int argc, const char * argv[]) {
    if (argc == ProgramParams::VALID_PARAMS_NUMBER) {
        Node _new_begin_point(argv[1], argv[2]);
        Node _new_end_point(argv[3], argv[4]);

        _begin_point = _new_begin_point;
        _end_point = _new_end_point;
        _open_street_map_source_file = argv[5];
        _valid = true;
    }
    else {
        _valid = false;
    }
}