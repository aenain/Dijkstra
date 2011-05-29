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
        cout << "mamy dane!" << endl;
        if (open_street_map.include(params.begin_node()) && open_street_map.include(params.end_node())) {
            ShortestPathFinder shortest_path_finder(open_street_map.nodes());

            shortest_path_finder.between(params.begin_node(), params.end_node());
            // TODO! w jakiś sposób trzeba wypisać tą ścieżkę
        }
        else {} // TODO!
    }
    else {} // TODO!
    return 0;
}
