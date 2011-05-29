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

Node ProgramParams::start_point() {
    return _start_point;
}

Node ProgramParams::finish_point() {
    return _finish_point;
}

string ProgramParams::open_street_map_source_file() {
    string a;
    return a;
}

void ProgramParams::validate_after_create(int argc, const char * argv[]) {
    if (argc == ProgramParams::VALID_PARAMS_NUMBER) {
        Node _new_start_point(argv[1], argv[2]);
        Node _new_finish_point(argv[3], argv[4]);

        _start_point = _new_start_point;
        _finish_point = _new_finish_point;
        _open_street_map_source_file = argv[5];
        _valid = true;
    }
    else {
        _valid = false;
    }
}