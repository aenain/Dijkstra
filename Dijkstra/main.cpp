//
//  main.cpp
//  Dijkstra
//
//  Created by Artur Hebda on 28/05/2011.
//  Copyright 2011 AdTaily. All rights reserved.
//

#include <iostream>
#include "program_params.h"
#include "open_street_map.h"
#include "shortest_path_finder.h"
using namespace std;

//  ./Dijkstra.debug 50.0661049 19.8271709 50.0696368 19.8287717 ~/Downloads/olszanica.osm [-o ~/Desktop/path.xml]
// ./Dijkstra.debug 1088843921 390856288 ~/Downloads/olszanica.osm [-o ~/Desktop/path.xml]

int main (int argc, const char *argv[]) {
    ProgramParams params(argc, argv); // latitude, longitude or only node_id

    if (params.valid()) {
        OpenStreetMap open_street_map;
        open_street_map.parse_file(params.map_source_file());

        if (open_street_map.include(params.begin_node()) && open_street_map.include(params.end_node())) {
            Node begin = params.begin_node();
            Node end = params.end_node();

            open_street_map.fill_up_information_about_node(begin);
            open_street_map.fill_up_information_about_node(end);

            ShortestPathFinder shortest_path_finder(open_street_map.nodes());

            if (params.write_to_file()) {
                shortest_path_finder.between(begin, end).write_to_file(params.output_file());
            }
            else {
                shortest_path_finder.between(begin, end).print();
            }
        }
        else {
            params.print_wrong_nodes_info();
        }
    }
    else {
        params.print_usage_help();
    }
    return 0;
}
