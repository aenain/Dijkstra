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
    ProgramParams params(argc, argv);

    if (params.valid()) {
        OpenStreetMap open_street_map;
        open_street_map.parse_file(params.open_street_map_source_file());

        if (open_street_map.include(params.start_point()) && open_street_map.include(params.finish_point())) {
            ShortestPathFinder shortest_path_finder(open_street_map.nodes(), open_street_map.edges());

            shortest_path_finder.between(params.start_point(), params.finish_point());
            // TODO! w jakiś sposób trzeba wypisać tą ścieżkę
        }
        else {} // TODO!
    }
    else {} // TODO!
    return 0;
}

