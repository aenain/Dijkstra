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

int main (int argc, const char * argv[]) {
    ProgramParams params(argc, argv); // najpierw latitude (szerokość), potem longitude (długość)

    if (params.valid()) {
        OpenStreetMap open_street_map;
        open_street_map.parse_file(params.open_street_map_source_file());

        if (open_street_map.include(params.begin_node()) && open_street_map.include(params.end_node())) {
            ShortestPathFinder shortest_path_finder(open_street_map.nodes());

            Path path = shortest_path_finder.between(params.begin_node(), params.end_node());
            path.print();
        }
        else {} // TODO!
    }
    else {} // TODO!
    return 0;
}
