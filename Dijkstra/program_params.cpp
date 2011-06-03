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
    if (argc == ProgramParams::VALID_PARAMS_NUMBER_WITH_COORDINATES) {
        Location begin_location(Numbers::to_f(argv[1]), Numbers::to_f(argv[2]));
        Location end_location(Numbers::to_f(argv[3]), Numbers::to_f(argv[4]));

        _begin_node.location = begin_location;
        _end_node.location = end_location;

        _open_street_map_source_file = argv[5];
        _valid = true;
    }
    else if (argc == ProgramParams::VALID_PARAMS_NUMBER_WITH_NODE_IDS) {
        _begin_node.id = argv[1];
        _end_node.id = argv[2];

        _open_street_map_source_file = argv[3];
        _valid = true;
    }
    else {
        _valid = false;
    }
}

void ProgramParams::wrong_nodes() {
    cout << "At least one of given nodes doesn't exist in OSM file." << endl;
}

void ProgramParams::wrong_arguments() {
    cout << "Examples of usage:\n"
    << "~/Desktop/Dijkstra.debug 50.0661049 19.8271709 50.0696368 19.8287717 ~/Downloads/olszanica.osm\n"
    << "~/Desktop/Dijkstra.debug 1088843921 390856288 ~/Downloads/olszanica.osm" << endl;
}