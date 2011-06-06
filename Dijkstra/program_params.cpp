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

bool ProgramParams::write_to_file() {
    return _write_to_file;
}

string ProgramParams::output_file() {
    return _output_file;
}

string ProgramParams::map_source_file() {
    return _map_source_file;
}

void ProgramParams::fetch(int argc, const char **argv) {
    for (int i = 0; i < argc; i++) {
        string param = argv[i];
        _params.push_back(param);
    }
}

void ProgramParams::dispatch() {
    validate_params_number_before_create();

    set_output();
    set_begin_and_end_nodes();
    set_map_source_file();

    validate_params_number_after_create();
}

bool ProgramParams::validate_params_number_before_create() {
    size_t number = _params.size();

    bool valid_with_coords_and_output = (number == VALID_PARAMS_NUMBER_WITH_COORDINATES_AND_OUTPUT);
    bool valid_with_ids_and_output = (number == VALID_PARAMS_NUMBER_WITH_NODE_IDS_AND_OUTPUT);
    bool valid_with_coords = (number == VALID_PARAMS_NUMBER_WITH_COORDINATES);
    bool valid_with_ids = (number == VALID_PARAMS_NUMBER_WITH_NODE_IDS);

    _valid = valid_with_coords_and_output || valid_with_ids_and_output || valid_with_coords || valid_with_ids;

    return _valid;
}

bool ProgramParams::validate_params_number_after_create() {
    if (_valid)
        _valid = (_params.size() == 1); // name of program should remain

    return _valid;
}

void ProgramParams::set_output() {
    vector<string>::iterator last_param = _params.end() - 1;
    vector<string>::iterator before_last_param = _params.end() - 2;

    if (*before_last_param == "-o") {
        _write_to_file = true;
        _output_file = *last_param;

        remove_used_params(-2, -1);
    }
}

void ProgramParams::set_begin_and_end_nodes() {
    if (_params.size() == VALID_PARAMS_NUMBER_WITH_COORDINATES) {
        set_begin_and_end_node_coordinates();
    }
    else if (_params.size() == VALID_PARAMS_NUMBER_WITH_NODE_IDS) {
        set_begin_and_end_node_ids();
    }
}

void ProgramParams::set_begin_and_end_node_coordinates() {
    Coordinate begin_latitude = Numbers::to_f(_params.at(1));
    Coordinate begin_longitude = Numbers::to_f(_params.at(2));
    
    Coordinate end_latitude = Numbers::to_f(_params.at(3));
    Coordinate end_longitude = Numbers::to_f(_params.at(4));

    Location begin_location(begin_latitude, begin_longitude);
    Location end_location(end_latitude, end_longitude);
    
    _begin_node.location = begin_location;
    _end_node.location = end_location;
    
    remove_used_params(1, 4);
}

void ProgramParams::set_begin_and_end_node_ids() {
    _begin_node.id = _params.at(1);
    _end_node.id = _params.at(2);
    
    remove_used_params(1, 2);
}

void ProgramParams::set_map_source_file() {
    if (_params.size() == 2) {
        _map_source_file = _params.at(1);
        remove_used_params(1, 1);
    }
}

void ProgramParams::remove_used_params(const int begin, const int end) {
    vector<string>::iterator first = (begin >= 0) ? _params.begin() + begin : _params.end() + begin;
    vector<string>::iterator last = (end > 0) ? _params.begin() + end : _params.end() + end;

    _params.erase(first, last + 1); // in std::vector stays that it removes [first, last)
}

void ProgramParams::print_wrong_nodes_info() {
    cout << "At least one of given nodes doesn't exist in OSM file." << endl;
}

void ProgramParams::print_usage_help() {
    cout << "Examples of usage:\n"
    << "./Dijkstra.debug 50.0661049 19.8271709 50.0696368 19.8287717 ~/Downloads/olszanica.osm\n"
    << "./Dijkstra.debug 1088843921 390856288 ~/Downloads/olszanica.osm" << endl;
}