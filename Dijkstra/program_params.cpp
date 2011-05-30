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

Node ProgramParams::begin_node() {
    return _begin_node;
}

Node ProgramParams::end_node() {
    return _end_node;
}

string ProgramParams::open_street_map_source_file() {
    return _open_street_map_source_file;
}

void ProgramParams::validate_after_create(int argc, const char * argv[]) {
    if (argc == ProgramParams::VALID_PARAMS_NUMBER) {
        Node _new_begin_node(Numbers::to_f(argv[1]), Numbers::to_f(argv[2]));
        Node _new_end_node(Numbers::to_f(argv[3]), Numbers::to_f(argv[4]));

        _begin_node = _new_begin_node;
        _end_node = _new_end_node;
        _open_street_map_source_file = argv[5];
        _valid = true;
    }
    else {
        _valid = false;
    }
}